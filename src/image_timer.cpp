#include "ros/ros.h"
#include "sensor_msgs/Image.h"

std::string topic_;
void imgCallback(const sensor_msgs::Image::ConstPtr& msg)
{
  ROS_INFO("I heard image on %s",topic_.c_str());
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  
  n.param<std::string>("topic", topic_, "/cam0/image_raw");

  ros::Subscriber sub = n.subscribe(topic_, 1000, imgCallback);

  ros::spin();

  return 0;
}