int pinArray[8];

void setup() {
  // put your setup code here, to run once:

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
  Serial.println(intToByte(45,3), BIN);
  intToIO(intToByte(45,3));
  delay(2000);

}
