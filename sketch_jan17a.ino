#include "libraries/CircularBuffer/CircularBuffer.h"

CircularBuffer test(20);
void setup() {
  // put your setup code here, to run once:           
  Serial.begin(38400);
}

  
//calculating the average
// Color average(double currentColor, previousColor){
//  color() colors[size];
//  int number = 0;
//  for(int i = 0; i <= size; i++){
//    colors[i] = currentColor;
//    previousColor = currentColor;
//    
//  }
//  for(int i = 0; i < size + 1; i++){
//    number += color[i];
//    
//  }
//  average = number/size;
//  //update for loop
//  
//}

  
// color(double r, g , b){
//  double red = r;
//  double green = g; 
//  double blue = b;
//}
//}


void loop() {
  // put your main code here, to run repeatedly:
  
//Serial.println("Hello World");
  delay(1000);

test.newColor(10);
Serial.println(test.getAverageColor());

  
}
