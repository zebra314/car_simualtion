cmake_minimum_required(VERSION 3.0.2)
project(pollo_bringup)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  geometry_msgs
)

catkin_package(
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(motor_tool_library src/motor_function.c include/motor_function.h)

add_executable(motor_tool src/motor_tool.cpp)
target_link_libraries(motor_tool motor_tool_library ${catkin_LIBRARIES})

add_executable(motor_comm src/motor_comm.cpp)
target_link_libraries(motor_comm motor_tool_library ${catkin_LIBRARIES})
