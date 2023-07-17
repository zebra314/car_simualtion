# Pollo Asado
## Overview
A ROS package for simulating a mobile robot with four wheels in Gazebo.

## Usage   
- [asado_control](asado_control/README.md)      
- [asado_description](asado_description/README.md)   
- [asado_gazebo](asado_gazebo/README.md)      
- [asado_navigation](asado_navigation/README.md)      
- [asado_teleop](asado_teleop/README.md)     

## Setup   
- Installation for local ROS environment :  
```bash
    sudo apt-get install 
    ros-$ROS_DISTRO-joy 
    ros-$ROS_DISTRO-teleop-twist-joy 
    ros-$ROS_DISTRO-teleop-twist-keyboard 
    ros-$ROS_DISTRO-gmapping 
    ros-$ROS_DISTRO-map-server 
    ros-$ROS_DISTRO-navigation 
    ros-$ROS_DISTRO-gazebo-ros-pkgs 
    ros-$ROS_DISTRO-gazebo-ros 
    ros-$ROS_DISTRO-gazebo-ros-control 
    ros-$ROS_DISTRO-velocity-controllers 
    ros-$ROS_DISTRO-joint-state-controller 
    ros-$ROS_DISTRO-controller-manager 
    ros-$ROS_DISTRO-laser-assembler 
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
    roslaunch asado_gazebo spawn.launch

    # bash-2
    roslaunch asado_teleop teleop.launch
```  

- 2. Navigate the robot in Gazebo :   
```bash
    # Use 2D Nav Goal in Rviz to set the goal position
    roslaunch asado_navigation navigation.launch
```