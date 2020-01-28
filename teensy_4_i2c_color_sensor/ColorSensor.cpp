//
// Created by Joshua on 1/24/2020.
//

#include "include/ColorMatcher.h"
#include "include/ColorSensor.h"
#include "include/CircularBuffer.h"

//Constructor to create an instance of a ColorSensor class
ColorSensor::ColorSensor(int size, double colorTargets[4][3]):red(size),blue(size),green(size), color(colorTargets){
    //You should initialize each ColorBuffer in here: red, green, and blue
    
}

//Convert raw data to doubles we can use
double * ColorSensor::convertColor(int rawColor[3]){
    //This function will take raw data (Three integers) from a color sensor and turn it into three percentages
    //In total, your three doubles should add up to 1.0
    double color[3];
    color[0] = rawColor[0];
    color[1] = rawColor[1];
    color[2] = rawColor[2];
    double total = color[0] + color[1] + color[2];
    double percentColor[3] = {(color[0]/total),(color[1]/total), (color[2]/total)};
    return percentColor;
    
}

int ColorSensor::senseColor(int *rawColor) {
    //You should use call the convertColor() message from here to turn it into colors and then put each
    //of the colors into their respective CircularBuffer using the newColor() method. 
    
    return color.matchColor(convertColor(rawColor));
    
    //Once that is done
    //you can get a resulting color from the getAverageColor() method. You should be able to throw those three
    //colors into an array and use the ColorMatcher's matchColor() method to get a color integer and return it
    
}
