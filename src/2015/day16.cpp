#include "day16.h"

#include <regex>

Day16_2015::Day16_2015():AoCDay(2015, 16)
{
}

Day16_2015::~Day16_2015() = default;

struct Aunt
{
    int number;
    vector<string> knownProperties;
    map<string, int> properties;
};

string Day16_2015::part1(const string &input, bool example)
{
    vector<Aunt> aunts;

    map<string, int> found = {
            {"children", 3},
            {"cats", 7},
            {"samoyeds", 2},
            {"pomeranians", 3},
            {"akitas", 0},
            {"vizslas", 0},
            {"goldfish", 5},
            {"trees", 3},
            {"cars", 2},
            {"perfumes", 1}
    };

    stringstream stream(input);
    string auntString;
    while(getline(stream, auntString, '\n'))
    {
        Aunt currentAunt;
        currentAunt.number = stoi(aoc_string::split(aoc_string::split(auntString, ":")[0], " ")[1]);

        vector<string> properties = aoc_string::split(aoc_string::split(auntString, to_string(currentAunt.number) + ": ")[1], ", ");

        for (const auto& property : properties)
        {
            currentAunt.knownProperties.push_back(aoc_string::split(property, ": ")[0]);
            currentAunt.properties[aoc_string::split(property, ": ")[0]] = stoi(aoc_string::split(property, ": ")[1]);
        }

        aunts.push_back(currentAunt);
    }

    for (const auto& aunt : aunts)
    {
        bool matches = true;
        for (const auto& property : aunt.knownProperties)
            if (aunt.properties.at(property) != found[property])
                matches = false;

        if (matches)
            return to_string(aunt.number);
    }

    return "Not found";
}

string Day16_2015::part2(const string &input, bool example)
{
    vector<Aunt> aunts;

    map<string, int> found = {
            {"children", 3},
            {"cats", 7},
            {"samoyeds", 2},
            {"pomeranians", 3},
            {"akitas", 0},
            {"vizslas", 0},
            {"goldfish", 5},
            {"trees", 3},
            {"cars", 2},
            {"perfumes", 1}
    };

    stringstream stream(input);
    string auntString;
    while(getline(stream, auntString, '\n'))
    {
        Aunt currentAunt;
        currentAunt.number = stoi(aoc_string::split(aoc_string::split(auntString, ":")[0], " ")[1]);

        vector<string> properties = aoc_string::split(aoc_string::split(auntString, to_string(currentAunt.number) + ": ")[1], ", ");

        for (const auto& property : properties)
        {
            currentAunt.knownProperties.push_back(aoc_string::split(property, ": ")[0]);
            currentAunt.properties[aoc_string::split(property, ": ")[0]] = stoi(aoc_string::split(property, ": ")[1]);
        }

        aunts.push_back(currentAunt);
    }

    for (const auto& aunt : aunts)
    {
        bool matches = true;
        for (const auto& property : aunt.knownProperties)
        {
            if (property == "cats" || property == "trees")
            {
                if (aunt.properties.at(property) <= found[property])
                    matches = false;
            }
            else if (property == "pomeranians" || property == "goldfish")
            {
                if (aunt.properties.at(property) >= found[property])
                    matches = false;
            }
            else
            {
                if (aunt.properties.at(property) != found[property])
                    matches = false;
            }
        }

        if (matches)
            return to_string(aunt.number);
    }

    return "Not found";
}
