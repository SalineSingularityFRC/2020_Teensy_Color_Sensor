//
// Created by Travis on 1/31/2020.
//
#include "include/ParallelByte.h"
#include <Arduino.h>

int pinArray[8];

void ParallelByte::init(pinArray){
  pinArray[0] = pin1;
  pinArray[1] = pin2;
  pinArray[2] = pin3;
  pinArray[3] = pin4;
  pinArray[4] = pin5;
  pinArray[5] = pin6;
  pinArray[6] = pin7;
  pinArray[7] = pin8;
  
  pinMode(pinArray[0], OUTPUT);
  pinMode(pinArray[1], OUTPUT);
  pinMode(pinArray[2], OUTPUT);
  pinMode(pinArray[3], OUTPUT);
  pinMode(pinArray[4], OUTPUT);
  pinMode(pinArray[5], OUTPUT);
  
  pinMode(pinArray[6], OUTPUT);
  pinMode(pinArray[7], OUTPUT);
}

int intToByte(int count, int color){ // color is th 2 bits, 4 numbers total (0,1,2,3)
  return ((count & 0x3f) + (color << 6)) & 0xff;
}

int intToIO(int data){
  for(int i = 0; i < 8; i++){
    ((data>>i)%2) == 1 ? digitalWrite(pinArray[i], HIGH): digitalWrite(pinArray[i], LOW);
  }
}

void ParallelByte::sendData(int count, int color){
  intToIO(intToByte(totalColor, currentColor));
}
