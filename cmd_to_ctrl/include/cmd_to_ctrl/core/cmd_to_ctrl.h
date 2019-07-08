//
// Created by vr-lab on 7/2/19.
//

#ifndef CMD_TO_CTRL_CMD_TO_CTRL_H
#define CMD_TO_CTRL_CMD_TO_CTRL_H

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "cmd_to_ctrl/Ctrl.h"
#include <cmath>
#include <boost/bind.hpp>

void twistCallback(const geometry_msgs::Twist::ConstPtr& msg, const ros::Publisher &pub, const double& L);
float twist_to_steering(const geometry_msgs::Twist::ConstPtr& msg, const float& speed, const double& L);

#endif //CMD_TO_STEERING_CMD_SUBSCRIBER_H
