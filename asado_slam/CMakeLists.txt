cmake_minimum_required(VERSION 2.8.3)

project(asado_slam)

find_package(catkin REQUIRED)

catkin_package()

find_package(roslaunch)

foreach(dir config launch rviz config maps)
	install(DIRECTORY ${dir}/
		DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
endforeach(dir) 