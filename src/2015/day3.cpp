#include "day3.h"

Day3_2015::Day3_2015():AoCDay(2015, 3)
{
}

Day3_2015::~Day3_2015() = default;

string Day3_2015::part1(const string &input, bool example)
{
    std::map<std::tuple<int, int>, bool> map;
    int x = 0;
    int y = 0;

    // Starting location
    map[std::tuple(x, y)] = true;
    for (auto &c : input)
    {
        switch (c)
        {
            case '^':
                y--;
                break;
            case '>':
                x++;
                break;
            case 'v':
                y++;
                break;
            case '<':
                x--;
                break;
            default:
                break;
        }

        map[std::tuple(x, y)] = true;
    }

    return std::to_string(map.size());
}

string Day3_2015::part2(const string &input, bool example)
{
    std::map<std::tuple<int, int>, bool> map;
    int santaX = 0;
    int santaY = 0;
    int satanX = 0;
    int satanY = 0;

    bool santaMove = true;

    // Starting location
    map[std::tuple(santaX, santaY)] = true;
    for (auto &c : input)
    {
        switch (c)
        {
            case '^':
                if (santaMove)
                    santaY--;
                else
                    satanY--;
                break;
            case '>':
                if (santaMove)
                    santaX++;
                else
                    satanX++;
                break;
            case 'v':
                if (santaMove)
                    santaY++;
                else
                    satanY++;
                break;
            case '<':
                if (santaMove)
                    santaX--;
                else
                    satanX--;
                break;
            default:
                break;
        }

        if (santaMove)
            map[std::tuple(santaX, santaY)] = true;
        else
            map[std::tuple(satanX, satanY)] = true;

        santaMove = !santaMove;
    }

    return std::to_string(map.size());
}
