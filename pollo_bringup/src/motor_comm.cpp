#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <iostream>
#include <cstdint>

extern "C"
{
  #include <motor_function.h>
}

// Msg {Data, Length, Status}
void initMsg(carInfo *car_info);
void clearMsg(carInfo *car_info);
void processMsg(carInfo *car_info);
void sendMsg(carInfo *car_info);
void clearData(serialData *targetMsg);
void velCmdCallback(const geometry_msgs::Twist::ConstPtr& msg);

carInfo car_info_;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "motor_comm");
  ros::NodeHandle rosNh;
  ros::Subscriber velCmdSub = rosNh.subscribe("/pollo/cmd_vel", 1, velCmdCallback);
  serialInit();
  initMsg(&car_info_);

  ros::spin();
  return 0;
}

void velCmdCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
  car_info_.linear_x = msg->linear.x;
  car_info_.angular_z = msg->angular.z;
  processMsg(&car_info_);
  sendMsg(&car_info_);
  return;
}

void processMsg(carInfo *car_info)
{
  double linear_x = car_info->linear_x;
  double angular_z = car_info->angular_z;

  double wheel_radius = 0.08;
  double lf_wheel_vel = 20 * (linear_x - angular_z * 0.5) / wheel_radius;
  double rf_wheel_vel = 20 * (linear_x + angular_z * 0.5) / wheel_radius;
  double lb_wheel_vel = 20 * (linear_x - angular_z * 0.5) / wheel_radius;
  double rb_wheel_vel = 20 * (linear_x + angular_z * 0.5) / wheel_radius;

  std::cout<<"---------------------"<<std::endl;
  std::cout<<"lf_wheel_vel: "<<lf_wheel_vel<<std::endl;
  std::cout<<"rf_wheel_vel: "<<rf_wheel_vel<<std::endl;
  std::cout<<"lb_wheel_vel: "<<lb_wheel_vel<<std::endl;
  std::cout<<"rb_wheel_vel: "<<rb_wheel_vel<<std::endl;
  std::cout<<"---------------------"<<std::endl;

  // car_info->lf_wheel.data[4] = (0xff & (int(lf_wheel_vel) >> 8));
  // car_info->rf_wheel.data[4] = (0xff & (int(rf_wheel_vel) >> 8));
  // car_info->lb_wheel.data[4] = (0xff & (int(lb_wheel_vel) >> 8));
  // car_info->rb_wheel.data[4] = (0xff & (int(rb_wheel_vel) >> 8));

  // car_info->lf_wheel.data[5] = (0xff & int(lf_wheel_vel));
  // car_info->rf_wheel.data[5] = (0xff & int(rf_wheel_vel));
  // car_info->lb_wheel.data[5] = (0xff & int(lb_wheel_vel));
  // car_info->rb_wheel.data[5] = (0xff & int(rb_wheel_vel));

  car_info->lf_wheel.data[4] = 27;
  car_info->rf_wheel.data[4] = 27;
  car_info->lb_wheel.data[4] = 27;
  car_info->rb_wheel.data[4] = 27;

  car_info->lf_wheel.data[5] = 10;
  car_info->rf_wheel.data[5] = 10;
  car_info->lb_wheel.data[5] = 10;
  car_info->rb_wheel.data[5] = 10;

  return;
}

void sendMsg(carInfo *car_info)
{
  transmitData(&car_info->lf_wheel);
  transmitData(&car_info->rf_wheel);
  transmitData(&car_info->lb_wheel);
  transmitData(&car_info->rb_wheel);
  return;
}

void initMsg(carInfo *car_info)
{
  clearMsg(car_info);

  car_info->lf_wheel.length = 8;
  car_info->lb_wheel.length = 8;
  car_info->rb_wheel.length = 8;
  car_info->rf_wheel.length = 8;

  // 從站
  car_info->lf_wheel.data[0] = 1;
  car_info->lb_wheel.data[0] = 2;
  car_info->rb_wheel.data[0] = 3;
  car_info->rf_wheel.data[0] = 4;

  // 寫入模式 
  car_info->lf_wheel.data[1] = 6;
  car_info->lb_wheel.data[1] = 6;
  car_info->rb_wheel.data[1] = 6;
  car_info->rf_wheel.data[1] = 6;

  // 速度控制 dec(43)
  car_info->lf_wheel.data[2] = 0;
  car_info->lb_wheel.data[2] = 0;
  car_info->rb_wheel.data[2] = 0;
  car_info->rf_wheel.data[2] = 0;

  car_info->lf_wheel.data[3] = 43;
  car_info->lb_wheel.data[3] = 43;
  car_info->rb_wheel.data[3] = 43;
  car_info->rf_wheel.data[3] = 43;

  // 初始速度 0
  car_info->lf_wheel.data[4] = 0;
  car_info->lb_wheel.data[4] = 0;
  car_info->rb_wheel.data[4] = 0;
  car_info->rf_wheel.data[4] = 0;

  car_info->lf_wheel.data[5] = 0;
  car_info->lb_wheel.data[5] = 0;
  car_info->rb_wheel.data[5] = 0;
  car_info->rf_wheel.data[5] = 0;
}

void clearMsg(carInfo *car_info)
{
  clearData(&car_info->lf_wheel);
  clearData(&car_info->lb_wheel);
  clearData(&car_info->rb_wheel);
  clearData(&car_info->rf_wheel);
  return;
}


void clearData(serialData *targetMsg)
{
  for(int i = 0; i < 20; i++)
  {
    targetMsg->data[i]= 0;
  }
  targetMsg->length = 0;
  return;
}