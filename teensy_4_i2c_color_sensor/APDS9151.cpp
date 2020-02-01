//
// Created by Travis on 1/31/2020.
//

#include "include/APDS9151.h"
#include <Arduino.h>
#include <Wire.h> 

void APDS9151::init(int power, int gnd, int scl, int sda){
  //initialize and start power pins
  pinMode(power, OUTPUT);
  digitalWrite(power, HIGH);  
  pinMode(gnd, OUTPUT);
  digitalWrite(gnd, LOW);

  //initialize and set i2c pins
  Wire.setSDA(sda);
  Wire.setSCL(scl);
  Wire.begin();

  //tell the bus what address to listen to
  Wire.beginTransmission(82);
  Wire.write(0);  //Write location
  Wire.write(7);  //0x00
  Wire.write(28); //0x01
  Wire.write(32); //0x02
  Wire.write(28); //0x03
  Wire.write(18); //0x04
  Wire.write(1);  //0x05
  Wire.endTransmission();
}

uint32_t APDS9151::To20Bit(uint8_t *val) {
    return (static_cast<uint32_t>(val[0]) |
           (static_cast<uint32_t>(val[1]) << 8)|   
           (static_cast<uint32_t>(val[2]) << 16)) &
           0x03FFFF;
}

int APDS9151::getData(int rgb[3])[3]{
  Wire.beginTransmission(82);
  Wire.write(0x0d);  //Read Location
  Wire.endTransmission();
  Wire.requestFrom(82, 9);
  byte raw[9];
  for(int i = 0; i < 9; i++){
    raw[i] = Wire.read();
  }
  uint32_t green = To20Bit(raw); //First three bytes
  uint32_t blue= To20Bit(raw + 3); //Second three bytes
  uint32_t red = To20Bit(raw + 6); //Last three byes

  Serial.print(red); Serial.print(","); Serial.print(green); Serial.print(","); Serial.println(blue);
  rgb[0] = red;
  rgb[1] = green;
  rgb[2] = blue;

  return rgb;
}
