/**
publishes array to display on light
**/
#include <ros/ros.h>
#include <std_msgs/Int8.h>
#include <iostream>
#include <vector>
#include <array> 

int main(int argc, char **argv) {
    ros::init(argc, argv, "light_node_node"); 
    ros::NodeHandle n("~"); 
    ros::Publisher pub = n.advertise<std_msgs::Int8>("light_state", 1); 
    // 0 -> empty light 
    // 1 -> green light 
    // 2 -> yellow light 
    // 3 -> red light  

  while (ros::ok()){
    int8_t message = 0;
    ros::spinOnce(); 
    // read input from cin 
    std::string inputString; 
    std::getline(std::cin, inputString);
    message = std::stoi(inputString); 

    std_msgs::Int8 msg;
    msg.data = message; 
    pub.publish(msg); 

  }

    return 0; 
}
