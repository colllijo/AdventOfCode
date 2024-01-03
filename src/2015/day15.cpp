#include "day15.h"

#include <functional>
#include <numeric>
#include <regex>

Day15_2015::Day15_2015():AoCDay(2015, 15)
{
}

Day15_2015::~Day15_2015() = default;

vector<vector<int>> print_partitions(int sum, int n) {
    vector<vector<int>> partitions;

    int pos = 0, last = n - 1;
    int a[n];

    for (int i = 1; i != n; ++i)
        a[i] = 0;

    a[0] = sum;
    while (true) {
        vector<int> partition;
        for (int i = 0; i != last; ++i)
            partition.push_back(a[i]);
        partition.push_back(a[last]);
        partitions.push_back(partition);

        if (pos != last)
        {
            --a[pos];
            ++pos;
            a[pos] = 1;
        }
        else
        {
            if (a[last] == sum)
                return partitions;

            for (--pos; a[pos] == 0; --pos);
            --a[pos];
            int tmp = 1 + a[last];
            ++pos;
            a[last] = 0;
            a[pos] = tmp;
        }
    }
}

string Day15_2015::part1(const string &input, bool example)
{
    vector<map<string, int>> ingredients;

    stringstream stream (input);
    string ingredientString;
    while(getline(stream, ingredientString, '\n'))
    {
        smatch matches;

        if (regex_search(ingredientString, matches, regex("([A-Za-z]+): capacity (-?[0-9]+), durability (-?[0-9]+), flavor (-?[0-9]+), texture (-?[0-9]+), calories (-?[0-9]+)")))
        {
            map<string, int> properties;
            properties["capacity"] = stoi(matches[2]);
            properties["durability"] = stoi(matches[3]);
            properties["flavor"] = stoi(matches[4]);
            properties["texture"] = stoi(matches[5]);
            properties["calories"] = stoi(matches[6]);

            ingredients.push_back(properties);
        }
    }

    auto combinations = print_partitions(100, (int) ingredients.size());

    int maxScore = INT32_MIN;
    for (const auto& combination : combinations)
    {
        int score = 1, value = 0;

        for (size_t ingredientIndex = 0; ingredientIndex < ingredients.size(); ingredientIndex++)
            value += combination[ingredientIndex] * ingredients[ingredientIndex]["capacity"];
        score *= max(value, 0);
        value = 0;

        for (size_t ingredientIndex = 0; ingredientIndex < ingredients.size(); ingredientIndex++)
            value += combination[ingredientIndex] * ingredients[ingredientIndex]["durability"];
        score *= max(value, 0);
        value = 0;

        for (size_t ingredientIndex = 0; ingredientIndex < ingredients.size(); ingredientIndex++)
            value += combination[ingredientIndex] * ingredients[ingredientIndex]["flavor"];
        score *= max(value, 0);
        value = 0;

        for (size_t ingredientIndex = 0; ingredientIndex < ingredients.size(); ingredientIndex++)
            value += combination[ingredientIndex] * ingredients[ingredientIndex]["texture"];
        score *= max(value, 0);

        maxScore = max(maxScore, score);
    }

    return to_string(maxScore);
}

string Day15_2015::part2(const string &input, bool example)
{
    vector<map<string, int>> ingredients;

    stringstream stream (input);
    string ingredientString;
    while(getline(stream, ingredientString, '\n'))
    {
        smatch matches;

        if (regex_search(ingredientString, matches, regex("([A-Za-z]+): capacity (-?[0-9]+), durability (-?[0-9]+), flavor (-?[0-9]+), texture (-?[0-9]+), calories (-?[0-9]+)")))
        {
            map<string, int> properties;
            properties["capacity"] = stoi(matches[2]);
            properties["durability"] = stoi(matches[3]);
            properties["flavor"] = stoi(matches[4]);
            properties["texture"] = stoi(matches[5]);
            properties["calories"] = stoi(matches[6]);

            ingredients.push_back(properties);
        }
    }

    auto combinations = print_partitions(100, (int) ingredients.size());

    int maxScore = INT32_MIN;
    for (const auto& combination : combinations)
    {
        int score = 1, value = 0;

        for (size_t ingredientIndex = 0; ingredientIndex < ingredients.size(); ingredientIndex++)
            value += combination[ingredientIndex] * ingredients[ingredientIndex]["capacity"];
        score *= max(value, 0);
        value = 0;

        for (size_t ingredientIndex = 0; ingredientIndex < ingredients.size(); ingredientIndex++)
            value += combination[ingredientIndex] * ingredients[ingredientIndex]["durability"];
        score *= max(value, 0);
        value = 0;

        for (size_t ingredientIndex = 0; ingredientIndex < ingredients.size(); ingredientIndex++)
            value += combination[ingredientIndex] * ingredients[ingredientIndex]["flavor"];
        score *= max(value, 0);
        value = 0;

        for (size_t ingredientIndex = 0; ingredientIndex < ingredients.size(); ingredientIndex++)
            value += combination[ingredientIndex] * ingredients[ingredientIndex]["texture"];
        score *= max(value, 0);
        value = 0;

        for (size_t ingredientIndex = 0; ingredientIndex < ingredients.size(); ingredientIndex++)
            value += combination[ingredientIndex] * ingredients[ingredientIndex]["calories"];

        if (value == 500)
            maxScore = max(maxScore, score);
    }

    return to_string(maxScore);
}
