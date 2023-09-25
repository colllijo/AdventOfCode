#include "day15.h"

#include <regex>

Day15_2015::Day15_2015():AoCDay(2015, 15)
{
}

Day15_2015::~Day15_2015() = default;

string Day15_2015::part1(const string &input)
{
    map<string, map<string, int>> ingredients;

    stringstream stream (input);
    string ingredient;
    while(getline(stream, ingredient, '\n'))
    {
        smatch matches;

        if (regex_search(ingredient, matches, regex("([A-Za-z]+): capacity (-?[0-9]+), durability (-?[0-9]+), flavor (-?[0-9]+), texture (-?[0-9]+), calories (-?[0-9]+)")))
        {
            map<string, int> properties;
            properties["capacity"] = stoi(matches[2]);
            properties["durability"] = stoi(matches[3]);
            properties["flavor"] = stoi(matches[4]);
            properties["texture"] = stoi(matches[5]);
            properties["calories"] = stoi(matches[6]);

            ingredients[matches[1]] = properties;
        }
    }

    array<string, 100> spoons;

    return AoCDay::part1(input);
}

string Day15_2015::part2(const string &input)
{
    return AoCDay::part2(input);
}
