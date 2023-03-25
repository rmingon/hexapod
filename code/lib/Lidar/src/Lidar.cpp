#include "Lidar.h"

#define MOTOR_ENABLE_PIN 26
#define MOTOR_SPEED_PIN 26

Lidar::Lidar() {
  this->_active = false;
}

void Lidar::init() {
  pinMode(MOTOR_ENABLE_PIN, OUTPUT);
  digitalWrite(MOTOR_ENABLE_PIN, LOW);

  ledcSetup(0, 1000, 8);
  ledcAttachPin(MOTOR_SPEED_PIN, 0);
  ledcWrite(0, 0);
}

void Lidar::rotationSpeed(uint8_t speed) {
  ledcWrite(0, speed); 
}

void Lidar::stop() {
  digitalWrite(MOTOR_ENABLE_PIN, LOW);
  rotationSpeed(0);
}

void Lidar::start() {
  digitalWrite(MOTOR_ENABLE_PIN, LOW);
  rotationSpeed(127);
}