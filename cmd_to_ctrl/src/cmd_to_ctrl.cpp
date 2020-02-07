//
// Created by Do Hyung Kwon on 7/2/19.
//

// based on simple car model
// http://planning.cs.uiuc.edu/node658.html

#include "cmd_to_ctrl.h"

geometry_msgs::Pose currentPose;
double currentRoll, currentPitch, currentYaw;
std::vector<geometry_msgs::PoseStamped> currentPath;
float speed_actual;
std::ofstream myfile;

int main(int argc, char **argv) {
    ros::init(argc, argv, "cmd_to_control");

    ros::NodeHandle n;

    double L = 1.1;
    n.getParam("length", L);

    myfile.open("output.txt");

    ros::Publisher pub_steering = n.advertise<std_msgs::Float64>("control_steering", 1000);
    ros::Publisher pub_speed = n.advertise<std_msgs::Float64>("control_speed", 1000);
    ros::Subscriber sub = n.subscribe<geometry_msgs::Twist>("cmd_vel", 1000, boost::bind(twistCallback, _1, pub_steering, pub_speed, L));

    ros::Publisher pub_current_yaw = n.advertise<std_msgs::Float64>("current_yaw", 1000);
    ros::Publisher pub_heading_angle = n.advertise<std_msgs::Float64>("heading_angle", 1000);

    ros::Subscriber sub_odom = n.subscribe<nav_msgs::Odometry>("/zed/zed_node/odom", 1000, boost::bind(getCurrentPose, _1, pub_current_yaw));
    ros::Subscriber sub_path = n.subscribe<nav_msgs::Path>("/move_base/TebLocalPlannerROS/local_plan", 1000, boost::bind(getCurrentPath, _1, pub_heading_angle));

    ros::spin();
    myfile.close();
    return 0;
}

void getCurrentPath(const nav_msgs::Path::ConstPtr& msg, const ros::Publisher &pub_heading_angle) {
    currentPath = msg->poses;
    getHeadingAngle(pub_heading_angle);
}

void getHeadingAngle(const ros::Publisher &pub_heading_angle) {
    std_msgs::Float64 heading_angle_msg;
    double r, p, y;
    int closest_idx;
    float curMin = INT_MAX;

    float cur_x = currentPose.position.x;
    float cur_y = currentPose.position.y;

    for (int i = 1; i < currentPath.size(); i++) {
        auto p = currentPath[i];
        float tmp = pow(p.pose.position.x - cur_x, 2.0) + pow(p.pose.position.y - cur_y, 2.0);
        if (curMin > tmp) {
            curMin = tmp;
            closest_idx = i;
        }
    }

    tf::Quaternion q(
        currentPath[closest_idx].pose.orientation.x,
        currentPath[closest_idx].pose.orientation.y,
        currentPath[closest_idx].pose.orientation.z,
        currentPath[closest_idx].pose.orientation.w
    );
    tf::Matrix3x3 m(q);
    m.getRPY(r, p, y);
    //heading_angle_msg.data = y-currentYaw;
    //pub_heading_angle.publish(heading_angle_msg);


    /* Heading Error */
	float theta_h = y - currentYaw;
	
	/* Normalize to [-PI, PI] */
	while(theta_h > PI)
		theta_h -= 2 * PI;
	while(theta_h < -PI)
		theta_h += 2 * PI;

	//float front_axle_vec[2] = {-cos(currentYaw + PI/2), -sin(currentYaw + PI/2)};
	//float error_front_axle = front_axle_vec[0]*currentPath[closest_idx].pose.position.x + front_axle_vec[1]*currentPath[closest_idx].pose.position.y;
    if(closest_idx + 1 == currentPath.size())
        return;

    float curr_x = currentPath[closest_idx].pose.position.x + LEART * cos(currentYaw);
    float curr_y = currentPath[closest_idx].pose.position.y + LEART * cos(currentYaw);

    float A = ( currentPath[closest_idx + 1].pose.position.y - curr_y ) / ( currentPath[closest_idx + 1].pose.position.x - curr_x);
    float B = -1;
    float C = curr_y - A*curr_x;

    float error_front_axle =  ( abs(A*curr_x + B*curr_y + C) ) / ( sqrt(pow(A,2) + pow(B,2)) );

	/* Cross Track Error */
	float theta_e = atan( (K_CONSTANT * error_front_axle) / speed_actual);	

	float delta = theta_h + theta_e;
    heading_angle_msg.data = delta;

    // Printing State Variables to file
    myfile << "Current (x,y,yaw): (" << curr_x << ", " << curr_y << ", " << currentYaw <<")" << std::endl;
    myfile << "Desired (x,y,yaw): (" << currentPath[closest_idx].pose.position.x << ", " << currentPath[closest_idx].pose.position.y << ", " << y <<")" << std::endl;
    myfile << "Crosstrack Error: (" << error_front_axle << ")" << std::endl;
    myfile << "Heading Error: (" << theta_h << ")" << std::endl;
    myfile << "Published Heading Angle: (" << delta << ")\n" << std::endl;
    pub_heading_angle.publish(heading_angle_msg);
	
}



void getCurrentPose(const nav_msgs::Odometry::ConstPtr& msg, const ros::Publisher &pub_current_yaw) {
    // https://gist.github.com/marcoarruda/f931232fe3490b7fa20dbb38da1195ac
    currentPose = msg->pose.pose;
    tf::Quaternion q(
        currentPose.orientation.x,
        currentPose.orientation.y,
        currentPose.orientation.z,
        currentPose.orientation.w
    );
    tf::Matrix3x3 m(q);
    m.getRPY(currentRoll, currentPitch, currentYaw);

    std_msgs::Float64 current_yaw_msg;
    current_yaw_msg.data = currentYaw;
    pub_current_yaw.publish(current_yaw_msg);
}

void twistCallback(const geometry_msgs::Twist::ConstPtr& msg, const ros::Publisher &pub_steering, const ros::Publisher &pub_speed, const double& L) {
    float speed = sqrt((msg->linear.x)*(msg->linear.x) + (msg->linear.y)*(msg->linear.y))*2.5;
    speed_actual = speed;
    if (msg->linear.x < 0) speed = -speed;
    float steering = twist_to_steering(msg, speed, L);

    std_msgs::Float64 steering_msg;
    std_msgs::Float64 speed_msg;
    steering_msg.data = steering;
    speed_msg.data = speed;
    pub_steering.publish(steering_msg);
    pub_speed.publish(speed_msg);
}

float twist_to_steering(const geometry_msgs::Twist::ConstPtr& msg, const float& speed, const double& L) {
    if (msg->angular.z == 0.0 || speed == 0.0) {
        return 0.0f;
    }
    return atan(L*msg->angular.z/std::max(speed, 1.0f));
}