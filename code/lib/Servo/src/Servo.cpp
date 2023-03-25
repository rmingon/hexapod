#include "Servo.h"

#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

Servo::Servo() {
    Adafruit_PWMServoDriver servo_first = Adafruit_PWMServoDriver(0x41);
    Adafruit_PWMServoDriver servo_second = Adafruit_PWMServoDriver(0x40);
};

void Servo::init() {
  servo_first.begin();
  servo_first.setOscillatorFrequency(27000000);
  servo_first.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  servo_second.begin();
  servo_second.setOscillatorFrequency(27000000);
  servo_second.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
};

void Servo::setAll(uint16_t pwm) {
  for(int i = 0; i < 16; i++) {
    servo_first.setPWM(i, 0, pwm);
  }
  for(int i = 0; i < 16; i++) {
    servo_second.setPWM(i, 0, pwm);
  }
}

void Servo::walk() {

}

void Servo::stop() {
  setAll(2048);
}