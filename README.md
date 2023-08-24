# Pollo Asado
## Overview
A ROS package for simulating a mobile robot with four wheels in Gazebo.

## Usage
- features
    - [pollo_main_control](./features/pollo_main_control/README.md)
    - [pollo_plate_control](./features/pollo_plate_control/README.md)
    - [pollo_upper_control](./features/pollo_upper_control/README.md)
- [pollo_bringup](pollo_bringup/README.md)
- [pollo_control](pollo_control/README.md)
- [pollo_description](pollo_description/README.md)
- [pollo_gazebo](pollo_gazebo/README.md)
- [pollo_mln](pollo_mln/README.md)
- [pollo_teleop](pollo_teleop/README.md)
- sensors
    - [rplidar_ros](./sensors/rplidar_ros/README.md) 

## Setup   
- Installation for local ROS environment :  
```bash
    sudo apt-get install ros-$ROS_DISTRO-velocity-controllers 
    sudo apt-get install ros-$ROS_DISTRO-joint-state-controller 
    sudo apt-get install ros-$ROS_DISTRO-controller-manager 
    sudo apt-get install ros-$ROS_DISTRO-joint_state_publisher
    sudo apt-get install ros-$ROS_DISTRO-joint_state_publisher_gui
    sudo apt-get install ros-$ROS_DISTRO-laser-assembler 
    sudo apt-get install ros-$ROS_DISTRO-gazebo-ros-pkgs 
    sudo apt-get install ros-$ROS_DISTRO-gazebo-ros 
    sudo apt-get install ros-$ROS_DISTRO-gazebo-ros-control 
    sudo apt-get install ros-$ROS_DISTRO-gmapping 
    sudo apt-get install ros-$ROS_DISTRO-map-server 
    sudo apt-get install ros-$ROS_DISTRO-navigation 
    sudo apt-get install ros-$ROS_DISTRO-joy 
    sudo apt-get install ros-$ROS_DISTRO-teleop-twist-joy 
    sudo apt-get install ros-$ROS_DISTRO-teleop-twist-keyboard  
    sudo apt-get install ros-$ROS_DISTRO-amcl    
    sudo apt-get install ros-$ROS_DISTRO-move-base 
    sudo apt-get install ros-$ROS_DISTRO-map-server   
    pip install qrcode_terminal
    pip install tornado
```   

- Installation for robostack conda environment :  
```bash
    mamba install -c robostack ros-$ROS_DISTRO-joy 
    mamba install -c robostack ros-$ROS_DISTRO-teleop-twist-joy
    mamba install -c robostack ros-$ROS_DISTRO-gmapping 
    mamba install -c robostack ros-$ROS_DISTRO-map-server 
    mamba install -c robostack ros-$ROS_DISTRO-gazebo-ros-pkgs 
    mamba install -c robostack ros-$ROS_DISTRO-gazebo-ros 
    mamba install -c robostack ros-$ROS_DISTRO-gazebo-ros-control 
    mamba install -c robostack ros-$ROS_DISTRO-velocity-controllers 
    mamba install -c robostack ros-$ROS_DISTRO-joint-state-controller 
    mamba install -c robostack ros-$ROS_DISTRO-controller-manager 
    mamba install -c robostack ros-$ROS_DISTRO-laser-assembler   
    mamba install -c robostack ros-$ROS_DISTRO-amcl    
    mamba install -c robostack ros-$ROS_DISTRO-move-base    
    mamba install -c robostack ros-$ROS_DISTRO-map-server    
    pip install qrcode_terminal  
    pip3 install tornado      
    
    # Do not install ros-noetic-pcl-ros, it will change the version of some pkgs,     
    # and cause gazebo to crash.    
    # If you have installed it and gazebo crashes, remove the env and create a new one.   
```   

## Quick Start
- 1. Control the real time robot with gui
    ```bash
    # bash-1
    roslaunch pollo_bringup bringup.launch

    # bash-2
    roslaunch pollo_teleop teleop.launch method:=gui
    ```
- 2. Control the robot in simulation with joystick
    ```bash
    # bash-1
    roslaunch pollo_gazebo bringup.launch sim:=true

    # bash-2
    roslaunch pollo_teleop teleop.launch method:=joystick
    ```