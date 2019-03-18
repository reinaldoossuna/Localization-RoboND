
source "/opt/ros/$ROS_DISTRO/setup.bash"
source "/home/catkin_ws/devel/setup.bash"

# some nice alias
alias cw="cd /home/catkin_ws"
alias cs="cd /home/catkin_ws/src"
alias cm="cw && catkin_make"
alias ss="cw; source devel/setup.bash; echo "setup.bash""
alias ..="cd .."
alias kk="xterm -e /home/kill_ros.sh"
