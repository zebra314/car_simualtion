## Setup 
- 1.A : Installation for local ROS environment :
```bash
    sudo apt-get install ros-$ROS_DISTRO-joy
    sudo apt-get install ros-$ROS_DISTRO-teleop-twist-joy
```

- 1.B : Installation for robostack conda environment : 
```bash
    mamba install -c robostack ros-$ROS_DISTRO-joy ros-$ROS_DISTRO-teleop-twist-joy
```

## Quick start
1. Control pollo_asado using PS4 joystick:       
```bash
    roslaunch asado_teleop teleop.launch
```    