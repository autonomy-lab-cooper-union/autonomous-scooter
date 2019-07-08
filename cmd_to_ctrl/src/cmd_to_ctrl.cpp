//
// Created by vr-lab on 7/2/19.
//

#include "cmd_to_ctrl/core/cmd_to_ctrl.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "cmd_to_control");

    ros::NodeHandle n;

    double L = 1;

    ros::Publisher pub = n.advertise<cmd_to_ctrl::Ctrl>("control_pub", 1000);
    ros::Subscriber sub = n.subscribe<geometry_msgs::Twist>("cmd_vel", 1000, boost::bind(twistCallback, _1, pub, L));

    ros::spin();
    return 0;
}

void twistCallback(const geometry_msgs::Twist::ConstPtr& msg, const ros::Publisher &pub, const double& L) {
    float speed = sqrt((msg->linear.x)*(msg->linear.x) + (msg->linear.y)*(msg->linear.y));
    float steering = twist_to_steering(msg, speed, L);

    cmd_to_ctrl::Ctrl ctrl_msg;
    ctrl_msg.steering = steering;
    ctrl_msg.speed = speed;
    pub.publish(ctrl_msg);
}

float twist_to_steering(const geometry_msgs::Twist::ConstPtr& msg, const float& speed, const double& L) {
    if (msg->angular.z == 0.0 || speed == 0.0) {
        return 0.0f;
    }
    return atan(L*speed/msg->angular.z);
}