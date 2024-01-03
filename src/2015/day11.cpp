#include "day11.h"

Day11_2015::Day11_2015():AoCDay(2015, 11)
{
}

Day11_2015::~Day11_2015() = default;

void incrementPassword(string& input)
{
    int index = input.length() - 1;
    if (input.at(index) == 'z')
    {
        do
        {
            input.at(index) = 'a';
            input.at(index - 1) = input.at(index - 1) + 1;
            index--;
        } while (input.at(index) == 123);
    }
    else
    {
        input.at(index) = input.at(index) + 1;
    }
}

bool validatePassword(const string& password)
{
    bool street = false;
    int pairDelimiter = 0;
    int pairs = 0;

    for (size_t i = 0; i < password.length(); i ++)
    {
        // Bad chars
        if (password.at(i) == 'i' || password.at(i) == 'o' || password.at(i) == 'l')
            return false;

        // Street check
        if ((i + 2) < password.length())
            if (password.at(i) + 1 == password.at(i + 1) && password.at(i + 1) + 1 == password.at(i + 2))
                street = true;

        // Pair
        if (i >= pairDelimiter && (i + 1) < password.length())
            if (password.at(i) == password.at(i + 1))
            {
                pairDelimiter = (int) (i + 2);
                pairs++;
            }
    }

    return street && pairs >= 2;
}

string Day11_2015::part1(const string &input, bool example)
{
    string password = aoc_string::split(input, "\n").at(0);

    do
    {
        incrementPassword(password);
    } while (!validatePassword(password));

    return password;
}

string Day11_2015::part2(const string &input, bool example)
{
    string password = part1(input, example);

    do
    {
        incrementPassword(password);
    } while (!validatePassword(password));

    return password;
}
