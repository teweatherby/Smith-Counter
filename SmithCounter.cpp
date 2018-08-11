// Author: Tyler Weatherby
// Computer Architecture
// March 16, 2017

#include "SmithCounter.h"
#include <iomanip>
#include <iostream>

SmithCounter::SmithCounter(int bits, int initialValue)
{
	number_Of_Bits = bits; // Number of bits in the counter
	state = initialValue; // Counter initial value
	mask_Value = pow(2, number_Of_Bits) - 1; // Mask value (Maximum value)
}
// Record branch will take whether the branch is take or not taken
// And adjust the counter appropriately.
void SmithCounter::record_Branch(bool taken)
{
	if (taken == 1)
	{
		record_Branch_Taken();
	}
	else
	{
		record_Branch_Not_Taken();
	}
}
// Adjusts the object state when branch is taken += 1
void SmithCounter::record_Branch_Taken()
{
	if (state != mask_Value)
	{
		state += 1;
	}
}
// Adjusts the object state when branch is not taken -= 1
void SmithCounter::record_Branch_Not_Taken()
{
	if (state != 0)
	{
		state -= 1;
	}
}
// Will return bool value of the prediction of whether the branch is taken(1) or not taken(0)
bool SmithCounter::get_Prediction() const
{
	if (state == 0 || state == 1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
// Simply returns the state of the Smith Counter
int	 SmithCounter::get_State() const
{
	return state;
}
std::ostream& operator<< (std::ostream& out, const SmithCounter& smith)
{
	out << smith.get_State();
	return out;
}