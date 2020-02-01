#include <Wire.h>
#include "include/ColorSensor.h"
#include "include/ColorMatcher.h"
#include "include/ColorCounter.h"

int pinArray[8];

// Converts 20 binary bits to an integer, where the last bit of the first byte is the least significant
// and only the last four bits of the last bytes is used
//eg.
// 00101101 01101011 00000101
// is translated to this in binary
// 0101 01101011 00101101
// which is 355117 in decimal
uint32_t To20Bit(uint8_t *val) {
    return (static_cast<uint32_t>(val[0]) |
           (static_cast<uint32_t>(val[1]) << 8)|   
           (static_cast<uint32_t>(val[2]) << 16)) &
           0x03FFFF;
}
double targets[4][3] = {{0.143, 0.427, 0.429},{0.197, 0.561, 0.240},{0.561, 0.232, 0.114},{0.361, 0.524, 0.113}};
ColorSensor colorSensor(20, targets);
ColorCounter colorCounter;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(20, OUTPUT);
  digitalWrite(20, HIGH);  
  pinMode(21, OUTPUT);
  digitalWrite(21, LOW);
  Serial.println("Enabled LED");  

  delay(1000);
  Wire.begin();
  Serial.println("Enabled I2C Bus");

  pinArray[0] = 1;
  pinArray[1] = 2;
  pinArray[2] = 3;
  pinArray[3] = 4;
  pinArray[4] = 5;
  pinArray[5] = 6;
  pinArray[6] = 7;
  pinArray[7] = 8;
  
  pinMode(pinArray[0], OUTPUT);
  pinMode(pinArray[1], OUTPUT);
  pinMode(pinArray[2], OUTPUT);
  pinMode(pinArray[3], OUTPUT);
  pinMode(pinArray[4], OUTPUT);
  pinMode(pinArray[5], OUTPUT);
  
  pinMode(pinArray[6], OUTPUT);
  pinMode(pinArray[7], OUTPUT);
  Serial.begin(9600);



  /*Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);*/

  Wire.beginTransmission(82);
  Wire.write(0);  //Write location
  Wire.write(7);  //0x00
  Wire.write(28); //0x01
  Wire.write(32); //0x02
  Wire.write(28); //0x03
  Wire.write(18); //0x04
  Wire.write(1);  //0x05
  Wire.endTransmission();
  Serial.println("Enabled Color Sensor!");

  Wire.beginTransmission(4); // transmit to device #4
  Wire.write("Setup Complete");        // sends five bytes  
  Wire.endTransmission();
  
}

int intToByte(int count, int color){ // color is th 2 bits, 4 numbers total (0,1,2,3)
  return ((count & 0x3f) + (color << 6)) & 0xff;
}

int intToIO(int data){
  for(int i = 0; i < 8; i++){
    ((data>>i)%2) == 1 ? digitalWrite(pinArray[i], HIGH): digitalWrite(pinArray[i], LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
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
  int rgb[3] = {(red), (green), (blue)};
  Serial.println(colorSensor.senseColor( rgb ));
  int currentColor = colorSensor.senseColor( rgb );
  int totalColor = colorCounter.colorCount(currentColor);

  intToIO(intToByte(totalColor, currentColor));
  
  Serial.println(totalColor);
  delay(10);
  

}
