#include "ros-tf/listener.hpp"

namespace listener
{
    listener::listener()
    :   private_nh_("~"),
        display_value_sub_(private_nh_.subscribe<std_msgs::Bool>("display_transform", 1, & listener::display_cb, this)),
        tfListener_(tfBuffer_)
    {
        private_nh_.param("rate", rate_, 5);
        private_nh_.param<std::string>("fixed_frame", fixed_frame_, "map");
        private_nh_.param<std::string>("odom_frame", odom_frame_, "odom");
    }


    listener::~listener()
    {
    }


    void listener::display_cb(const std_msgs::Bool::ConstPtr & msg)
    {
        #ifdef DEBUG_
            ROS_INFO_STREAM("Callback!");
        #endif
        // Pass to local variable
        display_ = msg->data;
    }


    void listener::start()
    {
        // Set process rate 
        ros::Rate r(rate_);

        while (private_nh_.ok())
        {
            if(display_)
            {
                try
                {
                    // Obtain odom_frame position in tf
                    read_transformation_ = tfBuffer_.lookupTransform(fixed_frame_, odom_frame_, ros::Time(0), ros::Duration(60.0));
                }
                catch(const tf2::TransformException & e)
                {
                    ROS_WARN_STREAM("listener_node: " << e.what());
                    ROS_WARN_STREAM("listener_node: Failed to read odom_frame tf");
                    continue;
                }

                ROS_INFO_STREAM(
                    "listener_node: position x, y, z (" << read_transformation_.transform.translation.x <<
                    ", " << read_transformation_.transform.translation.y << ", " << read_transformation_.transform.translation.z <<
                    ") x, y, z, w (" << read_transformation_.transform.rotation.x << ", " << read_transformation_.transform.rotation.y <<
                    ", " << read_transformation_.transform.rotation.z << ", " << read_transformation_.transform.rotation.w << ")"
                );

                // Set flag to false
                display_ = false;
            }

            // ROS spin for callbacks
            ros::spinOnce();

            // Sleep
            r.sleep();
        }
    }

} // namespace listener
