#ifndef COLL_AOC_RUNNER_AOC_DELIMITER_H
#define COLL_AOC_RUNNER_AOC_DELIMITER_H

struct AoCDelimiter
{
    int year;
    int day;
    int part;

    explicit AoCDelimiter(int year = -1, int day = -1, int part = -1): year(year), day(day), part(part) {}
};

#endif
