//
// Created by Joshua on 1/24/2020.
//

#ifndef ColorMatcher_h
#define ColorMatcher_h
class ColorMatcher{

private:
    double * colorTargets[3];
    double distance3d(double pointOne[3], double pointTwo[3]);

public:
    ColorMatcher(double * colorTargets[]);
    int matchColor(double color[3]);

};
#endif
