# Pollo Asado
## Overview
A ROS package for simulating a mobile robot with four wheels in Gazebo.

## Setup and Usage
- [Simulation](asado_simulation/README.md)   
- [Slam](asado_slam/README.md)
- [Teleop](asado_teleop/README.md)   

## Quick Start
- 1. Spawn the model in Gazebo world :   
```bash    
    roslaunch asado_simulation spawn.launch
```  

- 2. Build the map using gmapping :
```bash
    roslaunch asado_slam gmapping.launch
```

- 3. Control pollo_asado using PS4 joystick :       
```bash
    roslaunch asado_teleop teleop_joystick.launch
```   