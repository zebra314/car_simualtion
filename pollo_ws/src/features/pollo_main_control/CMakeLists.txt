cmake_minimum_required(VERSION 3.0.2)
project(pollo_main_control)
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

# catkin_install_python(PROGRAMS
  # src/mainA.py
  # src/mainA-reset.py
  # src/mainB.py
  # src/mainB-reset.py
  # src/test-script.py
  # src/mainA_test.py
  # DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )