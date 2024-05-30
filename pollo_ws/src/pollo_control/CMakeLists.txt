cmake_minimum_required(VERSION 2.8.3)
project(pollo_control)

find_package(catkin REQUIRED COMPONENTS
  controller_manager
  hardware_interface
  roscpp
  sensor_msgs
  transmission_interface
)

catkin_package(
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)