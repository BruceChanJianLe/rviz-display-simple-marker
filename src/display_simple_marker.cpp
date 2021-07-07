#include "rviz-display-simple-marker/display_simple_marker.hpp"


namespace rviz
{
    display_simple_marker::display_simple_marker()
    :   relative_nh_(ros::NodeHandle())
    ,   private_nh_(ros::NodeHandle("~"))
    {
         // Load ROS params
        private_nh_.param<double>("x", x_, 0.0);
        private_nh_.param<double>("y", y_, 0.0);
        private_nh_.param<int>("rate", rate_, 1);
        private_nh_.param<int>("shape", marker_shape_, visualization_msgs::Marker::SPHERE);
        private_nh_.param<std::string>("frame_id", frame_id_, "map");
        private_nh_.param<double>("color_r", color_r_, 0.0);
        private_nh_.param<double>("color_g", color_g_, 0.0);
        private_nh_.param<double>("color_b", color_b_, 0.0);
        private_nh_.param<double>("color_a", color_a_, 1.0);

        // Define publisher
        pub_ = relative_nh_.advertise<visualization_msgs::Marker>("simple_marker", 1);

        // Prepare marker
        // marker_msg_.points.clear();
        marker_msg_.header.frame_id = frame_id_;
        marker_msg_.ns = "simple_display";
        marker_msg_.id = 0;
        marker_msg_.action = visualization_msgs::Marker::ADD;
        marker_msg_.pose.position.x = x_;
        marker_msg_.pose.position.y = y_;
        marker_msg_.pose.position.z = 0;
        marker_msg_.pose.orientation.w = 1.0;
        marker_msg_.pose.orientation.x = 0.0;
        marker_msg_.pose.orientation.y = 0.0;
        marker_msg_.pose.orientation.z = 0.0;
        // Color
        marker_msg_.color.a = color_a_;
        marker_msg_.color.r = color_r_;
        marker_msg_.color.g = color_g_;
        marker_msg_.color.b = color_b_;
        // Marker scale
        marker_msg_.scale.x = 1.0;
        marker_msg_.scale.y = 1.0;
        marker_msg_.scale.z = 1.0;
        marker_msg_.type = marker_shape_;
        marker_msg_.lifetime = ros::Duration();

   }

    display_simple_marker::~display_simple_marker()
    {
    }

    void display_simple_marker::start()
    {
        ros::Rate r(1);

        while (ros::ok())
        {
            // Publish marker
            publish_marker();
            r.sleep();
        }
    }

    void display_simple_marker::publish_marker()
    {
        marker_msg_.header.stamp = ros::Time::now();

        pub_.publish(marker_msg_);
    }

} // namespace rviz