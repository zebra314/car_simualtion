# RPLIDAR ROS package

ROS node and test application for RPLIDAR

Visit following Website for more details about RPLIDAR:

rplidar roswiki: <http://wiki.ros.org/rplidar>

rplidar HomePage: <http://www.slamtec.com/en/Lidar>

rplidar SDK: <https://github.com/Slamtec/rplidar_sdk>

rplidar Tutorial: <https://github.com/robopeak/rplidar_ros/wiki>

## Uasge
- [rplidar.launch](./launch/rplidar.launch)
   - Launch the rplidar node.
   ```bash
   roslaunch rplidar_ros rplidar_s2.launch
   ```
   
- [view_rplidar_s2.launch](./launch/view_rplidar_s2.launch)
   - Launch the rplidar node and view the scan result in rviz.
   ```bash
   roslaunch rplidar_ros view_rplidar_s2.launch
   ```

## [Back](../../README.md#usage)