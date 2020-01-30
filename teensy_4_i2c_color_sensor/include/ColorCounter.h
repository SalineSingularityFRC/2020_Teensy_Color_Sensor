
#include "CircularBuffer.h"
#include "ColorMatcher.h"
#include "ColorSensor.h"

#ifndef ColorCounter_h
#define ColorCounter_h
class ColorCounter{

private:
    int prevColor;
    int totalColor;
public:
    int colorCount(int currentColor);
    ColorCounter();
};
#endif