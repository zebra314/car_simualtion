#!/usr/bin/env python
import rospy
import random
from gazebo_msgs.srv import SpawnModel
from geometry_msgs.msg import Pose

rospy.init_node('obstacle_spawner',log_level=rospy.INFO)
rospy.wait_for_service('/gazebo/spawn_sdf_model')
spawn_model_client = rospy.ServiceProxy('/gazebo/spawn_sdf_model', SpawnModel)

obstacle_xml = \
	"""
    <sdf version='1.6'>
      <model name='my_box'>
        <static>false</static>
        <link name='link'>
					<inertial>
						<mass>20.0</mass>
					</inertial>
          <collision name='collision'>
            <geometry>
              <box>
                <size>0.4 0.25 0.8</size>
              </box>
            </geometry>
          </collision>
          <visual name='visual'>
            <geometry>
              <box>
                <size>0.4 0.25 0.8</size>
              </box>
            </geometry>
          </visual>
        </link>
      </model>
    </sdf>
  """

obstacle_position = [
    [[-0.49,5.65,1],[0.41,5.65,1],[1.31,5.65,1]],
    [[-0.49,4.35,1],[0.41,4.35,1],[1.31,4.35,1]],
    [[-0.49,3.05,1],[0.41,3.05,1],[1.31,3.05,1]]
]

for i in range(3):
	skip_index = random.randint(0,2)
	for j in range(3):
		if j != skip_index:
			initial_pose = Pose()
			initial_pose.position.x = obstacle_position[i][j][0]
			initial_pose.position.y = obstacle_position[i][j][1]
			initial_pose.position.z = obstacle_position[i][j][2]
			spawn_model_client(
				model_name= 'obstacle-'+str(i)+'-'+str(j),
				model_xml= obstacle_xml,
				robot_namespace='/foo',
				initial_pose = initial_pose,
				reference_frame='world'
			)