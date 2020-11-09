#ifndef _broadcaster_H__
#define _broadcaster_H__

#include <ros/ros.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>
#include <std_msgs/Bool.h>

#include <string>

namespace broadcaster
{
    class broadcaster
    {
        private:
            // ROS Declaration
            ros::NodeHandle private_nh_;
            ros::NodeHandle relative_nh_;
            ros::Subscriber broadcaster_flag_sub_;

            tf2_ros::TransformBroadcaster tfBroadcaster_;

            geometry_msgs::TransformStamped coordinate_msg_;

            // Private variables
            std::string fixed_frame_;
            std::string odom_frame_;
            bool publish_;
            int rate_;

            // Private functions
            void flag_cb(const std_msgs::Bool::ConstPtr &);

            public:
                broadcaster();
                ~broadcaster();

                // Declare method
                void start();
    };
} // namespace broadcaster

#endif