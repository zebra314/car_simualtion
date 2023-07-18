## Dependicies
```bash
    ros-$ROS_DISTRO-gazebo-ros-pkgs 
    ros-$ROS_DISTRO-gazebo-ros 
    ros-$ROS_DISTRO-gazebo-ros-control 
```  

## Usage
- [base.launch](./launch/base.launch)
    - Run the simulation and the real robot simultaneously.
- [spawn.launch](./launch/spawn.launch)
    - Spawn the robot in the simulation.
- [world.launch](./launch/world.launch)
    - Spawn the world in the simulation.
    - This file is called by other launch files, no need to run it manually.

## [Back](../README.md#usage)
