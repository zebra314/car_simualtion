cmake_minimum_required(VERSION 2.8.3)

project(asado_description)

find_package(catkin REQUIRED)

catkin_package()

find_package(catkin REQUIRED COMPONENTS
  joint_state_publisher
  robot_state_publisher
  rviz
)

foreach(dir config launch meshes rviz urdf)
	install(DIRECTORY ${dir}/
		DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
endforeach(dir)
