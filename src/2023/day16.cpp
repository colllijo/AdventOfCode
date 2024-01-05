#include "day16.h"

Day16_2023::Day16_2023():AoCDay(2023, 16)
{
    exampleInput = ".|...\\....\n"
                   "|.-.\\.....\n"
                   ".....|-...\n"
                   "........|.\n"
                   "..........\n"
                   ".........\\\n"
                   "..../.\\\\..\n"
                   ".-.-/..|..\n"
                   ".|....-|.\\\n"
                   "..//.|....";
}

Day16_2023::~Day16_2023() = default;

enum Direction
{
    UP = 1 << 0,
    DOWN = 1 << 1,
    LEFT = 1 << 2,
    RIGHT = 1 << 3
};

struct Beam
{
    int x;
    int y;
    Direction dir;
};

string Day16_2023::part1(const string &input, bool example)
{
    vector<string> lines = aoc_string::split(input, "\n");
    AoC2DGrid<char> grid((int) lines[0].size(), (int) lines.size());

    for (int y = 0; y < grid.getHeight(); y++)
        for (int x = 0; x < grid.getWidth(); x++)
            grid[y][x] = lines[y][x];

    vector<Beam> beams {};
    map<pair<int, int>, int> visited{};

    // Add initial Beam
    beams.push_back({-1, 0, RIGHT});

    while (!beams.empty())
    {
        vector<Beam> createdBeams{};

        for (auto it = beams.begin(); it != beams.end(); )
        {
            switch (it->dir)
            {
                case UP: it->y--; break;
                case DOWN: it->y++; break;
                case LEFT: it->x--; break;
                case RIGHT: it->x++; break;
            }

            if (it->y < 0 || it->y >= grid.getHeight() || it->x < 0 || it->x >= grid.getWidth() || (visited[{it->x, it->y}] & it->dir) > 0)
            {
                it = beams.erase(it);
            }
            else
            {
                if (visited.contains({it->x, it->y}) && visited[{it->x, it->y}] != 0) { visited[{it->x, it->y}] |= it->dir; } else { visited[{it->x, it->y}] = it->dir;}
                if (grid[it->y][it->x] == '|')
                {
                    if (it->dir == LEFT || it->dir == RIGHT)
                    {
                        it->dir = UP;
                        createdBeams.push_back(Beam{it->x, it->y, DOWN});
                    }
                }
                else if (grid[it->y][it->x] == '-')
                {
                    if (it->dir == UP || it->dir == DOWN)
                    {
                        it->dir = LEFT;
                        createdBeams.push_back(Beam{it->x, it->y, RIGHT});
                    }
                }
                else if (grid[it->y][it->x] == '/')
                {
                    switch (it->dir)
                    {
                        case UP: it->dir = RIGHT; break;
                        case DOWN: it->dir = LEFT; break;
                        case LEFT: it->dir = DOWN; break;
                        case RIGHT: it->dir = UP; break;
                    }
                }
                else if (grid[it->y][it->x] == '\\')
                {
                    switch (it->dir)
                    {
                        case UP: it->dir = LEFT; break;
                        case DOWN: it->dir = RIGHT; break;
                        case LEFT: it->dir = UP; break;
                        case RIGHT: it->dir = DOWN; break;
                    }
                }
                it++;
            }
        }

        beams.insert(beams.end(), createdBeams.begin(), createdBeams.end());
    }

    return to_string(visited.size());
}

string Day16_2023::part2(const string &input, bool example)
{
    vector<string> lines = aoc_string::split(input, "\n");
    AoC2DGrid<char> grid((int) lines[0].size(), (int) lines.size());
    int best = INT32_MIN;

    for (int y = 0; y < grid.getHeight(); y++)
        for (int x = 0; x < grid.getWidth(); x++)
            grid[y][x] = lines[y][x];

    for (int i = 0; i < (grid.getWidth() * 2 + grid.getHeight() * 2); i++)
    {
        vector<Beam> beams {};
        map<pair<int, int>, int> visited{};

        // Add initial Beam
        beams.push_back({i >= grid.getWidth() * 2 ? (i - grid.getWidth() * 2) < grid.getHeight() ? -1 : grid.getWidth() : i % grid.getWidth(), i < grid.getWidth() * 2 ? i < grid.getWidth() ? -1 : grid.getHeight() : (i - grid.getWidth() * 2) % grid.getHeight(), i < grid.getWidth() * 2 ? i < grid.getWidth() ? DOWN : UP : (i - grid.getWidth() * 2) < grid.getHeight() ? RIGHT : LEFT});

        while (!beams.empty())
        {
            vector<Beam> createdBeams{};

            for (auto it = beams.begin(); it != beams.end(); )
            {
                switch (it->dir)
                {
                    case UP: it->y--; break;
                    case DOWN: it->y++; break;
                    case LEFT: it->x--; break;
                    case RIGHT: it->x++; break;
                }

                if (it->y < 0 || it->y >= grid.getHeight() || it->x < 0 || it->x >= grid.getWidth() || (visited[{it->x, it->y}] & it->dir) > 0)
                {
                    it = beams.erase(it);
                }
                else
                {
                    if (visited.contains({it->x, it->y}) && visited[{it->x, it->y}] != 0) { visited[{it->x, it->y}] |= it->dir; } else { visited[{it->x, it->y}] = it->dir;}
                    if (grid[it->y][it->x] == '|')
                    {
                        if (it->dir == LEFT || it->dir == RIGHT)
                        {
                            it->dir = UP;
                            createdBeams.push_back(Beam{it->x, it->y, DOWN});
                        }
                    }
                    else if (grid[it->y][it->x] == '-')
                    {
                        if (it->dir == UP || it->dir == DOWN)
                        {
                            it->dir = LEFT;
                            createdBeams.push_back(Beam{it->x, it->y, RIGHT});
                        }
                    }
                    else if (grid[it->y][it->x] == '/')
                    {
                        switch (it->dir)
                        {
                            case UP: it->dir = RIGHT; break;
                            case DOWN: it->dir = LEFT; break;
                            case LEFT: it->dir = DOWN; break;
                            case RIGHT: it->dir = UP; break;
                        }
                    }
                    else if (grid[it->y][it->x] == '\\')
                    {
                        switch (it->dir)
                        {
                            case UP: it->dir = LEFT; break;
                            case DOWN: it->dir = RIGHT; break;
                            case LEFT: it->dir = UP; break;
                            case RIGHT: it->dir = DOWN; break;
                        }
                    }
                    it++;
                }
            }

            beams.insert(beams.end(), createdBeams.begin(), createdBeams.end());
        }

        best = max(best, (int) visited.size());
    }

    return to_string(best);
}
