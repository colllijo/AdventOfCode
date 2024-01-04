#include "day15.h"

#include <regex>

Day15_2023::Day15_2023():AoCDay(2023, 15)
{
    exampleInput = "rn=1,cm-,qp=3,cm=2,qp-,pc=4,ot=9,ab=5,pc-,pc=6,ot=7";
}

Day15_2023::~Day15_2023() = default;

string Day15_2023::part1(const string &input, bool example)
{
    auto hash = [](const string &s){ return accumulate(s.begin(), s.end(), (uint8_t) 0, [](uint8_t acc, char c){ return (acc + c) * 17; }); };

    vector<string> steps = aoc_string::split(input, ",");
    return to_string(accumulate(steps.begin(), steps.end(), 0, [&hash](int acc, string step){ return acc + hash(step); }));
}

string Day15_2023::part2(const string &input, bool example)
{
    auto hash = [](const string &s){ return accumulate(s.begin(), s.end(), (uint8_t) 0, [](uint8_t acc, char c){ return (acc + c) * 17; }); };
    vector<pair<string, int>> boxes[256];

    for (const auto &step : aoc_string::split(input, ","))
    {
        smatch matches;
        if (regex_search(step, matches, regex("([^-=]*)([=-])([1-9]?)")))
        {
            string label = matches[1];
            string operation = matches[2];

            int focalLength = 0;
            if (matches.size() == 4 && !string(matches[3]).empty()) {
                focalLength = stoi(matches[3]);
            }
            int box = hash(label);

            if (operation == "=")
            {
                bool found = false;
                for (auto & i : boxes[box])
                {
                    if (i.first == label)
                    {
                        i.second = focalLength;
                        found = true;
                    }
                }
                if (!found) boxes[box].emplace_back(pair<string, int>{label, focalLength});
            }
            else if (operation == "-")
            {
                for (int i = 0; i < boxes[box].size(); i++)
                {
                    if (boxes[box][i].first == label)
                    {
                        boxes[box].erase(boxes[box].begin() + i);
                        break;
                    }
                }
            }
        }
    }

    int result = 0;
    for (int i = 0; i < 256; i++)
        for (int j = 0; j < boxes[i].size(); j++)
            result += (i + 1) * (j + 1) * boxes[i][j].second;

    return to_string(result);
}
