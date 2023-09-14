#include "day1.h"

Day1_2015::Day1_2015():AoCDay(2015, 1)
{
}

Day1_2015::~Day1_2015() = default;

std::string Day1_2015::part1(std::string* input)
{
    int floor = 0;

    for (auto &c : *input)
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

std::string Day1_2015::part2(std::string* input)
{
    int floor = 0;
    int charIndex = 0;
    for (auto &c : *input)
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
