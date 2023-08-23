cmake_minimum_required(VERSION 3.0.2)
project(pollo_teleop)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  rospy
  std_msgs
  sensor_msgs
)

catkin_python_setup()
catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

catkin_install_python(PROGRAMS
  nodes/rosboard_node
  nodes/generate_qrcode.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)