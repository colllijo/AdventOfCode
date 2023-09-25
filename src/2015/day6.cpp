#include "day6.h"

#include <regex>

Day6_2015::Day6_2015():AoCDay(2015, 6)
{
}

Day6_2015::~Day6_2015() = default;

string Day6_2015::part1(const string &input)
{
    int squareSize = 1000;
    vector<vector<bool>> lights(squareSize, vector<bool>(squareSize, false));

    regex instructionRegex ("(turn on|turn off|toggle) ([0-9]+),([0-9]+) through ([0-9]+),([0-9]+)");

    // follow instructions to turn on lights
    std::stringstream stream (input);
    std::string instruction;
    while (std::getline(stream, instruction, '\n'))
    {
        smatch matches;
        if (regex_search(instruction, matches, instructionRegex))
        {
            int startX = stoi(matches[2].str());
            int endX = stoi(matches[4].str());
            int startY = stoi(matches[3].str());
            int endY = stoi(matches[5].str());

            for (int x = startX; x <= endX; x++)
            {
                for (int y = startY; y <= endY; y++)
                {
                    if (matches[1].str() == "turn on")
                    {
                        lights[x][y] = true;
                    }
                    else if (matches[1].str() == "turn off")
                    {
                        lights[x][y] = false;
                    }
                    else if (matches[1].str() == "toggle")
                    {
                        lights[x][y] = !lights[x][y];
                    }
                }
            }
        }
    }

    // Count lights
    int burningLights = 0;
    for (int x = 0; x < squareSize; x++)
    {
        for (int y = 0; y < squareSize; y++)
        {
            if (lights[x][y])
                burningLights++;
        }
    }

    return to_string(burningLights);
}

string Day6_2015::part2(const string &input)
{
    int squareSize = 1000;
    vector<vector<int>> lights(squareSize, vector<int>(squareSize, 0));

    regex instructionRegex ("(turn on|turn off|toggle) ([0-9]+),([0-9]+) through ([0-9]+),([0-9]+)");

    // follow instructions to turn on lights
    std::stringstream stream (input);
    std::string instruction;
    while (std::getline(stream, instruction, '\n'))
    {
        smatch matches;
        if (regex_search(instruction, matches, instructionRegex))
        {
            int startX = stoi(matches[2].str());
            int endX = stoi(matches[4].str());
            int startY = stoi(matches[3].str());
            int endY = stoi(matches[5].str());

            for (int x = startX; x <= endX; x++)
            {
                for (int y = startY; y <= endY; y++)
                {
                    if (matches[1].str() == "turn on")
                    {
                        lights[x][y]++;
                    }
                    else if (matches[1].str() == "turn off")
                    {
                        lights[x][y]--;
                        if (lights[x][y] < 0)
                            lights[x][y] = 0;
                    }
                    else if (matches[1].str() == "toggle")
                    {
                        (++lights[x][y])++;
                    }
                }
            }
        }
    }

    // Count lights
    int burningLights = 0;
    for (int x = 0; x < squareSize; x++)
    {
        for (int y = 0; y < squareSize; y++)
        {
            burningLights += lights[x][y];
        }
    }

    return to_string(burningLights);
}
