## Dependencies
```bash
    ros-$ROS_DISTRO-joy
    ros-$ROS_DISTRO-teleop-twist-joy       
    ros-$ROS_DISTRO-teleop-twist-keyboard   
```

## Usage
- [teleop.launch](./launch/teleop.launch)
    - The robot needs to be set up first, either [in gazebo](../asado_gazebo/README.md) or [in real life](../asado_bringup/README.md), then launch this node to control the robot.  

    - Control the robot with joystick (default) :
    ```bash
        roslaunch asado_teleop teleop.launch 
    ```
    
    - Control the robot with keyboard :
    ```bash
        roslaunch asado_teleop teleop.launch method:=keyboard
    ```


## [Back](../README.md#usage)