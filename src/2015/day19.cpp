#include "day19.h"

Day19_2015::Day19_2015():AoCDay(2015, 19)
{
}

Day19_2015::~Day19_2015() = default;

string Day19_2015::part1(const string &input, bool example)
{
    vector<pair<string, string>> replacements;
    string molecule;

    bool firstSection = true;
    stringstream stream(input);
    string line;
    while (getline(stream, line, '\n'))
    {
        if (line.empty())
        {
            firstSection = false;
            continue;
        }

        if (firstSection)
        {
            replacements.emplace_back(aoc_string::split(line, " => ")[0], aoc_string::split(line, " => ")[1]);
        } else
        {
            molecule = line;
        }
    }

    set<string> possibleMolecules;
    for (const auto &entry : replacements)
    {
        for (size_t i = 0; i < molecule.size(); i++)
        {
            if (molecule.substr(i, entry.first.size()) == entry.first)
            {
                string tmp(molecule);
                tmp.replace(i, entry.first.size(), entry.second);
                possibleMolecules.insert(tmp);
            }
        }
    }

    return to_string(possibleMolecules.size());
}

string Day19_2015::part2(const string &input, bool example)
{
    string _input = "e => H\n"
                    "e => O\n"
                    "H => HO\n"
                    "H => OH\n"
                    "O => HH\n"
                    "\n"
                    "HOHOHO";

    vector<pair<string, string>> replacements;
    string medicine;

    bool firstSection = true;
    stringstream stream(input);
    string line;
    while (getline(stream, line, '\n'))
    {
        if (line.empty())
        {
            firstSection = false;
            continue;
        }

        if (firstSection)
        {
            replacements.emplace_back(aoc_string::split(line, " => ")[0], aoc_string::split(line, " => ")[1]);
        } else
        {
            medicine = line;
        }
    }

    std::sort(replacements.begin(), replacements.end(), [](pair<string, string> a, pair<string, string> b) {return a.second.size() < b.second.size() ? 0 : 1; });

    int steps = 0;
    string molecule = medicine;
    do {
        for (const auto &replacement : replacements)
        {
            if (molecule.find(replacement.second) != string::npos)
            {
                steps++;
                molecule.replace(molecule.find(replacement.second), replacement.second.size(), replacement.first);
                break;
            }
        }
    } while (molecule != "e");

    return to_string(steps);
}
