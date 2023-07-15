## Setup
- 1.A Installation for local ROS environment :
```bash
    sudo apt-get install ros-$ROS_DISTRO-gmapping ros-$ROS_DISTRO-map-server ros-$ROS_DISTRO-navigation
```

- 1.B Installation for robostack conda environment : 
```bash
    mamba install -c robostack ros-$ROS_DISTRO-gmapping ros-$ROS_DISTRO-map-server 
```

## Usage
- 1. Build the map using gmapping :
```bash
    roslaunch asado_navigation gmapping.launch
```

- 2. Save the map :
```bash
    rosrun map_server map_saver -f ~/map
```

- 3. Localize the robot using amcl :
```bash
    roslaunch asado_navigation amcl.launch
```

- 4. Navigate the robot using rviz :
```bash
    roslaunch asado_navigation move_base.launch
```

## [Back](../README.md#setup-and-usage)