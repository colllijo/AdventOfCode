#include <functional>
#include "day10.h"

Day10_2023::Day10_2023():AoCDay(2023, 10)
{
    exampleInput = "FF7FSF7F7F7F7F7F---7\n"
                   "L|LJ||||||||||||F--J\n"
                   "FL-7LJLJ||||||LJL-77\n"
                   "F--JF--7||LJLJ7F7FJ-\n"
                   "L---JF-JLJ.||-FJLJJ7\n"
                   "|F|F-JF---7F7-L7L|7|\n"
                   "|FFJF7L7F-JF7|JL---7\n"
                   "7-L-JL7||F7|L7F-7F7|\n"
                   "L.L7LFJ|||||FJL7||LJ\n"
                   "L7JLJL-JLJLJL--JLJ.L";
}

Day10_2023::~Day10_2023() = default;

enum PipeDirection
{
    NORTH = 1 << 0,
    SOUTH = 1 << 1,
    WEST  = 1 << 2,
    EAST  = 1 << 3,
};

struct Coordinate
{
    int x;
    int y;

};
bool operator==(const Coordinate& a, const Coordinate& b) {
    return a.x == b.x && a.y == b.y;
}

struct Pipe
{
private:
    void loadDirections()
    {
        switch (c)
        {
            case '|': directions = NORTH | SOUTH; break;
            case '-': directions = WEST  |  EAST; break;
            case 'L': directions = NORTH |  EAST; break;
            case 'J': directions = NORTH |  WEST; break;
            case '7': directions = SOUTH |  WEST; break;
            case 'F': directions = SOUTH |  EAST; break;
            case 'S': directions =        0x000F; break;
            default: directions = 0;
        }
    }

public:
    unsigned int directions;
    char c;

    bool inMainLoop;
    Coordinate position;

    Pipe(char c, int x, int y): c(c), inMainLoop(c == 'S'), position(Coordinate(x, y)), directions(0)
    {
        loadDirections();
    }
    Pipe(): directions(0), c('.'), inMainLoop(false), position(Coordinate(-1, -1)) {}

    [[nodiscard]] bool isPipe() const { return directions != 0; }
    [[nodiscard]] bool hasNorth() const { return directions & NORTH; }
    [[nodiscard]] bool hasSouth() const { return directions & SOUTH; }
    [[nodiscard]] bool hasEast() const { return directions & EAST; }
    [[nodiscard]] bool hasWest() const { return directions & WEST; }
};

string Day10_2023::part1(const string &input)
{
    AoC2DGrid<Pipe> grid((int) aoc_string::split(input, "\n")[0].size(), (int) aoc_string::split(input, "\n").size());
    Coordinate start{};
    function<void(Coordinate)> traversePipe = [&grid, &traversePipe](Coordinate from)
    {
            const Pipe &current = grid[from.y][from.x];

            if (current.hasSouth() && from.y + 1 < grid.getHeight())
            {
                Pipe &next = grid[from.y + 1][from.x];
                if (next.isPipe() && next.hasNorth() && !next.inMainLoop)
                {
                    next.inMainLoop = true;
                    traversePipe(next.position);
                }
            }
            if (current.hasNorth() && from.y - 1 >= 0)
            {
                Pipe &next = grid[from.y - 1][from.x];
                if (next.isPipe() && next.hasSouth() && !next.inMainLoop)
                {
                    next.inMainLoop = true;
                    traversePipe(next.position);
                }
            }
            if (current.hasEast() && from.x + 1 < grid.getWidth())
            {
                Pipe &next = grid[from.y][from.x + 1];
                if (next.isPipe() && next.hasWest() && !next.inMainLoop)
                {
                    next.inMainLoop = true;
                    traversePipe(next.position);
                }
            }
            if (current.hasWest() && from.x - 1 >= 0)
            {
                Pipe &next = grid[from.y][from.x - 1];
                if (next.isPipe() && next.hasEast() && !next.inMainLoop)
                {
                    next.inMainLoop = true;
                    traversePipe(next.position);
                }
            }
    };

    for (size_t y = 0; y < grid.getHeight(); y++)
        for (size_t x = 0; x < grid.getWidth(); x++)
        {
            grid[y][x] = Pipe(aoc_string::split(input, "\n")[y][x], (int) x, (int) y);
            if (aoc_string::split(input, "\n")[y][x] == 'S') start = Coordinate((int) x, (int) y);
        }

    traversePipe(start);

    int distance = 0;
    for (size_t y = 0; y < grid.getHeight(); y++)
        for (size_t x = 0; x < grid.getWidth(); x++)
        {
            Pipe &pipe = grid[y][x];
            if (pipe.isPipe() && pipe.inMainLoop) distance++;
        }

    return to_string(distance / 2);
}

