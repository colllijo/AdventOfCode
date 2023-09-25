#ifndef COLL_ADVENT_OF_CODE_DAY_H
#define COLL_ADVENT_OF_CODE_DAY_H

#include "coll-aoc-runner/aoc_day.h"

class Day: public AoCDay {
public:
    Day();
    ~Day();

    string part1(const string &input) override;
    string part2(const string &input) override;
};

#endif
