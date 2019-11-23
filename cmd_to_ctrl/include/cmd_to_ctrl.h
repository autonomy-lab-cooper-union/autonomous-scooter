//
// Created by vr-lab on 7/2/19.
//

#ifndef CMD_TO_CTRL_CMD_TO_CTRL_H
#define CMD_TO_CTRL_CMD_TO_CTRL_H

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/PoseStamped.h"
#include "std_msgs/Float64.h"
#include "nav_msgs/Odometry.h"
#include "nav_msgs/Path.h"
#include <cmath>
#include <boost/bind.hpp>
#include <tf/tf.h>
#include <vector>


void getCurrentPose(const nav_msgs::Odometry::ConstPtr& msg, const ros::Publisher &pub_current_speed);
void twistCallback(const geometry_msgs::Twist::ConstPtr& msg, const ros::Publisher &pub_steering, const ros::Publisher &pub_speed, const double& L);
float twist_to_steering(const geometry_msgs::Twist::ConstPtr& msg, const float& speed, const double& L);
void getCurrentPath(const nav_msgs::Path::ConstPtr& msg, const ros::Publisher &pub_heading_angle);
void getHeadingAngle(const ros::Publisher &pub_heading_angle);

#endif //CMD_TO_STEERING_CMD_SUBSCRIBER_H
