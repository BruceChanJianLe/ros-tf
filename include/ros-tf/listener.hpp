#ifndef _listener_H__
#define _listener_H__

#include <ros/ros.h>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/TransformStamped.h>
#include <std_msgs/Bool.h>

#include <string>

namespace listener
{
    class listener
    {
        private:
            ros::NodeHandle private_nh_;
            ros::NodeHandle relative_nh_;
            ros::Subscriber display_value_sub_;

            tf2_ros::Buffer tfBuffer_;
            tf2_ros::TransformListener tfListener_;
            
            geometry_msgs::TransformStamped read_transformation_;

            // Private variables
            std::string fixed_frame_;
            std::string odom_frame_;
            int rate_;
            bool display_;

            // Private functions
            void display_cb(const std_msgs::Bool::ConstPtr &);

        public:
            listener();
            ~listener();

            // Declare method
            void start();
    };
} // namespace listener


#endif