#ifndef COLL_AOC_RUNNER_AOC_YEARS_H
#define COLL_AOC_RUNNER_AOC_YEARS_H

#include <map>
#include <vector>

#include "aoc_days.h"

using namespace std;

class AoCYears {
private:
    map<int, AoCDays*> years;
public:
    AoCYears();
    ~AoCYears();

    void setYear(int year, AoCDays* aocDays);
    AoCDays* getYear(int year);
    vector<int> getYears();

    void setDay(int year, int day, AoCDay* aocDay);
    AoCDay* getDay(int year, int day);
};

#endif
