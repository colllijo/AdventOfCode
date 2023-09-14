#ifndef COLL_AOC_RUNNER_AOC_RUNNER_H
#define COLL_AOC_RUNNER_AOC_RUNNER_H

#include <map>
#include <functional>

#include "aoc_day.h"
#include "aoc_delimiter.h"
#include "aoc_input.h"
#include "aoc_years.h"

using namespace std;

class AoCRunner {
private:
    AoCYears* aocYears;
    AoCInput* aocInput;

    map<int, AoCDay*> getDaysToRun(AoCDelimiter* delimiter);
    static void runPart(AoCDelimiter delimiter, const string &result);
public:
    explicit AoCRunner(const function<void(AoCYears*)>& setYears);
    ~AoCRunner();

    void run(AoCDelimiter *delimiter);
};

#endif
