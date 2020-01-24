//
// Created by Joshua on 1/24/2020.
//

#include "include/ColorMatcher.h"

//Constructor to create an instance of a ColorMatcher class
ColorMatcher::ColorMatcher(double **colorTargets){
    //You should store the two dimensional array of color targets
    //inside the private variable of the same name
}

//Find distance between two points in three dimensional space
double ColorMatcher::distance3d(double *pointOne, double *pointTwo){
    //There are two parameters taken as inputs to this function
    //You turn them into arrays, where the point (x,y,z) corresponds to the 0th 1st and 2nd index of each array
    //Then use this function to get a total distance between the points and return it:
    //https://sciencing.com/euclidean-distance-7829754.html
}
int ColorMatcher::matchColor(double *color){
    //Loop through each of the colorTargets you stored earlier and check the distance between the color input and
    //each color in the array to find their distance, return the index of the closest color
}

