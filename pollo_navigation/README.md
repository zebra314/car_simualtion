## Dependencies
```bash
    ros-$ROS_DISTRO-gmapping 
    ros-$ROS_DISTRO-map-server 
    ros-$ROS_DISTRO-navigation 
```

## Usage
- [localization.launch](./launch/localization.launch)
    - Spawn the robot in gazebo and localize it with amcl.
    ```bash
        roslaunch pollo_navigation localization.launch
    ```

- [navigation.launch](./launch/navigation.launch)
    - Spawn the robot in gazebo and launch the navigation stack.
    ```bash
        roslaunch pollo_navigation navigation.launch
    ```

## [Back](../README.md#usage)