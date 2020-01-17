#include <Wire.h>

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

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(82);
  Wire.write(0x0d);  //Read Location
  Wire.endTransmission();
  Wire.requestFrom(82, 9);
  byte raw[9];
  for(int i = 0; i < 9; i++){
    raw[i] = Wire.receive();
  }
  uint32_t green = To20Bit(raw); //First three bytes
  uint32_t blue= To20Bit(raw + 3); //Second three bytes
  uint32_t red = To20Bit(raw + 6); //Last three byes
  /*Serial.print("R: ");
  Serial.println(red);
  Serial.print("G: ");
  Serial.println(green);
  Serial.print("B: ");
  Serial.println(blue);*/

  Serial.print(red); Serial.print(","); Serial.print(green); Serial.print(","); Serial.println(blue);
  delay(10);
  /*Wire.beginTransmission(4); 
  for(int ii = 0; ii < 9; ii++){ 
    Wire.write(raw[ii]);
  }
  Wire.endTransmission();*/

}
