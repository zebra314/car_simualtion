#!/usr/bin/env python3
import rospy
from std_msgs.msg import Float64

def forward(velocity):
    # 初始化ROS节点
    rospy.init_node('joint_velocity_controller')

    # 创建一个Publisher来发布关节速度控制消息
    pub_RF = rospy.Publisher('/asado/RF_wheel_velocity_controller/command', Float64, queue_size=10)
    pub_LF = rospy.Publisher('/asado/LF_wheel_velocity_controller/command', Float64, queue_size=10)
    pub_RB = rospy.Publisher('/asado/RB_wheel_velocity_controller/command', Float64, queue_size=10)
    pub_LB = rospy.Publisher('/asado/LB_wheel_velocity_controller/command', Float64, queue_size=10)

    # 创建一个Float64消息，用于设置关节速度
    LF_velocity_msg = Float64()
    LB_velocity_msg = Float64()
    RF_velocity_msg = Float64()
    RB_velocity_msg = Float64()

    # 设置关节名称和目标速度
    LF_velocity_msg.data = -velocity
    LB_velocity_msg.data = -velocity
    RF_velocity_msg.data = velocity
    RB_velocity_msg.data = velocity

    # 发布关节速度控制消息
    pub_LF.publish(LF_velocity_msg)
    pub_RF.publish(RF_velocity_msg)
    pub_LB.publish(LB_velocity_msg)
    pub_RB.publish(RB_velocity_msg)

    # 等待一段时间，以使消息得到处理
    rospy.sleep(0.5)

    # 停止发布消息
    # pub1.unregister()
    # pub2.unregister()
    # pub3.unregister()
    # pub4.unregister()

def turn(velocity):
    # 初始化ROS节点
    rospy.init_node('joint_velocity_controller')

    # 创建一个Publisher来发布关节速度控制消息
    pub_RF = rospy.Publisher('/asado/RF_wheel_velocity_controller/command', Float64, queue_size=10)
    pub_LF = rospy.Publisher('/asado/LF_wheel_velocity_controller/command', Float64, queue_size=10)
    pub_RB = rospy.Publisher('/asado/RB_wheel_velocity_controller/command', Float64, queue_size=10)
    pub_LB = rospy.Publisher('/asado/LB_wheel_velocity_controller/command', Float64, queue_size=10)

    # 创建一个Float64消息，用于设置关节速度
    LF_velocity_msg = Float64()
    LB_velocity_msg = Float64()
    RF_velocity_msg = Float64()
    RB_velocity_msg = Float64()

    # 设置关节名称和目标速度
    LF_velocity_msg.data = velocity
    LB_velocity_msg.data = velocity
    RF_velocity_msg.data = velocity
    RB_velocity_msg.data = velocity

    # 发布关节速度控制消息
    pub_LF.publish(LF_velocity_msg)
    pub_RF.publish(RF_velocity_msg)
    pub_LB.publish(LB_velocity_msg)
    pub_RB.publish(RB_velocity_msg)

    # 等待一段时间，以使消息得到处理
    rospy.sleep(0.5)

    # 停止发布消息
    # pub1.unregister()
    # pub2.unregister()
    # pub3.unregister()
    # pub4.unregister()

if __name__ == '__main__':
    while True:
    #   forward(50000)
      turn(50000)

