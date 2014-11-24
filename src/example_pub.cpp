#include <ros/ros.h>
#include <std_msgs/String.h>

int
main(int argc, char** argv)
{
  ros::init(argc, argv, "test_pub_node");
  ros::NodeHandle nh;

  ros::Publisher pub = nh.advertise<std_msgs::String>("atopic", 10);

  while (ros::ok()) {
    std_msgs::String stringMsg;
    stringMsg.data = "foo";
    pub.publish(stringMsg);

    ros::Duration(1.0).sleep();
  }
}
