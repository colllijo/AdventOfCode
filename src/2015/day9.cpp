#include "day9.h"

Day9_2015::Day9_2015():AoCDay(2015, 9)
{
}

Day9_2015::~Day9_2015() = default;

string Day9_2015::part1(const string &input, bool example)
{
    int shortestRoute = 2147483647;

    map<pair<string, string>, int> routes;
    vector<string> cities;

    stringstream stream (input);
    string connection;
    while (getline(stream, connection, '\n'))
    {
        vector<string> points = aoc_string::split(aoc_string::split(connection, " = ")[0], " to ");
        string distance = aoc_string::split(connection, " = ")[1];

        std::sort(points.begin(), points.end());

        routes[pair(points[0], points[1])] = stoi(distance);

        for (int i = 0; i < 2; i++)
            if (find(cities.begin(), cities.end(), points.at(i)) == end(cities))
                cities.push_back(points.at(i));
    }

    do {
        int distance = 0;
        for (size_t index = 0; index < cities.size() - 1; index++)
        {
            vector<string> cityPair = {cities[index], cities[index + 1]};
            std::sort(cityPair.begin(), cityPair.end());

            distance += routes[pair(cityPair[0], cityPair[1])];
        }

        shortestRoute = min(distance, shortestRoute);
    } while (std::next_permutation(cities.begin(), cities.end()));

    return to_string(shortestRoute);
}

string Day9_2015::part2(const string &input, bool example)
{
    int longestRoute = 0;

    map<pair<string, string>, int> routes;
    vector<string> cities;

    stringstream stream (input);
    string connection;
    while (getline(stream, connection, '\n'))
    {
        vector<string> points = aoc_string::split(aoc_string::split(connection, " = ")[0], " to ");
        string distance = aoc_string::split(connection, " = ")[1];

        std::sort(points.begin(), points.end());

        routes[pair(points[0], points[1])] = stoi(distance);

        for (int i = 0; i < 2; i++)
            if (find(cities.begin(), cities.end(), points.at(i)) == end(cities))
                cities.push_back(points.at(i));
    }

    do {
        int distance = 0;
        for (size_t index = 0; index < cities.size() - 1; index++)
        {
            vector<string> cityPair = {cities[index], cities[index + 1]};
            std::sort(cityPair.begin(), cityPair.end());

            distance += routes[pair(cityPair[0], cityPair[1])];
        }

        longestRoute = max(distance, longestRoute);
    } while (std::next_permutation(cities.begin(), cities.end()));

    return to_string(longestRoute);
}
