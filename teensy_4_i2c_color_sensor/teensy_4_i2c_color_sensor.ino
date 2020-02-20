  #include <Wire.h>
#include "include/ColorSensor.h"
#include "include/ColorMatcher.h"
#include "include/ColorCounter.h"
#include "include/ParallelByte.h"
#include "include/APDS9151.h"


int pinArray[9] = {12, 11, 10, 9, 7, 5, 4, 3, 1};

// Converts 20 binary bits to an integer, where the last bit of the first byte is the least significant
// and only the last four bits of the last bytes is used
//eg.
// 00101101 01101011 00000101
// is translated to this in binary
// 0101 01101011 00101101
// which is 355117 in decimal
double targets[4][3] = {{0.143, 0.427, 0.429},{0.197, 0.561, 0.240},{0.561, 0.232, 0.114},{0.361, 0.524, 0.113}};
ColorSensor colorSensor(20, targets);
ColorCounter colorCounter;

APDS9151 colorV3;
ParallelByte teensyToRIO;

void setup() {
  Serial.begin(9600);
  delay(10000);
  // put your setup code here, to run once:
  /*Serial.begin(9600);
  colorV3.init(21,20,19,18);
  Serial.println("Enabled LED");  

  delay(1000);
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
  pinMode(pinArray[7], OUTPUT);*/
  //Serial.begin(9600);



  /*Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);*/

  pinMode(13, OUTPUT);
  
  colorV3.init(20, 21, 19, 18);
  teensyToRIO.init(pinArray);
  Serial.println("Enabled Color Sensor!");
  
}

/*int intToByte(int count, int color){ // color is th 2 bits, 4 numbers total (0,1,2,3)
  return ((count & 0x3f) + (color << 6)) & 0xff;
}

int intToIO(int data){
  for(int i = 0; i < 8; i++){
    ((data>>i)%2) == 1 ? digitalWrite(pinArray[i], HIGH): digitalWrite(pinArray[i], LOW);
  }
}*/

void loop() {
  // put your main code here, to run repeatedly:
  int rgb[3];
  colorV3.getData(rgb);
  Serial.println("Trying to get data... ");
  int currentColor = colorSensor.senseColor(rgb);
  int totalColor = colorCounter.colorCount(currentColor);
  teensyToRIO.sendData(totalColor, currentColor);
  teensyToRIO.checkReset(colorCounter);
  Serial.println(currentColor);
  Serial.println(totalColor);
  Serial.println("Trying to Send Data... ");
  if(currentColor == 1) {
    digitalWrite(13, HIGH);
  }
  else {
    digitalWrite(13, LOW);
  }
  Serial.println("End of Loop");
  delay(10);
  

}
