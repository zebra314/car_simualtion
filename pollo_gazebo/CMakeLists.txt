cmake_minimum_required(VERSION 3.0.2)
project(pollo_gazebo)

find_package(catkin REQUIRED
  rospy
)

catkin_package(
  CATKIN_DEPENDS
  rospy
)

include_directories(
)

install(PROGRAMS
  src/obstacle_spawner.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)