#!/bin/bash

source /home/.bashrc

xterm -e "roslaunch udacity_bot udacity_world.launch" &

sleep 5

xterm -e "roslaunch udacity_bot amcl.launch" &

sleep 5

xterm -e "roslaunch turtlebot_teleop keyboard_teleop.launch"
