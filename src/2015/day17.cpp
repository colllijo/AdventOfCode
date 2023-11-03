#include "day17.h"

#include <functional>
#include <numeric>

Day17_2015::Day17_2015():AoCDay(2015, 17)
{
}

Day17_2015::~Day17_2015() = default;

string Day17_2015::part1(const string &input)
{
    vector<int> containers;

    stringstream stream(input);
    string containerString;
    while(getline(stream, containerString, '\n'))
        containers.push_back(stoi(containerString));

    function<int(int, vector<int>)> combinations = [&combinations](int remaining, vector<int> containers)
    {
        if (remaining != 0)
        {
            int total = 0;
            for (size_t i = 0; i < containers.size(); i++)
            {
                if (remaining >= containers[i])
                    total += combinations(remaining - containers[i], vector<int>(containers.begin() + i + 1, containers.end()));
            }
            return total;
        }
        else
        {
            return 1;
        }
    };

    return to_string(combinations(150, containers));
}

string Day17_2015::part2(const string &input)
{
    vector<int> containers;

    stringstream stream(input);
    string containerString;
    while(getline(stream, containerString, '\n'))
        containers.push_back(stoi(containerString));

    int minCount = INT32_MAX;
    int totalCount = 0;

    function<void(int, int, vector<int>)> combinations = [&combinations, &minCount, &totalCount](int count, int remaining, vector<int> containers)
    {
        if (remaining != 0)
        {
            if (count >= minCount)
                return;

            for (size_t i = 0; i < containers.size(); i++)
            {
                if (remaining >= containers[i])
                    combinations(count + 1, remaining - containers[i], vector<int>(containers.begin() + i + 1, containers.end()));
            }
        }
        else if (count < minCount)
        {
            minCount = count;
            totalCount = 1;
        }
        else
            totalCount++;
    };

    combinations(0, 150, containers);
    return to_string(totalCount);
}
