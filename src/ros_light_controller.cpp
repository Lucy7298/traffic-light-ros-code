/**
publishes array to display on light
**/
#include <ros/ros.h>
#include <light_controller/light_command.h>
#include <sstream>
#include <iostream>
#include <vector>

int main(int argc, char **argv) {
    ros::init(argc, argv, "light_node_node"); 
    ros::NodeHandle n("~"); 
    ros::Publisher pub = n.advertise<light_controller::light_command>("light_state", 1); 

  while (ros::ok()){
    ros::spinOnce(); 
    // read input from cin 
    std::string inputString; 
    std::getline(std::cin, inputString);
    std::stringstream in(inputString);
    std::vector<int8_t> a;
    std::string temp;
    while(in >> temp) {
      a.push_back(stoi(temp));
    }

    light_controller::light_command msg;
    msg.light1_status = a.at(0); 
    msg.light2_status = a.at(1); 
    pub.publish(msg); 

  }

    return 0; 
}
