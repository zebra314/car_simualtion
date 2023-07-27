#include <ros/ros.h>
#include <iostream>
#include <cstdint>

extern "C"{
#include <pollo_bringup/motor_function.h>
}

void writeRegister();
void settingController(uint8_t address);
void settingPID(uint8_t address, char type);
void initMsg();
void clearMsg(serialData *targetMsg);

serialData msg;
serialData lf_wheel_msg_;
serialData lb_wheel_msg_;
serialData rf_wheel_msg_;
serialData rb_wheel_msg_;

int main(int argc, char **argv){
    ros::init(argc, argv, "motor_comm");
    ros::NodeHandle rosNh;

    serialInit();

    while(ros::ok()){
      writeRegister();
      CRC16Generate(&msg);
      transmitData(&msg);
      receiveData(&msg);
    }
    return 0;
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
  clearMsg(&lf_wheel_msg_);
  clearMsg(&lb_wheel_msg_);
  clearMsg(&rf_wheel_msg_);
  clearMsg(&rb_wheel_msg_);

  lf_wheel_msg_.length = 8;
  lb_wheel_msg_.length = 8;
  rf_wheel_msg_.length = 8;
  rb_wheel_msg_.length = 8;

  // 從站
  lf_wheel_msg_.data[0] = 0x01;
  lb_wheel_msg_.data[0] = 0x02;
  rf_wheel_msg_.data[0] = 0x03;
  rb_wheel_msg_.data[0] = 0x04;

  // 寫入模式 
  lf_wheel_msg_.data[1] = 0x06;
  lb_wheel_msg_.data[1] = 0x06;
  rf_wheel_msg_.data[1] = 0x06;
  rb_wheel_msg_.data[1] = 0x06;

  // 速度控制 dec(43)
  lf_wheel_msg_.data[2] = (0xff & (0x2B >> 8));
  lb_wheel_msg_.data[2] = (0xff & (0x2B >> 8));
  rf_wheel_msg_.data[2] = (0xff & (0x2B >> 8));
  rb_wheel_msg_.data[2] = (0xff & (0x2B >> 8));

  lf_wheel_msg_.data[3] = (0xff & 0x2B);
  lb_wheel_msg_.data[3] = (0xff & 0x2B);
  rf_wheel_msg_.data[3] = (0xff & 0x2B);
  rb_wheel_msg_.data[3] = (0xff & 0x2B);

  // 初始速度 0
  lf_wheel_msg_.data[4] = (0xff & (0x00 >> 8));
  lb_wheel_msg_.data[4] = (0xff & (0x00 >> 8));
  rf_wheel_msg_.data[4] = (0xff & (0x00 >> 8));
  rb_wheel_msg_.data[4] = (0xff & (0x00 >> 8));

  lf_wheel_msg_.data[5] = (0xff & 0x00);
  lb_wheel_msg_.data[5] = (0xff & 0x00);
  rf_wheel_msg_.data[5] = (0xff & 0x00);
  rb_wheel_msg_.data[5] = (0xff & 0x00);
}