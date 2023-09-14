#ifndef COLL_AOC_RUNNER_AOC_DAY_H
#define COLL_AOC_RUNNER_AOC_DAY_H

#include <iostream>
#include <string>

class AoCDay {
protected:
    int year;
    int day;
public:
    AoCDay(int year, int day);
    ~AoCDay();


    void setYear(const int value) { year = value; }
    int getYear() const { return year; }

    void setDay(const int value) { day = value; }
    int getDay() const { return day; }

    virtual std::string part1(std::string* input);
    virtual std::string part2(std::string* input);
};

#endif
