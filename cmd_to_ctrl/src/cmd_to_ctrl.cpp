//
// Created by vr-lab on 7/2/19.
//

#include "cmd_to_ctrl.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "cmd_to_control");

    ros::NodeHandle n;

    double L = 1;

    ros::Publisher pub_steering = n.advertise<std_msgs::Float64>("control_steering", 1000);
    ros::Publisher pub_speed = n.advertise<std_msgs::Float64>("control_speed", 1000);
    ros::Subscriber sub = n.subscribe<geometry_msgs::Twist>("cmd_vel", 1000, boost::bind(twistCallback, _1, pub_steering, pub_speed, L));

    ros::spin();
    return 0;
}

void twistCallback(const geometry_msgs::Twist::ConstPtr& msg, const ros::Publisher &pub_steering, const ros::Publisher &pub_speed, const double& L) {
    float speed = sqrt((msg->linear.x)*(msg->linear.x) + (msg->linear.y)*(msg->linear.y));
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
    return atan(L*speed/msg->angular.z);
}