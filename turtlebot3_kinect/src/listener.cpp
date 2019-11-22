#include <ros/ros.h>
#include <std_msgs/String.h>

void sendToTurtlebot(const std_msgs::String::ConstPtr& msg){
ROS_INFO("I heard: [%s]", msg->data.c_str());
  
}

int main(int argc, char **argv){

ros::init(argc, argv, "listener");
ros::NodeHandle nh;

ros::Subscriber subscriber_obj = nh.subscribe("/turtle", 1000, sendToTurtlebot);

ros::spin();

return 0;


}
