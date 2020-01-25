//
// Created by Joshua on 1/24/2020.
//
#include "CircularBuffer.h"
#include "ColorMatcher.h"

#ifndef ColorSensor_h
#define ColorSensor_h
class ColorSensor{

private:
    CircularBuffer red;
    CircularBuffer green;
    CircularBuffer blue;
    double convertColor(int rawColor[3])[3];

public:
    ColorMatcher();
    int senseColor(int rawColor[3]);

};
#endif
