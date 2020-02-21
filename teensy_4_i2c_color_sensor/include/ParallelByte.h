//
// Created by Travis on 1/31/2020.
//


#include "ColorSensor.h"
#include "ColorCounter.h"
#ifndef ParallelByte_h
#define ParallelByte_h
class ParallelByte{

private:
    int intToByte(int count, int color);
    int intToIO(int data);
    int pinArray[9];

public:
    void sendData(int count, int color);
    void init(int pinArray[9]);
    ParallelByte(){};
    void checkReset(ColorCounter * colorCount);
};
#endif