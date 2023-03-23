#include "Lidar.h"

Lidar::Lidar() {
  this->_active = false;
  this->_motor_enabled_pin = 26;
  this->_motor_speed_pin = 37;
}

void Lidar::init() {
  pinMode(_motor_enabled_pin, OUTPUT);
  digitalWrite(_motor_enabled_pin, LOW);

  ledcSetup(0, 1000, 8);
  ledcAttachPin(_motor_speed_pin, 0);
  ledcWrite(0, 0); 
}

void Lidar::rotationSpeed(int speed) {
  ledcWrite(0, speed); 
}