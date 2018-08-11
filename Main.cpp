// Author: Tyler Weatherby
// Computer Architecture
// March 16, 2017

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "SmithCounter.h"
#include "Stats.h"
#include "globalHistory.h"
#include "localHistory.h"

using namespace std;

int main()
{
	const int number_smith_elements = 128; // Constant int for the number of Smith Counters
	SmithCounter smith_array[number_smith_elements]; // Array to hold Smith Counters
	Stats stats; // Statistics object
	GlobalHistory global_history; // global history register with 3 bits
	LocalHistory local_history[4]; // Local History with 4 entries, each has a BHR of 4 bits.
	string filename = "branchpred.dat";
	ifstream infile(filename); 
	int address = 0; // Variable to hold addresses
	char branch = 'A'; // Variable to hold whether the branch was taken or not taken

	// Take in the address and branch
	while (infile >> address >> branch)
	{
		// Get the index of the smith counter
		address = address % number_smith_elements;
		// Get the state of the Smith Counter at the new address (index)
		smith_array[address].get_State();
		
		if (branch == 'T')
		{
			// Record data branch == 'T'
			stats.record_Data(1, smith_array[address].get_Prediction());
			// Change object states
			smith_array[address].record_Branch_Taken();
			global_history.record_Branch_Taken();
		}
		else
		{
			// Record data branch == 'F'
			stats.record_Data(0, smith_array[address].get_Prediction());
			// Change Object states
			smith_array[address].record_Branch_Not_Taken();
			global_history.record_Branch_Not_Taken();		
		}
	}

	cout << stats << endl;


	return 0;
}