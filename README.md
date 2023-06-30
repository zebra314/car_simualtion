# Obstacle avoidance simulation in Gazebo
## Setup  
Install : 
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
    mamba install -c robostack ros-noetic-gazebo-ros-pkgs ros-noetic-gazebo-ros    ros-noetic-gazebo-ros-control  ros-noetic-velocity-controllers ros-noetic-joint-state-controller   ros-noetic-controller-manager    
      
    mamba install -c robostack ros-noetic-laser-assembler  

    # Do not install ros-noetic-pcl-ros, it will change the version of some pkgs,  
    # and cause gazebo to crash.  
    # If you install it and gazebo crashes, remove the env and create a new one.  
    # mamba install -c robostack ros-noetic-pcl-ros   
```  

## Quick Start   
Gazebo and Rviz:   
```bash    
    roslaunch car_simulation spawn.launch
```   
   
Example of Moving Joints:
```bash   
    rosrun car_simulation SetJointVelocity.py  
```