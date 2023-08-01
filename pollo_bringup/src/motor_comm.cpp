#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <iostream>
#include <cstdint>

extern "C"{
#include <pollo_bringup/motor_function.h>
}

void writeRegister();
void initMsg();
void clearMsg(serialData *targetMsg);
void processMsg(carInfo *car_info);
void sendMsg(carInfo *car_info);
void velCmdCallback(const geometry_msgs::Twist::ConstPtr& msg);

serialData msg;
carInfo car_info_;

int main(int argc, char **argv){
    ros::init(argc, argv, "motor_comm");
    serialInit();
    initMsg();
    ros::NodeHandle rosNh;
    std::cout<<"motor_comm node is running..."<<std::endl;
    ros::Subscriber velCmdSub = rosNh.subscribe("/pollo/cmd_vel", 1, velCmdCallback);
    ros::spin();
    // while(ros::ok()){
    //   writeRegister();
    //   CRC16Generate(&msg);
    //   transmitData(&msg);
    //   receiveData(&msg);
    // }

    return 0;
}

void velCmdCallback(const geometry_msgs::Twist::ConstPtr& msg){
  car_info_.linear_x = msg->linear.x;
  car_info_.angular_z = msg->angular.z;
  processMsg(&car_info_);
  sendMsg(&car_info_);
  return;
}

void processMsg(carInfo *car_info){
  double linear_x = car_info->linear_x;
  double angular_z = car_info->angular_z;
  double wheel_radius = 0.08;

  double lf_wheel_vel = 20 * (linear_x - angular_z * 0.5) / wheel_radius;
  double rf_wheel_vel = 20 * (linear_x + angular_z * 0.5) / wheel_radius;
  double lb_wheel_vel = 20 * (linear_x - angular_z * 0.5) / wheel_radius;
  double rb_wheel_vel = 20 * (linear_x + angular_z * 0.5) / wheel_radius;

  car_info->lf_wheel.data[4] = (0xff & (int(lf_wheel_vel) >> 8));
  car_info->rf_wheel.data[4] = (0xff & (int(rf_wheel_vel) >> 8));
  car_info->lb_wheel.data[4] = (0xff & (int(lb_wheel_vel) >> 8));
  car_info->rb_wheel.data[4] = (0xff & (int(rb_wheel_vel) >> 8));

  car_info->lf_wheel.data[5] = (0xff & int(lf_wheel_vel));
  car_info->rf_wheel.data[5] = (0xff & int(rf_wheel_vel));
  car_info->lb_wheel.data[5] = (0xff & int(lb_wheel_vel));
  car_info->rb_wheel.data[5] = (0xff & int(rb_wheel_vel));

  return;
}

void sendMsg(carInfo *car_info){
  transmitData(&car_info->lf_wheel);
  transmitData(&car_info->rf_wheel);
  transmitData(&car_info->lb_wheel);
  transmitData(&car_info->rb_wheel);
  return;
}

void writeRegister(){
    int input;

    clearMsg(&msg);
    msg.length = 8;
    std::cout << "enter target address: (dec)" << std::endl;
    std::cin >> std::dec >> input;
    std::cin.get();
    msg.data[0] = (uint8_t)input;
    std::cout << std::endl;

    msg.data[1] = 0x06;

    std::cout << "enter register address: (hex)" << std::endl;
    std::cin >> std::hex >> input;
    std::cin.get();
    msg.data[3] = (0xff & input);
    msg.data[2] = (0xff & (input >> 8));
    std::cout << std::endl;

    std::cout << "enter data: (dec)" << std::endl;
    std::cin >> std::dec >> input;
    std::cin.get();
    msg.data[5] = (0xff & input);
    msg.data[4] = (0xff & (input >> 8));
    std::cout << std::endl;

    return ;
}

void clearMsg(serialData *targetMsg){
  for(int i = 0; i < 20; i++){
    targetMsg->data[i]= 0;
  }
  targetMsg->length = 0;
  return;
}

void initMsg(){
  clearMsg(&car_info_.lf_wheel);
  clearMsg(&car_info_.lb_wheel);
  clearMsg(&car_info_.rb_wheel);
  clearMsg(&car_info_.rf_wheel);

  car_info_.lf_wheel.length = 8;
  car_info_.lb_wheel.length = 8;
  car_info_.rb_wheel.length = 8;
  car_info_.rf_wheel.length = 8;

  // 從站
  car_info_.lf_wheel.data[0] = (uint8_t)1;
  car_info_.lb_wheel.data[0] = (uint8_t)2;
  car_info_.rb_wheel.data[0] = (uint8_t)3;
  car_info_.rf_wheel.data[0] = (uint8_t)4;

  // 寫入模式 
  car_info_.lf_wheel.data[1] = 0x06;
  car_info_.lb_wheel.data[1] = 0x06;
  car_info_.rb_wheel.data[1] = 0x06;
  car_info_.rf_wheel.data[1] = 0x06;

  // 速度控制 dec(43)
  car_info_.lf_wheel.data[2] = (0xff & (0x2B >> 8));
  car_info_.lb_wheel.data[2] = (0xff & (0x2B >> 8));
  car_info_.rb_wheel.data[2] = (0xff & (0x2B >> 8));
  car_info_.rf_wheel.data[2] = (0xff & (0x2B >> 8));

  car_info_.lf_wheel.data[3] = (0xff & 0x2B);
  car_info_.lb_wheel.data[3] = (0xff & 0x2B);
  car_info_.rb_wheel.data[3] = (0xff & 0x2B);
  car_info_.rf_wheel.data[3] = (0xff & 0x2B);

  // 初始速度 0
  car_info_.lf_wheel.data[4] = (0xff & (0x00 >> 8));
  car_info_.lb_wheel.data[4] = (0xff & (0x00 >> 8));
  car_info_.rb_wheel.data[4] = (0xff & (0x00 >> 8));
  car_info_.rf_wheel.data[4] = (0xff & (0x00 >> 8));

  car_info_.lf_wheel.data[5] = (0xff & 0x00);
  car_info_.lb_wheel.data[5] = (0xff & 0x00);
  car_info_.rb_wheel.data[5] = (0xff & 0x00);
  car_info_.rf_wheel.data[5] = (0xff & 0x00);
}