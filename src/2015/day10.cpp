#include "day10.h"

Day10_2015::Day10_2015():AoCDay(2015, 10)
{
}

Day10_2015::~Day10_2015() = default;

string lookAndSay(const string &input)
{
    string result;

    int repetitions = 0;
    char currentDigit;

    for (const auto &c : input)
    {
        if (!isdigit(c))
            break;

        if (currentDigit != c)
        {
            if (repetitions != 0)
                result += to_string(repetitions) + currentDigit;

            currentDigit = c;
            repetitions = 1;
        }
        else
            repetitions++;
    }

    return result + to_string(repetitions) + currentDigit;
}

string Day10_2015::part1(const string &input, bool example)
{
    string result = input;

    for (int i = 0; i < 40; i++)
        result = lookAndSay(result);

    return to_string(result.length());
}

string Day10_2015::part2(const string &input, bool example)
{
    string result = input;

    for (int i = 0; i < 50; i++)
        result = lookAndSay(result);

    return to_string(result.length());
}
