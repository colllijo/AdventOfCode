#ifndef COLL_AOC_RUNNER_AOC_STRING_H
#define COLL_AOC_RUNNER_AOC_STRING_H

#pragma once

#include <string>
#include <vector>

namespace aoc_string
{
    inline static std::vector<std::string> split(const std::string& string, const std::string& delimiter)
    {
        std::vector<std::string> result;

        size_t start_pos = 0, end_pos;
        std::string token;

        while ((end_pos = string.find(delimiter, start_pos)) != std::string::npos)
        {
            token = string.substr(start_pos, end_pos - start_pos);
            start_pos = end_pos + delimiter.length();

            result.push_back(token);
        }

        result.push_back(string.substr(start_pos));
        return result;
    }

    inline static bool isNumber(const std::string &string)
    {
        return !string.empty() && std::all_of(string.at(0) == '-' ? string.begin() + 1 : string.begin(), string.end(), ::isdigit);
    }

    inline static bool isLowerCase(const std::string &string)
    {
        return !string.empty() && std::all_of(string.begin(), string.end(), ::islower);
    }

    inline static bool isUpperCase(const std::string &string)
    {
        return !string.empty() && std::all_of(string.begin(), string.end(), ::isupper);
    }
}

#endif
