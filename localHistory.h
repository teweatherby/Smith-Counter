#pragma once
// Author: Tyler Weatherby
// Computer Architecture
// April 10, 2017
// Header file modeled from SmithCounter.h

#ifndef LocalHistory_H
#define LocalHistory_H
#include <fstream>

class LocalHistory
{
public:
	LocalHistory(int bits = 4, int initialValue = 0);
	void record_Branch(bool taken);
	void record_Branch_Taken();
	void record_Branch_Not_Taken();
	int	 get_State() const; 
	friend std::ostream& operator<< (std::ostream&, const LocalHistory&);

private:
	int binary_Value;
	int number_Of_Bits;
	int state;
	int mask_Value;	// 2^number_Of_Bits -1  
					// a fast way to mask off unused bits
					// set at creation
};

#endif 
