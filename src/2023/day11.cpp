#include "day11.h"

#include <numeric>

Day11_2023::Day11_2023():AoCDay(2023, 11)
{
}

Day11_2023::~Day11_2023() = default;

string Day11_2023::part1(const string &input, bool example)
{
    string _input = "...#......\n"
                    ".......#..\n"
                    "#.........\n"
                    "..........\n"
                    "......#...\n"
                    ".#........\n"
                    ".........#\n"
                    "..........\n"
                    ".......#..\n"
                    "#...#.....\n";
    _input = input;

    if (_input.ends_with('\n'))
        _input.pop_back();

    vector<pair<int, int>> galaxies;
    AoC2DGrid<char> universe((int) aoc_string::split(_input, "\n")[0].size(), (int) aoc_string::split(_input, "\n").size());
    for (int y = 0; y < universe.getHeight(); y++)
        for (int x = 0; x < universe.getHeight(); x++)
            universe[y][x] = aoc_string::split(_input, "\n")[y][x];

    vector<int> yEmpty {}, xEmpty{};
    for (int y = 0; y < universe.getHeight(); y++)
    {
        bool empty = true;
        for (int x = 0; x < universe.getWidth(); x++)
            if (universe[y][x] == '#')
                empty = false;
        if (empty) yEmpty.push_back(y);
    }
    for (int x = 0; x < universe.getHeight(); x++)
    {
        bool empty = true;
        for (int y = 0; y < universe.getWidth(); y++)
            if (universe[y][x] == '#')
                empty = false;
        if (empty) xEmpty.push_back(x);
    }

    for (int y = 0; y < universe.getHeight(); y++)
        for (int x = 0; x < universe.getHeight(); x++)
            if (universe[y][x] == '#')
                galaxies.emplace_back(x + accumulate(xEmpty.begin(), xEmpty.end(), 0, [x](int acc, int value){ return acc + (x > value ? (1000000 - 1) : 0);}), y + accumulate(yEmpty.begin(), yEmpty.end(), 0, [y](int acc, int value){ return acc + (y > value ? (1000000 - 1) : 0);}));

    long sum = 0;
    for (int i = 0; i < galaxies.size(); i++)
        for (int j = i + 1; j < galaxies.size(); j++)
            sum += abs(galaxies[i].first - galaxies[j].first) + abs(galaxies[i].second - galaxies[j].second);

    return to_string(sum);
}

string Day11_2023::part2(const string &input, bool example)
{
    return AoCDay::part2(input, example);
}
