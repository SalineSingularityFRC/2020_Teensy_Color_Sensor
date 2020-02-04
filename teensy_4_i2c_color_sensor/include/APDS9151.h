//
// Created by Travis on 1/31/2020.
//

#include <Arduino.h>

#ifndef APDS9151_h
#define APDS9151_h
class APDS9151{

private:
    uint32_t To20Bit(uint8_t *val);

public:
    void getData(int rgb[3]);
	void init(int power, int gnd, int scl, int sda);
	APDS9151(){};
};
#endif