#include "day14.h"

#include <functional>
#include <iterator>

Day14_2023::Day14_2023():AoCDay(2023, 14)
{
    exampleInput = "O....#....\n"
                   "O.OO#....#\n"
                   ".....##...\n"
                   "OO.#O....O\n"
                   ".O.....O#.\n"
                   "O.#..O.#.#\n"
                   "..O..#O..O\n"
                   ".......O..\n"
                   "#....###..\n"
                   "#OO..#....";
}

Day14_2023::~Day14_2023() = default;

string Day14_2023::part1(const string &input, bool example)
{
    vector<string> lines = aoc_string::split(input, "\n");
    AoC2DGrid<char> grid(lines[0].size(), lines.size());

    int result = 0;
    for (int y = 0; y < grid.getHeight(); y++)
    {
        for (int x = 0; x < grid.getWidth(); x++)
        {
            if (lines[y][x] != 'O')
            {
                grid[y][x] = lines[y][x];
            }
            else
            {
                int d = 0;
                while (y - d > 0 && grid[y - d - 1][x] == '.') { d++; }
                grid[y][x] = '.';
                grid[y - d][x] = 'O';
                result += lines.size() - (y - d);
            }
        }
    }

    return to_string(result);
}

string Day14_2023::part2(const string &input, bool example)
{
    function<void(string&)> spin = [](string &grid){
        function<vector<string>(string)> toCols = [](const string &grid){ vector<string> rows = aoc_string::split(grid, "\n"); vector<string> cols{}; for (size_t i = 0; i < rows[0].size(); i++) { cols.emplace_back(accumulate(rows.begin(),rows.end(), string(), [i](const string& acc, string row){ return acc + row[i]; })); } return cols; };

        for (int i = 0; i < 4; i++)
        {
            vector<string> cols = toCols(grid);
            for (string &col : cols)
            {
                vector<string> parts = aoc_string::split(col, "#");
                std::for_each(parts.begin(), parts.end(), [&i](string &part){ std::sort(part.begin(), part.end(), [&i](char a, char b){ return i < 2 ? a > b : a < b; }); });
                col = accumulate(std::next(parts.begin()), parts.end(),parts[0],[](const string& acc, const string &part) { return acc + "#" + part; });
            }
            grid = accumulate(std::next(cols.begin()), cols.end(), cols[0], [](const string& acc, const string& col){ return acc + "\n" + col; });
        }
    };

    string grid = string(input);
    map<string, int> spins{};

    for (int i = 0; i < 1000000000; i++)
    {
        if (spins.contains(grid))
        {
            i = 1000000000 - (1000000000 - i) % (i - spins[grid]);
            spins = {};
        }
        else
            spins[string(grid)] = i;

        spin(grid);
    }

    vector<string> states{};
    for (const auto &spiny : spins)
        states.push_back(spiny.first);

    int result = 0;
    vector<string> rows = aoc_string::split(grid, "\n");
    for (auto it = rows.begin(); it != rows.end(); ++it)
        result += ((int) rows.size() - (int) (it - rows.begin())) * (int) count(it->begin(), it->end(), 'O');


    return to_string(result);
}
