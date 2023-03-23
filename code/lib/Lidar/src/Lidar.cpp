#include "Lidar.h"

int lidar_motor = 26;
int lidar_motor_speed = 37;

Lidar::Lidar() {
  this->_active = false;
  this->_motor_pin = lidar_motor;
  this->_motor_speed_pin = lidar_motor_speed;

}