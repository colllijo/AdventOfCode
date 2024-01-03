#include "day5.h"

#include <regex>

Day5_2015::Day5_2015():AoCDay(2015, 5)
{
}

Day5_2015::~Day5_2015() = default;

string Day5_2015::part1(const string &input, bool example)
{
    int goodStrings = 0;

    std::stringstream stream (input);
    std::string string;
    while (std::getline(stream, string, '\n'))
    {
        int vowelsCount = 0;
        bool doubledLetter = false;
        bool badPair = false;
        char prevChar = '\0';

        for (auto &c : string)
        {
            // Check for vowels
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                vowelsCount++;

            // Check for doubles
            if (c == prevChar)
                doubledLetter = true;

            // Check for bad strings
            switch (prevChar)
            {
                case 'a':
                    badPair = c == 'b';
                    break;
                case 'c':
                    badPair = c == 'd';
                    break;
                case 'p':
                    badPair = c == 'q';
                    break;
                case 'x':
                    badPair = c == 'y';
                    break;
                default:
                    break;
            }

            if (badPair)
                break;

            prevChar = c;
        }

        if (badPair)
            continue;

        if (vowelsCount >= 3 && doubledLetter)
            goodStrings++;
    }

    return to_string(goodStrings);
}

string Day5_2015::part2(const string &input, bool example)
{
    int goodStrings = 0;

    std::stringstream stream (input);
    std::string string;
    while (std::getline(stream, string, '\n'))
    {
        if (regex_match(string, regex(".*(?=.*(..).*\\1).*(?=(.).\\2).*")))
            goodStrings++;
    }

    return to_string(goodStrings);
}
