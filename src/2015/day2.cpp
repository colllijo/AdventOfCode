#include "day2.h"

#include <sstream>
#include <vector>

Day2_2015::Day2_2015():AoCDay(2015, 2)
{
}

Day2_2015::~Day2_2015() = default;

std::string Day2_2015::part1(std::string* input)
{
    unsigned int squareFeetOfPaper = 0;

    std::stringstream stream (*input);
    std::string present;
    while (std::getline(stream, present, '\n'))
    {
        std::string::size_type pos = 0;
        std::string::size_type prev = 0;

        std::vector<int> boxSizes;

        while ((pos = present.find('x', prev)) != std::string::npos)
        {
            boxSizes.push_back(stoi(present.substr(prev, pos - prev)));
            prev = pos + 1;
        }
        boxSizes.push_back(stoi(present.substr(prev)));

        int front = boxSizes[0] * boxSizes[1];
        int side = boxSizes[0] * boxSizes[2];
        int bottom = boxSizes[1] * boxSizes[2];

        squareFeetOfPaper += 2*front + 2*side + 2*bottom + std::min(std::min(front, side), bottom);
    }

    return std::to_string(squareFeetOfPaper);
}

std::string Day2_2015::part2(std::string* input)
{

    unsigned int lengthOfRibbon = 0;

    std::stringstream stream (*input);
    std::string present;
    while (std::getline(stream, present, '\n'))
    {
        std::string::size_type pos = 0;
        std::string::size_type prev = 0;

        std::vector<int> boxSizes;

        while ((pos = present.find('x', prev)) != std::string::npos)
        {
            boxSizes.push_back(stoi(present.substr(prev, pos - prev)));
            prev = pos + 1;
        }
        boxSizes.push_back(stoi(present.substr(prev)));

        int largest = std::max(std::max(boxSizes[0], boxSizes[1]), boxSizes[2]);

        lengthOfRibbon += (boxSizes[0] * boxSizes[1] * boxSizes[2]) + 2*boxSizes[0] + 2*boxSizes[1] + 2*boxSizes[2] - 2*largest;
    }

    return std::to_string(lengthOfRibbon);
}
