## Setup 
- 1.A Installation for local ROS environment :
```bash
    sudo apt-get install ros-$ROS_DISTRO-joy ros-$ROS_DISTRO-teleop-twist-joy ros-$ROS_DISTRO-teleop-twist-keyboard
```

- 1.B Installation for robostack conda environment : 
```bash
    mamba install -c robostack ros-$ROS_DISTRO-joy ros-$ROS_DISTRO-teleop-twist-joy
```

## Usage
- 1.A Control pollo_asado using PS4 joystick :       
```bash
    roslaunch asado_teleop teleop_joystick.launch
```   

- 1.B Control pollo_asado using keyboard (Current not functional in robostack env) :
```bash
    roslaunch asado_teleop teleop_keyboard.launch
```

## [Back](../README.md#setup-and-usage)