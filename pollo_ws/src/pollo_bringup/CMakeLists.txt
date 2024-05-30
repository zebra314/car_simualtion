cmake_minimum_required(VERSION 3.0.2)
project(pollo_bringup)
find_package(catkin REQUIRED COMPONENTS
  rospy
  std_msgs
  message_generation
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS rospy std_srvs message_runtime
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)