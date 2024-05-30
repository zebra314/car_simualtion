#!/bin/zsh
source /opt/ros/noetic/setup.zsh && \
    source /root/pollo_ws/devel/setup.zsh && \
    cd /root/pollo_ws && \
    catkin_make

exec "$@"