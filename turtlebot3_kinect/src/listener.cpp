#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>
#include <math.h>

void sendToTurtlebot(const std_msgs::String::ConstPtr& msg){
ROS_INFO("I heard: [%s]", msg->data.c_str());
ROS_ERROR("running %s", "callback function");

ros::NodeHandle handle;
ros::Publisher pub = handle.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
geometry_msgs::Twist msgss;
msgss.linear.x = 2.0;
msgss.linear.y = 1.0;
msgss.linear.z = 1.0;
msgss.angular.x = 1.0;
msgss.angular.y = 1.0;
msgss.angular.z = 1.0;
pub.publish(msgss);

}

int main(int argc, char **argv){

ros::init(argc, argv, "listener");
ros::NodeHandle nh;

ros::Subscriber subscriber_obj = nh.subscribe("/turtle", 1000, sendToTurtlebot);

//ros::Publisher chatter_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
//geometry_msgs::Twist msg;
//msg.linear.x = 2.0,0.0,0.0;
//msg.angular.z = 0.0,0.0,1.8;
//chatter_pub.publish(msg);



ros::spin();

return 0;


}
