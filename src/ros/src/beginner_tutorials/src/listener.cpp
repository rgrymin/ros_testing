#include "ros/ros.h"
#include "std_msgs/String.h"

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}


class Listener
{
  public:
  Listener(int argc, char* argv[])
  {
    ros::init(argc, argv, "listener");

    ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

    ros::spin();
  }



  private: 
  ros::NodeHandle n;
};

int main(int argc, char **argv)
{
  Listener l(argc, argv);
  return 0;
}