string Day10_2023::part2(const string &input)
{
    AoC2DGrid<Pipe> grid((int) aoc_string::split(input, "\n")[0].size(), (int) aoc_string::split(input, "\n").size());
    Coordinate start{};
    function<void(Coordinate)> traversePipe = [&grid, &traversePipe](Coordinate from)
    {
        const Pipe &current = grid[from.y][from.x];

        if (current.hasSouth() && from.y + 1 < grid.getHeight())
        {
            Pipe &next = grid[from.y + 1][from.x];
            if (next.isPipe() && next.hasNorth() && !next.inMainLoop)
            {
                next.inMainLoop = true;
                traversePipe(next.position);
            }
        }
        if (current.hasNorth() && from.y - 1 >= 0)
        {
            Pipe &next = grid[from.y - 1][from.x];
            if (next.isPipe() && next.hasSouth() && !next.inMainLoop)
            {
                next.inMainLoop = true;
                traversePipe(next.position);
            }
        }
        if (current.hasEast() && from.x + 1 < grid.getWidth())
        {
            Pipe &next = grid[from.y][from.x + 1];
            if (next.isPipe() && next.hasWest() && !next.inMainLoop)
            {
                next.inMainLoop = true;
                traversePipe(next.position);
            }
        }
        if (current.hasWest() && from.x - 1 >= 0)
        {
            Pipe &next = grid[from.y][from.x - 1];
            if (next.isPipe() && next.hasEast() && !next.inMainLoop)
            {
                next.inMainLoop = true;
                traversePipe(next.position);
            }
        }
    };

    for (size_t y = 0; y < grid.getHeight(); y++)
        for (size_t x = 0; x < grid.getWidth(); x++)
        {
            grid[y][x] = Pipe(aoc_string::split(input, "\n")[y][x], (int) x, (int) y);
            if (aoc_string::split(input, "\n")[y][x] == 'S') start = Coordinate((int) x, (int) y);
        }

    traversePipe(start);

    // determine directions of start
    grid[start.y][start.x].directions = 0;
    if (start.x - 1 >= 0 && grid[start.y][start.x - 1].inMainLoop && grid[start.y][start.x - 1].hasEast())
        grid[start.y][start.x].directions |= WEST;
    if (start.x + 1 < grid.getWidth() && grid[start.y][start.x + 1].inMainLoop && grid[start.y][start.x + 1].hasWest())
        grid[start.y][start.x].directions |= EAST;
    if (start.y - 1 >= 0 && grid[start.y - 1][start.x].inMainLoop && grid[start.y - 1][start.x].hasSouth())
        grid[start.y][start.x].directions |= NORTH;
    if (start.y + 1 < grid.getHeight() && grid[start.y + 1][start.x].inMainLoop && grid[start.y + 1][start.x].hasNorth())
        grid[start.y][start.x].directions |= SOUTH;

    int enclosed = 0;
    for (size_t y = 0; y < grid.getHeight(); y++)
    {
        bool inLoop = false;
        for (size_t x = 0; x < grid.getWidth(); x++)
        {
            Pipe &pipe = grid[y][x];
            for (size_t dx = x - 1; dx < x; dx++)
            {
                Pipe &dPipe = grid[y][dx];
                if (dPipe.inMainLoop && (dPipe.hasNorth() || dPipe.hasSouth()))
                {
                    if (dPipe.directions == (NORTH | SOUTH))
                        inLoop = !inLoop;
                    else
                    {
                        while (dx + 1 < grid.getWidth() && grid[y][dx + 1].hasWest() && grid[y][dx + 1].inMainLoop)
                            dx++;
                        Pipe &endPipe = grid[y][dx];

                        if (!(dPipe.hasSouth() && endPipe.hasSouth() || dPipe.hasNorth() && endPipe.hasNorth()))
                            inLoop = !inLoop;
                    }
                }
            }

            if (inLoop && !pipe.inMainLoop) enclosed++;
            printf(inLoop && !pipe.inMainLoop ? "\033[1m\033[31m#\033[0m" : "\033[%sm%c\033[0m", (grid[y][x].isPipe() ? "0" : "1"), (grid[y][x].inMainLoop ? grid[y][x].c : '#'));
        }
        cout << endl;
    }

    return to_string(enclosed);
}
