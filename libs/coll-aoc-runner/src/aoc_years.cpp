#include "aoc_years.h"

AoCYears::AoCYears() = default;

AoCYears::~AoCYears()
{
    // Delete all the years
    for (auto &year : years)
    {
        delete year.second;
    }
    years.clear();
}

void AoCYears::setYear(int year, AoCDays *aocDays)
{
    years[year] = aocDays;
}

AoCDays *AoCYears::getYear(int year)
{
    return years[year];
}

void AoCYears::setDay(int year, int day, AoCDay *aocDay)
{
    if (years[year] == nullptr)
    {
        years[year] = new AoCDays();
    }
    years[year]->setDay(day, aocDay);
}

AoCDay *AoCYears::getDay(int year, int day)
{
    if (years[year] != nullptr) {
        return years[year]->getDay(day);
    }
    return nullptr;
}

vector<int> AoCYears::getYears()
{
    vector<int> yearValues;

    for (auto &year : years)
    {
        yearValues.push_back(year.first);
    }

    return yearValues;
}
