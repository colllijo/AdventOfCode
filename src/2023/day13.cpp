#include "day13.h"

#include <bitset>

Day13_2023::Day13_2023():AoCDay(2023, 13)
{
    exampleInput = "#.##..##.\n"
                   "..#.##.#.\n"
                   "##......#\n"
                   "##......#\n"
                   "..#.##.#.\n"
                   "..##..##.\n"
                   "#.#.##.#.\n"
                   "\n"
                   "#...##..#\n"
                   "#....#..#\n"
                   "..##..###\n"
                   "#####.##.\n"
                   "#####.##.\n"
                   "..##..###\n"
                   "#....#..#";
}

Day13_2023::~Day13_2023() = default;

string Day13_2023::part1(const string &input, bool example)
{
    int result = 0;
    for (const auto &grid : aoc_string::split(input, "\n\n"))
    {
        vector<string> lines = aoc_string::split(grid, "\n");

        for (int i = 1; i < lines[0].size(); i++)
        {
            bool symmetrical = true;

            for (const auto &line : lines)
            {
                string left = line.substr(0, i);
                std::reverse(left.begin(), left.end());
                string right = line.substr(i, line.size());
                left.resize(min(left.size(), right.size()));
                right.resize(min(left.size(), right.size()));

                if (left != right)
                {
                    symmetrical = false;
                    break;
                }
            }

            if (symmetrical)
            {
                result += i;
                break;
            }
        }

        for (int i = 0; i < lines.size() - 1; i++)
        {
            bool symmetrical = true;

            int d = 0;
            while (i - d >= 0 && i + d + 1 < lines.size())
            {
                if (lines[i - d] != lines[i + d + 1])
                {
                    symmetrical = false;
                    break;
                }

                d++;
            }

            if (symmetrical)
            {
                result += 100 * (i + 1);
                break;
            }
        }
    }

    return to_string(result);
}

string Day13_2023::part2(const string &input, bool example)
{
    int result = 0;
    for (const auto &grid : aoc_string::split(input, "\n\n"))
    {
        int val = INT32_MAX;
        vector<string> lines = aoc_string::split(grid, "\n");

        for (int i = 1; i < lines[0].size(); i++)
        {
            int smudges = 0;

            for (const auto &line : lines)
            {
                string leftString = line.substr(0, i);
                std::reverse(leftString.begin(), leftString.end());
                string rightString = line.substr(i, line.size());
                leftString.resize(min(leftString.size(), rightString.size()));
                rightString.resize(min(leftString.size(), rightString.size()));

                long left = 0;
                long right = 0;
                for (int index = 0; index < leftString.size(); index++)
                {
                    left |= (leftString[index] == '#' ? 1 : 0) << index;
                    right |= (rightString[index] == '#' ? 1 : 0) << index;
                }

                bitset<64> wrongBits = (left ^ right);
                smudges += (int) wrongBits.count();
            }

            if (smudges == 1)
            {
                val = i;
                break;
            }
        }

        for (int i = 0; i < lines.size() - 1; i++)
        {
            int smudges = 0;

            int d = 0;
            while (i - d >= 0 && i + d + 1 < lines.size())
            {
                long top = 0;
                long bottom = 0;
                for (int index = 0; index < lines[i - d].size(); index++)
                {
                    top |= (lines[i - d][index] == '#' ? 1 : 0) << index;
                    bottom |= (lines[i + d + 1][index] == '#' ? 1 : 0) << index;
                }

                bitset<64> wrongBits = (top ^ bottom);
                smudges += (int) wrongBits.count();

                d++;
            }

            if (smudges == 1)
            {
                if (i + 1 < val)
                    val = 100 * (i + 1);
                break;
            }
        }

        result += val;
    }

    return to_string(result);
}
