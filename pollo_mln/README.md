## Dependencies
```bash
    ros-$ROS_DISTRO-gmapping 
    ros-$ROS_DISTRO-map-server 
    ros-$ROS_DISTRO-navigation 
```

## Usage
- The robot needs to be set up first, either in gazebo or in real life.
    ```bash
    roslaunch pollo_bringup bringup.launch # for real robot
    # or 
    roslaunch pollo_gazebo spawn.launch # for simulation only
    # or
    roslaunch pollo_bringup bringup.launch sim:=true # for both real and simulation
    ```

- [localization.launch](./launch/localization.launch)
    - Localize the robot with amcl.

- [navigation.launch](./launch/navigation.launch)
    - Launch the navigation stack.
    - Clear costmaps
    ```bash
    rosservice call /move_base/clear_costmaps "{}"
    ```

## [Back](../README.md#usage)