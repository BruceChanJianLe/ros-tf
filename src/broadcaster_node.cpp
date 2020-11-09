#include "ros-tf/broadcaster.hpp"


int main(int argc, char ** argv)
{
    // Initialize ROS node
    ros::init(argc, argv, "broadcaster_node");

    // Instantiate broadcaster class
    broadcaster::broadcaster node;

    // Run node
    node.start();

    return 0;
}