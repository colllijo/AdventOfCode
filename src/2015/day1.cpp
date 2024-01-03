#include "day1.h"

Day1_2015::Day1_2015():AoCDay(2015, 1)
{
}

Day1_2015::~Day1_2015() = default;

string Day1_2015::part1(const string &input, bool example)
{
    int floor = 0;

    for (auto &c : input)
    {
        switch (c)
        {
            case '(':
                floor++;
                break;
            case ')':
                floor--;
                break;
            default:
                break;
        }
    }
    return std::to_string(floor);
}

string Day1_2015::part2(const string &input, bool example)
{
    int floor = 0;
    int charIndex = 0;
    for (auto &c : input)
    {
        charIndex++;

        switch (c)
        {
            case '(':
                floor++;
                break;
            case ')':
                floor--;
                break;
            default:
                break;
        }

        if (floor < 0)
        {
            break;
        }
    }
    return std::to_string(charIndex);
}
