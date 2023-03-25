#ifndef SERVO_H
#define SERVO_H

#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>

class Servo {
  private:
    Adafruit_PWMServoDriver servo_first;
    Adafruit_PWMServoDriver servo_second;
  public:
    Servo();
    void init();
    void setAll(uint16_t pwm);
};

#endif