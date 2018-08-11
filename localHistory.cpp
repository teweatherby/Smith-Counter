// Author: Tyler Weatherby
// Computer Architecture
// April 10, 2017

#include "localHistory.h"
#include <iostream>

LocalHistory::LocalHistory(int bits, int initialvalue)
{
	number_Of_Bits = bits;
	state = initialvalue;
	mask_Value = pow(2, number_Of_Bits) - 1;
}
void LocalHistory::record_Branch(bool taken)
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
void LocalHistory::record_Branch_Taken()
{
	// If branch is taken shift right, and add one.
	state = state << 1;
	state += 1;
	// If state > mask_Value then discard leading bit
	if (state > mask_Value)
	{
		state -= pow(2, number_Of_Bits);
	}
}
void LocalHistory::record_Branch_Not_Taken()
{
	// If Branch not taken, just shift right
	state = state << 1;
	// If state > mask_Value then discard leading bit
	if (state > mask_Value)
	{
		state -= pow(2, number_Of_Bits);
	}
}
int LocalHistory::get_State() const
{
	return state;
}
std::ostream& operator<< (std::ostream& out, const LocalHistory& local)
{
	out << local.get_State();
	return out;
}