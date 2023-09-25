#ifndef COLL_AOC_RUNNER_AOC_DAY_H
#define COLL_AOC_RUNNER_AOC_DAY_H

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

#include "crypto/aoc_md5.h"
#include "string/aoc_string.h"

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

    virtual std::string part1(const string &input);
    virtual std::string part2(const string &input);
};

#endif
