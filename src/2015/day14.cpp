#include "day14.h"

Day14_2015::Day14_2015():AoCDay(2015, 14)
{
}

Day14_2015::~Day14_2015() = default;

string Day14_2015::part1(const string &input, bool example)
{
    int longestDistance = 0;

    stringstream stream(input);
    string reindeer;
    while(getline(stream, reindeer, '\n'))
    {
        int distance = 0;
        int speed = stoi(aoc_string::split(reindeer, " ")[3]);
        int energy = stoi(aoc_string::split(reindeer, " ")[6]);
        int rest = stoi(aoc_string::split(reindeer, " ")[13]);

        for (int i = 0; i < 2503; i++)
            distance += (i % (energy + rest) < energy) ? speed : 0;

        longestDistance = max(longestDistance, distance);
    }

    return to_string(longestDistance);
}

string Day14_2015::part2(const string &input, bool example)
{
    vector<int> points;
    map<string, vector<int>> reindeer;

    stringstream stream(input);
    string competitors;
    while(getline(stream, competitors, '\n'))
    {
        reindeer[aoc_string::split(competitors, " ")[0]] = {
                0,  // Points
                0,  // Distance
                stoi(aoc_string::split(competitors, " ")[3]),   // Speed
                stoi(aoc_string::split(competitors, " ")[6]),   // Energy
                stoi(aoc_string::split(competitors, " ")[13])   // Rest
        };
    }

    for (int i = 0; i < 2503; i++)
    {
        int farthest = 0;
        for (auto &competitor : reindeer)
        {
            competitor.second[1] += (i % (competitor.second[3] + competitor.second[4]) < competitor.second[3]) ? competitor.second[2] : 0;

            farthest = max(farthest, competitor.second[1]);
        }

        for (auto &competitor : reindeer)
            if (competitor.second[1] == farthest)
                competitor.second[0]++;
    }

    for (const auto &competitor : reindeer)
        points.push_back(competitor.second[0]);

    return to_string(*std::max_element(points.begin(), points.end()));
}
