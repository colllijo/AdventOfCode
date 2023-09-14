#include "aoc_days.h"

AoCDays::AoCDays() = default;

AoCDays::~AoCDays()
{
    // Delete all the days
    for (auto &day : days)
    {
        delete day.second;
    }
    days.clear();
}

void AoCDays::setDay(int day, AoCDay *aocDay)
{
    days[day] = aocDay;
}

AoCDay *AoCDays::getDay(int day)
{
    return days[day];
}

vector<int> AoCDays::getDays()
{
    vector<int> dayValues;

    for (auto &day : days)
    {
        dayValues.push_back(day.first);
    }

    return dayValues;
}
