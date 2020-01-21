#include "libraries/CircularBuffer/CircularBuffer.h"

    
    CircularBuffer::CircularBuffer(int size){
      colorBuffer = new double[size];
      this->size = size;
      index = 0;
      for(int i = 0; i < size; i++){
          colorBuffer[i] = 0 ;
      }
      }
    

    double CircularBuffer::getAverageColor(){
      double number = 0;
      for(int i = 0; i < size; i++){
          number += colorBuffer[i];
         }
       double average = number/(double)size;
       //update for loop
       
       return average;
    }
   void CircularBuffer::newColor(double color){
    colorBuffer[index] = color;
    index += 1;

    if(index >= size ){
      index = 0;
    }
  }
 
