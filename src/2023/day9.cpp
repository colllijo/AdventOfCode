#include "day9.h"

#include <functional>

Day9_2023::Day9_2023():AoCDay(2023, 9)
{
    exampleInput = "0 3 6 9 12 15\n"
                   "1 3 6 10 15 21\n"
                   "10 13 16 21 30 45";
}

Day9_2023::~Day9_2023() = default;

string Day9_2023::part1(const string &input, bool example)
{
    vector<vector<long>> lines;
    for (const auto &line : aoc_string::split(input, "\n"))
    {
        vector<string> in = aoc_string::split(line, " ");
        lines.push_back(accumulate(in.begin(), in.end(), vector<long>{}, [](vector<long> acc, string num){ if (aoc_string::isNumber(num)) acc.push_back(stol(num)); return acc; }));
    }

    function<long(vector<long>)> findNext = [&findNext](vector<long> line)
    {
        if (accumulate(line.begin(), line.end(), 0, [](long acc, long num) { return acc + (num != 0); }) == 0)
            return 0l;

        vector<long> previous{};
        for (int i = 0; i < line.size() - 1; i++)
            previous.push_back(line[i + 1] - line[i]);

        return line[line.size() - 1] + findNext(previous);
    };

    return to_string(accumulate(lines.begin(), lines.end(), 0, [&findNext](int acc, const vector<long> &line){ return acc + findNext(line); }));
}

string Day9_2023::part2(const string &input, bool example)
{
    vector<vector<long>> lines;
    for (const auto &line : aoc_string::split(input, "\n"))
    {
        vector<string> in = aoc_string::split(line, " ");
        lines.push_back(accumulate(in.begin(), in.end(), vector<long>{}, [](vector<long> acc, string num){ if (aoc_string::isNumber(num)) acc.push_back(stol(num)); return acc; }));
    }

    function<long(vector<long>)> findNext = [&findNext](vector<long> line)
    {
        if (accumulate(line.begin(), line.end(), 0, [](long acc, long num) { return acc + (num != 0); }) == 0)
            return 0l;

        vector<long> previous{};
        for (int i = 0; i < line.size() - 1; i++)
            previous.push_back(line[i + 1] - line[i]);

        return line[line.size() - 1] + findNext(previous);
    };

    return to_string(accumulate(lines.begin(), lines.end(), 0, [&findNext](int acc, vector<long> line){ std::reverse(line.begin(), line.end()); return acc + findNext(line); }));
}
