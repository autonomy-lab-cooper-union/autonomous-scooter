#include <math.h>
#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <std_msgs/Int32.h>

class Encoder
  {
  public:
    int tick, last_tick;
    double radius, displacement, last_displacement, delta_displacement;
    double speed;
    ros::Subscriber sub;

    Encoder();
    
    void update(double dt);
  };