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
    double * convertColor(int rawColor[3], double percentColor[3]);
    ColorMatcher color;

public:
    ColorSensor(int size, double colorTargets[4][3]);
    int senseColor(int rawColor[3]);

};
#endif