# Obstacle avoidance simulation in Gazebo
## Setup  
- 1.A : Installation for local ROS environment:   
```bash
    # Install the dependencies
    sudo apt-get install ros-noetic-gazebo-ros-pkgs ros-noetic-gazebo-ros    ros-noetic-gazebo-ros-control ros-noetic-velocity-controllers ros-noetic-joint-state-controller ros-noetic-controller-manager ros-noetic-laser-assembler 
```   
   
- 1.B : Installation for robostack conda environment : 
```bash    
    # Install ros1 environment  
    mamba create -n ros1_env  
    mamba activate ros1_env  
  
    conda config --env --add channels conda-forge  
    conda config --env --add channels robostack-staging  
    conda config --env --remove channels defaults  
  
    mamba install ros-noetic-desktop    
    mamba install compilers cmake pkg-config make ninja colcon-common-extensions catkin_tools  

    # Install additional pkgs  
    mamba install -c robostack ros-noetic-gazebo-ros-pkgs ros-noetic-gazebo-ros ros-noetic-gazebo-ros-control ros-noetic-velocity-controllers ros-noetic-joint-state-controller ros-noetic-controller-manager ros-noetic-laser-assembler  

    # Do not install ros-noetic-pcl-ros, it will change the version of some pkgs,  
    # and cause gazebo to crash.  
    # If you have installed it and gazebo crashes, remove the env and create a new one.   
```  

2. Clone this repo to local workspace and compile   
## Quick Start   
Gazebo and Rviz:   
```bash    
    roslaunch car_simulation spawn.launch
```   
   
Example of Moving Joints:
```bash   
    rosrun car_simulation SetJointVelocity.py  
```