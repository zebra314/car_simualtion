cmake_minimum_required(VERSION 2.8.3)
project(pollo_gazebo)

# add_compile_options(-std=c++11)

find_package(catkin REQUIRED
  rospy
)

catkin_package(
  CATKIN_DEPENDS
  rospy
)

include_directories(
)