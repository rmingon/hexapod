#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>
#include <Led.h>

Led led1(32);

#define SERVO_FREQ 50

void setup() {
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");

  servoInit();

  led1.init();
  led1.on();

  servoSetAll(0);

  delay(2000);

  servoSetAll(2048);

  delay(10);

}

void loop() {

}