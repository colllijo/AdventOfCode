#include "day1.h"

Day1_2023::Day1_2023():AoCDay(2023, 1)
{
}

Day1_2023::~Day1_2023() = default;

const map<string, char> spelledNumbers {
        {"one", '1'},
        {"two", '2'},
        {"three", '3'},
        {"four", '4'},
        {"five", '5'},
        {"six", '6'},
        {"seven", '7'},
        {"eight", '8'},
        {"nine", '9'},
};

string Day1_2023::part1(const string &input)
{
	vector<string> lines = aoc_string::split(input, "\n");
    return to_string(accumulate(lines.begin(), lines.end(), 0, [](int acc, string line){ return acc + ((10 * (accumulate(line.begin(),line.end(), '\0', [](char acc, char c){ return (acc == '\0' &&isdigit(c) ? c : acc); }) - '0')) + accumulate(line.begin(),line.end(), '\0', [](char acc, char c){ return (isdigit(c) ? c : acc); }) - '0'); }));
}

string Day1_2023::part2(const string &input)
{
    vector<string> lines = aoc_string::split(input, "\n");
    return to_string(accumulate(lines.begin(), lines.end(), 0, [](int acc, string line){
        char first = '\0';
        char last = '\0';

        do
        {
            last = accumulate(spelledNumbers.begin(), spelledNumbers.end(), isdigit(line[0]) ? line[0] : last, [line](char acc, const pair<string, char>& entry){ return (line.starts_with(entry.first) ? entry.second : acc); });
            first = accumulate(spelledNumbers.begin(), spelledNumbers.end(), first == '\0' ? (isdigit(line[0]) ? line[0] : first) : first, [line](char acc, const pair<string, char>& entry){ return acc == '\0' ? (line.starts_with(entry.first) ? entry.second : acc) : acc; });
        } while (!(line = line.substr(1)).empty());
        return acc + (10 * (first - '0')) + last - '0';
    }));
}
