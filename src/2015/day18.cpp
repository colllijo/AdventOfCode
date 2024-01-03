#include "day18.h"

#include "numeric"

Day18_2015::Day18_2015():AoCDay(2015, 18)
{
}

Day18_2015::~Day18_2015() = default;

string Day18_2015::part1(const string &input, bool example)
{
    AoC2DGrid<char> grid(100, 100);
    AoC2DGrid<char> updatedGrid(100, 100);

    string _input = ".#.#.#\n"
                    "...##.\n"
                    "#....#\n"
                    "..#...\n"
                    "#.#..#\n"
                    "####..";

    for (int y = 0; y < grid.getHeight(); y++)
        for (int x = 0; x < grid.getWidth(); x++)
            grid[y][x] = aoc_string::split(input, "\n")[y][x];

    for (int steps = 0; steps < 100; steps++) {
        for (int y = 0; y < grid.getHeight(); y++)
        {
            for (int x = 0; x < grid.getWidth(); x++)
            {
                vector<char> neighbors = grid.getAdjacentCells(x, y);
                int neighborsOn = std::accumulate(neighbors.begin(), neighbors.end(), 0, [](int accumulator, char light) { return accumulator + (light == '#' ? 1 : 0); });

                if (grid[y][x] == '#')
                    if (neighborsOn != 2 && neighborsOn != 3)
                        updatedGrid[y][x] = '.';
                    else
                        updatedGrid[y][x] = '#';
                else
                    if (neighborsOn == 3)
                        updatedGrid[y][x] = '#';
                    else
                        updatedGrid[y][x] = '.';
            }
        }
        grid = updatedGrid;
        updatedGrid = *new AoC2DGrid<char>(100, 100);
    }


    int lights = 0;
    for (int y = 0; y < grid.getHeight(); y++)
        for (int x = 0; x < grid.getWidth(); x++)
            if (grid[y][x] == '#')
                lights++;

    return to_string(lights);
}

string Day18_2015::part2(const string &input, bool example)
{
    AoC2DGrid<char> grid(100, 100);
    AoC2DGrid<char> updatedGrid(100, 100);

    string _input = ".#.#.#\n"
                    "...##.\n"
                    "#....#\n"
                    "..#...\n"
                    "#.#..#\n"
                    "####..";

    for (int y = 0; y < grid.getHeight(); y++)
        for (int x = 0; x < grid.getWidth(); x++)
            grid[y][x] = aoc_string::split(input, "\n")[y][x];

    // Turn corners on
    grid[0][0] = '#';
    grid[99][0] = '#';
    grid[0][99] = '#';
    grid[99][99] = '#';

    for (int steps = 0; steps < 100; steps++) {
        for (int y = 0; y < grid.getHeight(); y++)
        {
            for (int x = 0; x < grid.getWidth(); x++)
            {
                vector<char> neighbors = grid.getAdjacentCells(x, y);
                int neighborsOn = std::accumulate(neighbors.begin(), neighbors.end(), 0, [](int accumulator, char light) { return accumulator + (light == '#' ? 1 : 0); });

                if (grid[y][x] == '#')
                    if (neighborsOn != 2 && neighborsOn != 3)
                        updatedGrid[y][x] = '.';
                    else
                        updatedGrid[y][x] = '#';
                else
                if (neighborsOn == 3)
                    updatedGrid[y][x] = '#';
                else
                    updatedGrid[y][x] = '.';
            }
        }
        grid = updatedGrid;
        updatedGrid = *new AoC2DGrid<char>(100, 100);

        // Turn corners on
        grid[0][0] = '#';
        grid[99][0] = '#';
        grid[0][99] = '#';
        grid[99][99] = '#';
    }


    int lights = 0;
    for (int y = 0; y < grid.getHeight(); y++)
        for (int x = 0; x < grid.getWidth(); x++)
            if (grid[y][x] == '#')
                lights++;

    return to_string(lights);
}
