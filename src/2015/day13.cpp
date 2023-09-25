#include "day13.h"

Day13_2015::Day13_2015():AoCDay(2015, 13)
{
}

Day13_2015::~Day13_2015() = default;

string Day13_2015::part1(const string &input)
{
    int maxHappiness = INT32_MIN;

    vector<string> people;
    map<pair<string, string>, int> happinessGain;

    stringstream stream (input);
    string line;
    while (getline(stream, line, '\n'))
    {
        vector<string> parts = aoc_string::split(aoc_string::split(line, ".")[0], " ");

        if (std::find(people.begin(), people.end(), parts[0]) == people.end())
            people.push_back(parts[0]);

        if (std::find(people.begin(), people.end(), parts[parts.size() - 1]) == people.end())
            people.push_back(parts[parts.size() - 1]);

        happinessGain[pair(parts[0], parts[parts.size() - 1])] = (parts[2] == "gain" ? 1 : -1) * stoi(parts[3]);
    }

    do {
        int happiness = 0;

        for (size_t i = 0; i < people.size(); i++)
        {
            if (i == 0)
            {
                happiness += happinessGain[pair(people[0], people[people.size() - 1])];
                happiness += happinessGain[pair(people[0], people[1])];
            }
            else if (i == people.size() - 1)
            {
                happiness += happinessGain[pair(people[i], people[i - 1])];
                happiness += happinessGain[pair(people[i], people[0])];
            }
            else
            {
                happiness += happinessGain[pair(people[i], people[i - 1])];
                happiness += happinessGain[pair(people[i], people[i + 1])];
            }
        }

        maxHappiness = max(happiness, maxHappiness);
    } while (std::next_permutation(people.begin(), people.end()));

    return to_string(maxHappiness);
}

string Day13_2015::part2(const string &input)
{
    int maxHappiness = INT32_MIN;

    vector<string> people;
    map<pair<string, string>, int> happinessGain;

    stringstream stream (input);
    string line;
    while (getline(stream, line, '\n'))
    {
        vector<string> parts = aoc_string::split(aoc_string::split(line, ".")[0], " ");

        if (std::find(people.begin(), people.end(), parts[0]) == people.end())
            people.push_back(parts[0]);

        if (std::find(people.begin(), people.end(), parts[parts.size() - 1]) == people.end())
            people.push_back(parts[parts.size() - 1]);

        happinessGain[pair(parts[0], parts[parts.size() - 1])] = (parts[2] == "gain" ? 1 : -1) * stoi(parts[3]);
    }

    // Add myself;
    for (const auto &person : people)
    {
        happinessGain[pair("me", person)] = 0;
        happinessGain[pair(person, "me")] = 0;
    }
    people.emplace_back("me");

    do {
        int happiness = 0;

        for (size_t i = 0; i < people.size(); i++)
        {
            if (i == 0)
            {
                happiness += happinessGain[pair(people[0], people[people.size() - 1])];
                happiness += happinessGain[pair(people[0], people[1])];
            }
            else if (i == people.size() - 1)
            {
                happiness += happinessGain[pair(people[i], people[i - 1])];
                happiness += happinessGain[pair(people[i], people[0])];
            }
            else
            {
                happiness += happinessGain[pair(people[i], people[i - 1])];
                happiness += happinessGain[pair(people[i], people[i + 1])];
            }
        }

        maxHappiness = max(happiness, maxHappiness);
    } while (std::next_permutation(people.begin(), people.end()));

    return to_string(maxHappiness);
}
