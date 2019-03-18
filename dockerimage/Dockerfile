FROM osrf/ros:kinetic-desktop-full-xenial
RUN apt-get update && apt-get -y upgrade

RUN apt-get install -y --no-install-recommends \
  ros-kinetic-navigation \
  ros-kinetic-map-server \
  ros-kinetic-move-base \
  ros-kinetic-amcl 

RUN mkdir -p /root/catkin_ws/src/ &&\
    cd /root/catkin_ws/src/ &&\
    /bin/bash -c "cd /root/catkin_ws/ &&\
                  source /opt/ros/kinetic/setup.bash &&\
                  /opt/ros/kinetic/bin/catkin_make" &&\
    cd /root/catkin_ws/src/ &&\
    git clone https://github.com/turtlebot/turtlebot

RUN /bin/bash -c "source /opt/ros/kinetic/setup.bash &&\
                  cd /root/catkin_ws &&\
                  source /root/catkin_ws/devel/setup.bash &&\
                  rosdep -i -y install turtlebot_teleop &&\
                  /opt/ros/kinetic/bin/catkin_make" 

COPY ./.bashrc /root/

COPY ./entrypoint.sh /

ENTRYPOINT ["/entrypoint.sh"]

CMD ["bash"]


# nvidia-container-runtime
ENV NVIDIA_VISIBLE_DEVICES \
    ${NVIDIA_VISIBLE_DEVICES:-all}
ENV NVIDIA_DRIVER_CAPABILITIES \
    ${NVIDIA_DRIVER_CAPABILITIES:+$NVIDIA_DRIVER_CAPABILITIES,}graphics

RUN  rm -rf /var/lib/apt/lists/*

