cmake_minimum_required(VERSION 3.0.2)
project(pollo_upper_control)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  rospy
  std_msgs
)

# add_service_files(
#   FILES
# 
# )

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS message_generation roscpp rospy std_msgs message_runtime
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

# catkin_install_python(PROGRAMS
# src/arduino_command_server.py src/input_client.py
# DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )