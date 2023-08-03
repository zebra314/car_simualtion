# Pollo Asado
## Overview
A ROS package for simulating a mobile robot with four wheels in Gazebo.

## Usage
- [pollo_bringup](pollo_bringup/README.md)
- [pollo_control](pollo_control/README.md)      
- [pollo_description](pollo_description/README.md)   
- [pollo_gazebo](pollo_gazebo/README.md)      
- [pollo_navigation](pollo_navigation/README.md) 
- [pollo_sensors](pollo_sensors/README.md)     
- [pollo_teleop](pollo_teleop/README.md)     

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
    
    # Do not install ros-noetic-pcl-ros, it will change the version of some pkgs,     
    # and cause gazebo to crash.    
    # If you have installed it and gazebo crashes, remove the env and create a new one.   
```   

## Quick Start
- 1. Navigate the robot in Gazebo :   
```bash
    # bash-1
    # Use 2D Nav Goal in Rviz to set the goal position
    roslaunch pollo_navigation navigation.launch
```
- 2. Control the robot using PS4 joystick
```bash
    # bash-2
    roslaunch pollo_teleop teleop.launch
```  