//
// Created by Travis on 1/31/2020.
//


#ifndef ParallelByte_h
#define ParallelByte_h
class ParallelByte{

private:
    int intToByte(int count, int color);
	int intToIO(int data);
	int pinArray[8];
public:
    void sendData(int count, int color);
	void init(int pinArray[8]);
	ParallelByte(){};
};
#endif