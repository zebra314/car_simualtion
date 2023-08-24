## Dependencies
```bash
    pip install qrcode_terminal   
    ros-$ROS_DISTRO-joy     
    ros-$ROS_DISTRO-teleop-twist-joy         
    ros-$ROS_DISTRO-teleop-twist-keyboard    
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
    
- [teleop.launch](./launch/teleop.launch)
    - Control the robot :
    ```bash
    roslaunch pollo_teleop teleop.launch # with web page (default)
    # or
    roslaunch pollo_teleop teleop.launch method:=gui # with gui 
    # or
    roslaunch pollo_teleop teleop.launch method:=joystick # with joystick
    # or
    roslaunch pollo_teleop teleop.launch method:=keyboard # with keyboard
    ```
- If using the web page, make sure to connect to the same network as the robot.

- The web page is built using [ROSboard](./rosboard.md)
## [Back](../README.md#usage)