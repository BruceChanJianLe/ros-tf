#include "ros-tf/listener.hpp"


int main(int argc, char ** argv)
{
    // Initialize ROS node
    ros::init(argc, argv, "listener_node");

    // Instantiate listener object
    listener::listener node;

    // Start node
    node.start();

    return 0;
}