# Pollo Asado
## Overview
A ROS package for simulating a mobile robot with four wheels in Gazebo.

## Setup and Usage
- [Simulation](asado_simulation/README.md)   
- [Navigation](asado_navigation/README.md)
- [Teleop](asado_teleop/README.md)   

## Quick Start
- 1. Spawn the model in Gazebo world :   
```bash    
    roslaunch asado_simulation spawn.launch
```  

- 2. Localize the robot using amcl :   
```bash
    roslaunch asado_navigation move_base.launch
```

- 3. Control pollo_asado using PS4 joystick :       
```bash
    roslaunch asado_teleop teleop_joystick.launch
```   