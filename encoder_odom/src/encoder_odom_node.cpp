#include "encoder_odom/encoder_odom_node.h"

    EncoderOdomNode::EncoderOdomNode()
    {
        ros::NodeHandle n;
        odom_pub = n.advertise<nav_msgs::Odometry>("odom", 50);

        lwheel.sub = n.subscribe<std_msgs::Int32>("lwheel_tick", 100, &EncoderOdomNode::lwheelCallBack, this);
        rwheel.sub = n.subscribe<std_msgs::Int32>("rwheel_tick", 100, &EncoderOdomNode::lwheelCallBack, this);
        fwheel.sub = n.subscribe<std_msgs::Int32>("fwheel_tick", 100, &EncoderOdomNode::fwheelCallBack, this);

        current_time = ros::Time::now();
        last_time = ros::Time::now();
        ros::Rate r_(10);
        r = &r_;
    }

    void EncoderOdomNode::lwheelCallBack(const IntConstPtr& msg)
    {
        lwheel.tick = msg->data;
    }

    void EncoderOdomNode::rwheelCallBack(const IntConstPtr& msg)
    {
        rwheel.tick = msg->data;
    }

    void EncoderOdomNode::fwheelCallBack(const IntConstPtr& msg)
    {
        fwheel.tick = msg->data;
    }

    void EncoderOdomNode::run()
    {
        while (n.ok())
        {

            ros::spinOnce(); // check for incoming messages
            current_time = ros::Time::now();

            //update the dispalcement and speed based on the new tick
            double dt = (current_time - last_time).toSec();
            lwheel.update(dt);
            rwheel.update(dt);
            fwheel.update(dt);

            //take the average of the two rear encoders
            delta_r = (lwheel.delta_displacement + rwheel.delta_displacement) / 2;
            vr = (lwheel.speed + rwheel.speed) / 2;

            //compute odometry using a simple car kinematic model
            delta_x = delta_r * (cos(fwheel.displacement) / fwheel.radius); // displacement / radius = angle
            delta_y = delta_r * (sin(fwheel.displacement) / fwheel.radius);
            delta_th = delta_r * (tan(fwheel.speed) / fwheel.radius) / car_length;

            vx = vr * (cos(fwheel.displacement) / fwheel.radius); // displacement / radius = angle
            vy = vr * (sin(fwheel.displacement) / fwheel.radius);
            vth = vr * (tan(fwheel.speed) / fwheel.radius) / car_length;

            x += delta_x;
            y += delta_y;
            th += delta_th;

            //since all odometry is 6DOF we'll need a quaternion created from yaw
            geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(th);

            //first, we'll publish the transform over tf
            geometry_msgs::TransformStamped odom_trans;
            odom_trans.header.stamp = current_time;
            odom_trans.header.frame_id = "odom";
            odom_trans.child_frame_id = "base_link";

            odom_trans.transform.translation.x = x;
            odom_trans.transform.translation.y = y;
            odom_trans.transform.translation.z = 0.0;
            odom_trans.transform.rotation = odom_quat;

            //send the transform
            odom_broadcaster.sendTransform(odom_trans);

            //next, we'll publish the odometry message over ROS
            nav_msgs::Odometry odom;
            odom.header.stamp = current_time;
            odom.header.frame_id = "odom";

            //set the position
            odom.pose.pose.position.x = x;
            odom.pose.pose.position.y = y;
            odom.pose.pose.position.z = 0.0;
            odom.pose.pose.orientation = odom_quat;

            //set the velocity
            odom.child_frame_id = "base_link";
            odom.twist.twist.linear.x = vx;
            odom.twist.twist.linear.y = vy;
            odom.twist.twist.angular.z = vth;

            //publish the message
            odom_pub.publish(odom);

            last_time = current_time;
            r->sleep();
        }
    }

int main(int argc, char **argv)
{
    ros::init(argc, argv, "encoder_odom");
    EncoderOdomNode myEncoderOdomNode;
    myEncoderOdomNode.run();

    return 0;
}