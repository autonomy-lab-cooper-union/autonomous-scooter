#include "encoder_odom/encoder.h"

typedef boost::shared_ptr<std_msgs::Int32 const> IntConstPtr;

class EncoderOdomNode
{
public:
    Encoder lwheel, rwheel, fwheel;

    ros::NodeHandle n;
    ros::Publisher odom_pub;
    tf::TransformBroadcaster odom_broadcaster;

    ros::Time current_time, last_time;
    ros::Rate* r;

    const double car_length = 0.5;
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

    EncoderOdomNode();

    void lwheelCallBack(const IntConstPtr& msg);

    void rwheelCallBack(const IntConstPtr& msg);

    void fwheelCallBack(const IntConstPtr& msg);

    void run();

};