#ifndef COLL_ADVENT_OF_CODE_DAY_25_2023_H
#define COLL_ADVENT_OF_CODE_DAY_25_2023_H

#include "coll-aoc-runner/aoc_day.h"

class Day25_2023: public AoCDay {
public:
    Day25_2023();
    ~Day25_2023();

    string part1(const string &input, bool example) override;
    string part2(const string &input, bool example) override;
};

#endif
