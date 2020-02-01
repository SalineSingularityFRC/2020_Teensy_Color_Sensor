//
// Created by Travis on 1/31/2020.
//


#ifndef APDS9151_h
#define APDS9151_h
class APDS9151{

private:
    uint32_t To20Bit(uint8_t *val);

public:
    int getData(int rgb[3])[3];
	APDS9151(int power, int gnd, int scl, int sda);
};
#endif