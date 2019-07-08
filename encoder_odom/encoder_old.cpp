#include "encoder/encoder.h"

  class Encoder
  {
  public:
    int tick, last_tick;
    double radius, displacement, last_displacement, delta_displacement;
    double speed;
    ros::Subscriber sub;

    Encoder()
    {
      //TODO: read the radius as param
      radius = 0.05;
    }

    void update(double dt)
    {
      displacement = tick * radius;
      delta_displacement = displacement - last_displacement;
      speed = delta_displacement / dt;
      last_tick = tick;
      last_displacement = displacement;
    }
  };

  int main(int argc, char **argv)
  {
    ros::init(argc, argv, "encoder_odom");

    ros::NodeHandle n;
    ros::Publisher odom_pub = n.advertise<nav_msgs::Odometry>("odom", 50);
    tf::TransformBroadcaster odom_broadcaster;

    Encoder lwheel, rwheel, fwheel;
    // lwheel.init("lwheel_tick", n);
    // rwheel.init("rwheel_tick", n);
    // fwheel.init("fwheel_tick", n);
    lwheel.sub = n.subscribe<std_msgs::Int32>("lwheel_tick", 100, lwheel::encoderCallBack);
    rwheel.sub = n.subscribe<std_msgs::Int32>("rwheel_tick", 100, rwheel::encoderCallBack);
    fwheel.sub = n.subscribe<std_msgs::Int32>("fwheel_tick", 100, fwheel::encoderCallBack);

    //TODO: implenent this as param
    double car_length = 0.5;

    double x = 0;
    double y = 0;
    double th = 0;
    double delta_x = 0;
    double delta_y = 0;
    double delta_th = 0;
    double delta_r = 0;
    double vx = 0;
    double vy = 0;
    double vth = 0;
    double vr = 0;

    ros::Time current_time, last_time;
    current_time = ros::Time::now();
    last_time = ros::Time::now();

    ros::Rate r(10);
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
      vr = (lwheel.speed + rwheel.speed) / 2

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
      r.sleep();
    }
  }
}