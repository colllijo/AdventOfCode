#ifndef COLL_ADVENT_OF_CODE_DAY_H
#define COLL_ADVENT_OF_CODE_DAY_H

#include "coll-aoc-runner/aoc_day.h"

class Day: public AoCDay {
public:
    Day();
    ~Day();

    std::string part1(std::string* input) override;
    std::string part2(std::string* input) override;
};

#endif
