#ifndef COLL_AOC_RUNNER_AOC_DAY_H
#define COLL_AOC_RUNNER_AOC_DAY_H

#include <iostream>
#include <numeric>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <vector>

#include "crypto/aoc_md5.h"
#include "string/aoc_string.h"
#include "structures/aoc_2d_grid.h"

using namespace std;

class AoCDay {
protected:
    int year;
    int day;
public:
    AoCDay(int year, int day);
    ~AoCDay();

    [[nodiscard]] int getYear() const { return year; }
    [[nodiscard]] int getDay() const { return day; }

    virtual std::string part1(const string &input, bool example);
    virtual std::string part2(const string &input, bool example);

    string exampleInput{};
    void setExampleInput(const string& example) { exampleInput = example; };
};

#endif
