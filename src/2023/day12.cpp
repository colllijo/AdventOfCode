#include <functional>
#include "day12.h"

Day12_2023::Day12_2023():AoCDay(2023, 12)
{
    exampleInput = "???.### 1,1,3\n"
                   ".??..??...?##. 1,1,3\n"
                   "?#?#?#?#?#?#?#? 1,3,1,6\n"
                   "????.#...#... 4,1,1\n"
                   "????.######..#####. 1,6,5\n"
                   "?###???????? 3,2,1";
}

Day12_2023::~Day12_2023() = default;

long count(const string &s, int i, int j, int len, const vector<int>& groups, unordered_map<string, long> &cache)
{
    if (j == groups.size() || (j == groups.size() - 1 && groups[j] == len))
        return (s.length() == i || s.find("#", i) == string::npos) ? 1 : 0;
    if (i == s.length()) return 0;
    string key = to_string(i) + "-" + to_string(len) + "-" + to_string(j);
    if (cache.find(key) != cache.end()) return cache[key];


    long res = 0;
    if (len == groups[j] && (s[i] == '.' || s[i] == '?'))
    {
        res = count(s, i + 1, j + 1, 0, groups, cache);
    }
    else if (len == 0)
    {
        if (s[i] == '?')
            res = count(s, i + 1, j, 1, groups, cache) + count(s, i + 1, j, 0, groups, cache);
        else if (s[i] == '#')
            res = count(s, i + 1, j, 1, groups, cache);
        else
            res = count(s, i + 1, j, 0, groups, cache);
    }
    else if (s[i] == '#' || s[i] == '?')
        res = count(s, i + 1, j, len + 1, groups, cache);

    cache[key] = res;
    return res;
}

string Day12_2023::part1(const string &input, bool example)
{
    long result = 0;

    for (const string& line: aoc_string::split(input, "\n"))
    {
        vector<string> groupString = aoc_string::split(aoc_string::split(line, " ")[1], ",");
        vector<int> groups;
        transform(groupString.begin(), groupString.end(), back_inserter(groups), [](auto g){ return stoi(g); });

        string part = aoc_string::split(line, " ")[0];

        unordered_map<string, long> cache;
        result += count(part, 0, 0, 0, groups, cache);
    }

    return to_string(result);
}

string Day12_2023::part2(const string &input, bool example)
{
    long result = 0;

    for (const string& line: aoc_string::split(input, "\n"))
    {
        vector<string> groupString = aoc_string::split(aoc_string::split(line, " ")[1], ",");
        vector<int> groups;
        for (int i = 0; i < 5; i++)
            for (const auto &string : groupString)
                groups.push_back(stoi(string));

        string part = aoc_string::split(line, " ")[0];
        string full = part;
        for (int i = 0; i < 4; i++)
            full += "?" + part;

        unordered_map<string, long> cache;
        result += count(full, 0, 0, 0, groups, cache);
    }

    return to_string(result);
}
