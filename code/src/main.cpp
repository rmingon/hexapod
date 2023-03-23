#include <Arduino.h>
#include <Wire.h>
#include <Servo.h>
#include <Led.h>

Led led1(32);
Led led2(33);

int lidar_motor = 26;
int lidar_motor_speed = 37;

void setup() {
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");

Serial1.begin(128000);


  servoInit();

  pinMode(lidar_motor, OUTPUT);
  digitalWrite(lidar_motor, LOW);

  pinMode(lidar_motor_speed, OUTPUT);
  digitalWrite(lidar_motor_speed, LOW);

  led1.init();
  led1.on();

  servoSetAll(400);

  delay(2000);

  servoSetAll(2048);

  delay(10);

}

void loop() {

}