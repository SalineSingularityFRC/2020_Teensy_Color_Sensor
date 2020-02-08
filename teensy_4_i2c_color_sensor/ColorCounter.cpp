#include "include/ColorMatcher.h"
#include "include/ColorSensor.h"
#include "include/CircularBuffer.h"
#include "include/ColorCounter.h"
#include <Arduino.h>

//Constructor of ColorCounter Class
ColorCounter::ColorCounter(){
    this->totalColor = 0;
    this->prevColor = 0;
}

//Increases counter (totalColor) when it sees next expected Color
int ColorCounter::colorCount(int currentColor){
  if(currentColor == (this->prevColor + 1)){
    this->totalColor++;
    this->prevColor = currentColor;
  }
  if(this->prevColor == 3 && currentColor == 0) {
    this->totalColor++;
    this->prevColor = currentColor;
  }
  Serial.println(this->prevColor);
  return this->totalColor;
}
