## Dependencies   
1. joy : provides a ROS node that reads the joystick inputs and publishes them as ROS messages
    ```bash
    sudo apt-get install ros-$ROS_DISTRO-joy
    ```
2. teleop-twist-joy : converts the joystick inputs (the data in topic named /joy_teleop/joy) into Twist commands, which represent linear and angular velocities, and publishes them as ROS messages.
    ```bash
    sudo apt-get install ros-$ROS_DISTRO-teleop-twist-joy
    ```

3. mamba install -c lianghongzhuo ros-noetic-teleop-twist-keyboard
## Quick start
1. Control pollo_asado using PS4 joystick    
    ```bash
    roslaunch asado_teleop teleop.launch
    ```    