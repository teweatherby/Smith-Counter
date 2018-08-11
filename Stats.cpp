// Author: Tyler Weatherby
// Computer Architecture
// March 16, 2017

#include "Stats.h"
// This default constructor calls a method that sets all values to zero initially.
Stats::Stats()
{
	reset();
}
// This method takes in the actual, predicted. It will increment the values accordingly.
void Stats::record_Data(bool actual, bool predicted)
{
	total += 1; // For each branch we add one to the total
	if (actual == 1) // If we took the branch
	{
		total_taken += 1;
		if (predicted == 1) // If we took the branch and were correct
		{
			total_taken_predicted_correctly += 1;
		}
	}
	if (actual == 0) // If we did not take the branch
	{
		total_notTaken += 1;
		if (predicted == 0) // If we did not take the branch and were correct
		{
			total_notTaken_predicted_correctly += 1;
		}
	}
}
// Sets all statistical values to zero.
void Stats::reset()
{
	total = 0;
	total_taken = 0;
	total_taken_predicted_correctly = 0;
	total_notTaken = 0;
	total_notTaken_predicted_correctly = 0;
}
// Returns the total number of branches taken
int	Stats::get_total() const
{
	return total;
}
// Return the total branches that were taken
int Stats::get_total_taken() const
{
	return total_taken;
}
// Return the total taken that were correct
int Stats::get_taken_correct() const
{
	return total_taken_predicted_correctly;
}
// Return the number actually taken but predicted incorrectly
int Stats::get_taken_incorrect() const 
{
	return (total_taken - total_taken_predicted_correctly);
}
// Return the total number of branches not taken
int Stats::get_total_notTaken() const
{
	return total_notTaken;
}
// Return the number of branches that were not taken and correct
int Stats::get_notTaken_correct() const
{
	return total_notTaken_predicted_correctly;
}
// Return the number actually not taken but predicted incorrectly
int Stats::get_notTaken_incorrect() const 
{
	return (total_notTaken - total_notTaken_predicted_correctly);
}
// This outputs all statistics.
std::ostream& operator<< (std::ostream& out, const Stats& stat)
{
	double perc = 0;
	out << "Total: " << stat.get_total() << endl;
	out << "Total Taken: " << stat.get_total_taken() << endl;
	out << "Total Taken Correct: " << stat.get_taken_correct() << endl;
	out << "Total Taken Not Correct: " << stat.get_taken_incorrect() << endl << endl;
	out << "Total Not Taken: " << stat.get_total_notTaken() << endl;
	out << "Total Not Taken Correct: " << stat.get_notTaken_correct() << endl;
	out << "Total Not Taken Not Correct: " << stat.get_notTaken_incorrect() << endl << endl;
	perc = ((double)stat.get_notTaken_correct() + stat.get_taken_correct())/stat.get_total();
	cout << "Overall rate of correct predictions: " << setprecision(4) << (perc * 100) << "%" << endl;
	return out;
}