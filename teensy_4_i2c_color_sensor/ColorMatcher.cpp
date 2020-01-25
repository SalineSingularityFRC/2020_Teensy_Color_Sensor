//
// Created by Joshua on 1/24/2020.
//

#include "include/ColorMatcher.h"
//#include <cmath>

//Constructor to create an instance of a ColorMatcher class
ColorMatcher::ColorMatcher(double **colorTargets){
    //You should store the two dimensional array of color targets
    //inside the private variable of the same name
    private double colorTarget[][] = **colorTargets;
}

//Find distance between two points in three dimensional space
double ColorMatcher::distance3d(double *pointOne, double *pointTwo){
    //There are two parameters taken as inputs to this function
    //You turn them into arrays, where the point (x,y,z) corresponds to the 0th 1st and 2nd index of each array
    double point1[] = {pointOne};
    double point2[] = {pointTwo};
    //Then use this function to get a total distance between the points and return it:
    //https://sciencing.com/euclidean-distance-7829754.html
  return sqrt((pow((point1[0] - point2[0]), 2)) + (pow((point1[1] - point2[1]), 2)) + (pow((point1[2] - point2[2]), 2)));
    
}
int ColorMatcher::matchColor(double *color){
    //Loop through each of the colorTargets you stored earlier and check the distance between the color input and
    //each color in the array to find their distance, return the index of the closest color
    for(int r = 0; r < colorTarget.length; r++){
      for(int c = 0; c < colorTarget[r].length; c++){
        return distance3d(colorTarget[r][c], color);
      }
    }

      
}
