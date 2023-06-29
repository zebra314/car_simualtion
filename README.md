# Obstacle avoidance simulation in Gazebo
## Setup  
Install : 

    mamba create -n ros1_env
    mamba activate ros1_env

    conda config --env --add channels conda-forge
    conda config --env --add channels robostack-staging
    conda config --env --remove channels defaults

    mamba install ros-noetic-desktop
    mamba install compilers cmake pkg-config make ninja colcon-common-extensions catkin_tools

    mamba install -c robostack ros-noetic-gazebo-ros  ros-noetic-gazebo-ros-control  ros-noetic-velocity-controllers ros-noetic-joint-state-controller ros-noetic-controller-manager  
    
    mamba install -c robostack ros-noetic-laser-assembler
    mamba install -c robostack ros-noetic-gazebo-ros-pkgs
    # mamba install -c robostack ros-noetic-pcl-ros 有毒 裝了gazebo會core dump!!

## Quick Start
Gazebo and Rviz:

    roslaunch car_simulation car_control.launch

Example of Moving Joints:

    rosrun car_simulation SetJointVelocity.py  
