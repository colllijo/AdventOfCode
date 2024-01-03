#ifndef COLL_ADVENT_OF_CODE_DAY_15_2023_H
#define COLL_ADVENT_OF_CODE_DAY_15_2023_H

#include "coll-aoc-runner/aoc_day.h"

class Day15_2023: public AoCDay {
public:
    Day15_2023();
    ~Day15_2023();

    string part1(const string &input, bool example) override;
    string part2(const string &input, bool example) override;
};

#endif
