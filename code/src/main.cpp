#include <Arduino.h>
#include <Wire.h>
#include <Servo.h>
#include <Led.h>
#include <Lidar.h>
#include "WiFi.h"
#include "AsyncUDP.h"
#include "Conf.h"

Led led1 = Led(32);
Led led2 = Led(33);

Lidar lidar = Lidar();

Servo servo = Servo();

HardwareSerial SerialPort(2);

AsyncUDP udp;

void setup() {
  Serial.begin(115200);
  SerialPort.begin(128000, SERIAL_8N1, 16, 17);
  led2.init();
  led1.init();
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASS);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
      Serial.println("WiFi Failed");
      while(1) {
          delay(1000);
      }
  }
  if(udp.listen(1234)) {
      Serial.print("UDP Listening on IP: ");
      Serial.println(WiFi.localIP());
      udp.onPacket([](AsyncUDPPacket packet) {
          Serial.print("UDP Packet Type: ");
          Serial.print(packet.isBroadcast()?"Broadcast":packet.isMulticast()?"Multicast":"Unicast");
          Serial.print(", From: ");
          Serial.print(packet.remoteIP());
          Serial.print(":");
          Serial.print(packet.remotePort());
          Serial.print(", To: ");
          Serial.print(packet.localIP());
          Serial.print(":");
          Serial.print(packet.localPort());
          Serial.print(", Length: ");
          Serial.print(packet.length());
          Serial.print(", Data: ");
          Serial.write(packet.data(), packet.length());
          Serial.println();
          //reply to the client
          packet.printf("Got %u bytes of data", packet.length());
      });
      led1.on();
  }
  led2.on();

  servo.init();

  lidar.init();

  servo.setAll(400);

  delay(2000);

  servo.setAll(2048);

  delay(10);

  lidar.start();

  delay(2000);
  
  lidar.rotationSpeed(255);
}

void loop() {

      String number = SerialPort.readString();
      Serial.println(number);
    
}