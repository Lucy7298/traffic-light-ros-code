/**
publishes array to display on light
**/
#include <ros/ros.h>
#include <std_msgs/UInt16.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <math.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "light_node_node"); 
    ros::NodeHandle n("~"); 
    ros::Publisher pub = n.advertise<std_msgs::UInt16>("light_state", 1); 

  while (ros::ok()){
    ros::spinOnce(); 
    // read input from cin 
    std::string inputString; 
    std::getline(std::cin, inputString);
    std_msgs::UInt16 msg;
    int running_total = 0; 
    for (int i = 0; i < 4; i++) {
      int status_i = atoi(&inputString.at(i*2)); 
      running_total += (int) status_i * pow(4, i); 
    }
    msg.data = running_total; 
    pub.publish(msg); 

  }

    return 0; 
}
