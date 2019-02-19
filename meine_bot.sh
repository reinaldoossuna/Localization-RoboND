#!/bin/bash

source /home/.bashrc

xterm -e "roslaunch meine_bot empty_world.launch" &

sleep 5

xterm -e "roslaunch meine_bot amcl.launch" &

sleep 10

xterm -e "rosrun drive_bot navigation_goals"
