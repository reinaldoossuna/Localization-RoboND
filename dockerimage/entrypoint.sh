#!/bin/bash

set -e

# setup ros 
source "/opt/ros/$ROS_DISTRO/setup.bash"
source "/home/catkin_ws/devel/setup.bash"

exec "$@"
