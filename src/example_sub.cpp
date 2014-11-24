#include <ros/ros.h>
#include <std_msgs/String.h>


void atopicCallback(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO_STREAM("got msg:" << *msg);
}


int
main(int argc, char** argv)
{
  ros::init(argc, argv, "test_sub_node");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe<std_msgs::String>("atopic", 10, atopicCallback);

  ros::spin();
}
