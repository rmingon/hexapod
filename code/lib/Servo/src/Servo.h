#ifndef SERVO_H
#define SERVO_H

#include <Arduino.h>

void servoInit();

void servoSetAll(uint16_t pwm);

#endif