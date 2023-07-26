# Pollo Asado
## Overview
A ROS package for simulating a mobile robot with four wheels in Gazebo.

## Usage   
- [pollo_control](pollo_control/README.md)      
- [pollo_description](pollo_description/README.md)   
- [pollo_gazebo](pollo_gazebo/README.md)      
- [pollo_navigation](pollo_navigation/README.md) 
- [pollo_sensors](pollo_sensors/README.md)     
- [pollo_teleop](pollo_teleop/README.md)     

## Setup   
- Installation for local ROS environment :  
```bash
    sudo apt-get install 
    ros-$ROS_DISTRO-velocity-controllers 
    ros-$ROS_DISTRO-joint-state-controller 
    ros-$ROS_DISTRO-controller-manager 
    ros-$ROS_DISTRO-joint_state_publisher
    ros-$ROS_DISTRO-joint_state_publisher_gui
    ros-$ROS_DISTRO-laser-assembler 
    ros-$ROS_DISTRO-gazebo-ros-pkgs 
    ros-$ROS_DISTRO-gazebo-ros 
    ros-$ROS_DISTRO-gazebo-ros-control 
    ros-$ROS_DISTRO-gmapping 
    ros-$ROS_DISTRO-map-server 
    ros-$ROS_DISTRO-navigation 
    ros-$ROS_DISTRO-joy 
    ros-$ROS_DISTRO-teleop-twist-joy 
    ros-$ROS_DISTRO-teleop-twist-keyboard 
```   

- Installation for robostack conda environment :  
```bash
    mamba install -c robostack 
    ros-$ROS_DISTRO-joy 
    ros-$ROS_DISTRO-teleop-twist-joy
    ros-$ROS_DISTRO-gmapping 
    ros-$ROS_DISTRO-map-server 
    ros-$ROS_DISTRO-gazebo-ros-pkgs 
    ros-$ROS_DISTRO-gazebo-ros 
    ros-$ROS_DISTRO-gazebo-ros-control 
    ros-$ROS_DISTRO-velocity-controllers 
    ros-$ROS_DISTRO-joint-state-controller 
    ros-$ROS_DISTRO-controller-manager 
    ros-$ROS_DISTRO-laser-assembler  
    
    # Do not install ros-noetic-pcl-ros, it will change the version of some pkgs,     
    # and cause gazebo to crash.    
    # If you have installed it and gazebo crashes, remove the env and create a new one.   
```   

## Quick Start
- 1. Spawn the model in Gazebo and control the robot using PS4 joystick:   
```bash    
    # bash-1
    roslaunch pollo_gazebo spawn.launch
```
```bash
    # bash-2
    roslaunch pollo_teleop teleop.launch
```  

- 2. Navigate the robot in Gazebo :   
```bash
    # Use 2D Nav Goal in Rviz to set the goal position
    roslaunch pollo_navigation navigation.launch
```