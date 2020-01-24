#ifndef CircularBuffer_h
#define CircularBuffer_h
class CircularBuffer{
 
   private:
    int index;
    double * colorBuffer; 
    int size;
    
   public:
    CircularBuffer(int size);
    double getAverageColor();    
	void newColor(double color);
 };
#endif