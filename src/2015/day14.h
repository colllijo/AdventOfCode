#ifndef COLL_ADVENT_OF_CODE_DAY_14_2015_H
#define COLL_ADVENT_OF_CODE_DAY_14_2015_H

#include "coll-aoc-runner/aoc_day.h"

class Day14_2015: public AoCDay {
public:
    Day14_2015();
    ~Day14_2015();

    string part1(const string &input, bool example) override;
    string part2(const string &input, bool example) override;
};

#endif
