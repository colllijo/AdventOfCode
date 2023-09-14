#ifndef COLL_AOC_RUNNER_AOC_DAYS_H
#define COLL_AOC_RUNNER_AOC_DAYS_H

#include <map>
#include <vector>

#include "aoc_day.h"

using namespace std;

class AoCDays {
private:
    map<int, AoCDay*> days;
public:
    AoCDays();
    ~AoCDays();

    void setDay(int day, AoCDay* aocDay);
    AoCDay *getDay(int day);
    vector<int> getDays();
};


#endif
