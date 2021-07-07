#include "rviz-display-simple-marker/display_simple_marker.hpp"

const std::string ROSNodeName {"display_simple_marker_node"};

int main(int argc, char ** argv)
{
    ros::init(argc, argv, ROSNodeName);

    rviz::display_simple_marker node;

    node.start();

    return 0;
}