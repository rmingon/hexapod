#include <Arduino.h>
#include <Wire.h>
#include <Servo.h>
#include <Led.h>
#include <Lidar.h>

Led led1(32);
Led led2(33);

Lidar lidar;

HardwareSerial SerialPort(2);

void setup() {
  Serial.begin(115200);

  SerialPort.begin(128000, SERIAL_8N1, 16, 17);

  servoInit();

  lidar.init();

  led1.init();
  led1.on();

  servoSetAll(400);

  delay(2000);

  servoSetAll(2048);

  delay(10);

  lidar.start();

  delay(2000);
  
  lidar.rotationSpeed(255);
}

void loop() {

      String number = SerialPort.readString();
      Serial.println(number);
    
}