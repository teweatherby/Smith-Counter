// Author: Tyler Weatherby
// Computer Architecture
// March 16, 2017
// A Provided Header File

#ifndef STATS_H
#define STATS_H
#include <iostream>
#include <iomanip>

using namespace std; 


class Stats
{
  public: 
    Stats();
    void record_Data(bool actual, bool predicted);

    void reset();
    int	get_total() const;
    int get_total_taken() const;
    int get_taken_correct() const;
    int get_taken_incorrect() const;	// number actually taken but predicted incorrectly
    int get_total_notTaken() const;
    int get_notTaken_correct() const;
    int get_notTaken_incorrect() const;	// number actually taken but predicted incorrectly
    friend std::ostream& operator<< (std::ostream&, const Stats&);

  protected:
    int total;
    int total_taken;
    int total_taken_predicted_correctly;
    int total_notTaken;
    int total_notTaken_predicted_correctly;
};

#endif
