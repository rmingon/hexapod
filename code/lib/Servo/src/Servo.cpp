#include "Servo.h"
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servo_first = Adafruit_PWMServoDriver(0x41);
Adafruit_PWMServoDriver servo_second = Adafruit_PWMServoDriver(0x40);

#define SERVO_FREQ 50

void servoInit() {
  servo_first.begin();
  servo_first.setOscillatorFrequency(27000000);
  servo_first.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  servo_second.begin();
  servo_second.setOscillatorFrequency(27000000);
  servo_second.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
}

void servoSetAll(uint16_t pwm) {
  for(int i = 0; i < 16; i++) {
    servo_first.setPWM(i, 0, pwm);
  }
  for(int i = 0; i < 16; i++) {
    servo_second.setPWM(i, 0, pwm);
  }
}