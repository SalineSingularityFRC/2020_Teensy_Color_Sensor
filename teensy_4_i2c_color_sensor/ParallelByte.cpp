//
// Created by Travis on 1/31/2020.
//
#include "include/ParallelByte.h"
#include "include/ColorSensor.h"
#include "include/ColorCounter.h"
#include <Arduino.h>

void ParallelByte::init(int pinArray[9]){
  for(int i = 0; i < 9; i++){
    this->pinArray[i] = pinArray[i];
  }

  
  pinMode(pinArray[0], OUTPUT);
  pinMode(pinArray[1], OUTPUT);
  pinMode(pinArray[2], OUTPUT);
  pinMode(pinArray[3], OUTPUT);
  pinMode(pinArray[4], OUTPUT);
  pinMode(pinArray[5], OUTPUT);
  
  pinMode(pinArray[6], OUTPUT);
  pinMode(pinArray[7], OUTPUT);
  pinMode(pinArray[8], INPUT);
}

int ParallelByte::intToByte(int count, int color){ // color is th 2 bits, 4 numbers total (0,1,2,3)
  return ((count & 0x3f) + (color << 6)) & 0xff;
}

int ParallelByte::intToIO(int data){
  for(int i = 0; i < 8; i++){
    ((data>>i)%2) == 1 ? digitalWrite(this->pinArray[i], HIGH): digitalWrite(this->pinArray[i], LOW);
  }
}

void ParallelByte::sendData(int count, int color){
  intToIO(intToByte(count, color));
}

void ParallelByte::checkReset(ColorCounter colorCount){
  if( this->pinArray[8] == HIGH) {
    colorCount.resetCount();
    Serial.println("RESET REQUESTED");
  }
}
