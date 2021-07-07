#ifndef __DSM_H_
#define __DSM_H_

#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/Point.h>

#include <string>

namespace rviz
{
    class display_simple_marker
    {
    private:
        // ROS declaration
        ros::NodeHandle relative_nh_;
        ros::NodeHandle private_nh_;
        ros::Publisher pub_;

        // Variable declaration
        int rate_;
        double x_;
        double y_;
        double color_r_;
        double color_g_;
        double color_b_;
        double color_a_;
        visualization_msgs::Marker marker_msg_;
        int marker_shape_ = visualization_msgs::Marker::SPHERE;
        std::string frame_id_;

        // Private function
        void publish_marker();
    public:
        display_simple_marker();
        ~display_simple_marker();

        void start();
    };
} // namespace rviz
#endif