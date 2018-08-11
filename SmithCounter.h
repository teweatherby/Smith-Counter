// Author: Tyler Weatherby
// Computer Architecture
// March 16, 2017
// A Provided Header File

#ifndef SmithCounter_H
#define SmithCounter_H
#include <fstream>

class SmithCounter 
{
  public:
	SmithCounter(int bits=2, int initialValue=0);
    void record_Branch(bool taken);
    void record_Branch_Taken();
    void record_Branch_Not_Taken();
    bool get_Prediction() const;
    int	 get_State() const;
    friend std::ostream& operator<< (std::ostream&, const SmithCounter&);

  private:
    int number_Of_Bits;
    int state;
    int mask_Value;	// 2^number_Of_Bits -1  
			// a fast way to mask off unused bits
			// set at creation
};

#endif 
