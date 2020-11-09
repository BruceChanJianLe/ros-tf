#include "ros-tf/broadcaster.hpp"

namespace broadcaster
{
    broadcaster::broadcaster()
    :   private_nh_("~"),
        publish_(false),
        broadcaster_flag_sub_(private_nh_.subscribe<std_msgs::Bool>("reset", 1, & broadcaster::flag_cb, this))
    {
        private_nh_.param<std::string>("fixed_frame", fixed_frame_, "map");
        private_nh_.param<std::string>("odom_frame", odom_frame_, "odom");
        private_nh_.param("rate", rate_, 5);
    }


    broadcaster::~broadcaster()
    {
    }


    void broadcaster::flag_cb(const std_msgs::Bool::ConstPtr & msg)
    {
        #ifdef DEBUG_
            // debug
            ROS_INFO_STREAM("callback!");
        #endif
        // Pass to local variable
        publish_ = msg->data;
    }


    void broadcaster::start()
    {
        // Set process rate
        ros::Rate r(rate_);

        // Define msg
        coordinate_msg_.header.frame_id = fixed_frame_;
        coordinate_msg_.child_frame_id = odom_frame_;

        coordinate_msg_.transform.translation.x = 1.0;
        coordinate_msg_.transform.translation.y = 1.0;
        coordinate_msg_.transform.translation.z = 0.0;

        coordinate_msg_.transform.rotation.w = 1.0;
        coordinate_msg_.transform.rotation.x = 0.0;
        coordinate_msg_.transform.rotation.y = 0.0;
        coordinate_msg_.transform.rotation.z = 0.0;

        while(private_nh_.ok())
        {
            if(publish_)
            {
                #ifdef DEBUG_
                    // process
                    ROS_INFO_STREAM("Processing!");
                #endif
                // Set msg time
                coordinate_msg_.header.stamp = ros::Time::now();
                // Broadcast transformation
                tfBroadcaster_.sendTransform(coordinate_msg_);
                // Set flag to flase
                publish_ = false;
            }

            // ROS spin for callbacks
            ros::spinOnce();

            // Sleep
            r.sleep();
        }
    }
} // namespace broadcaster
