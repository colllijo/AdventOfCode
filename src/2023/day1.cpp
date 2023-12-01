#include "day1.h"

Day1_2023::Day1_2023():AoCDay(2023, 1)
{
}

Day1_2023::~Day1_2023() = default;

string Day1_2023::part1(const string &input)
{
	int sum = 0;

	stringstream stream (input);
	string line;
	while (getline(stream, line, '\n'))
	{
		char first = '\0';
		char last = '\0';

		for (const auto &c : line)
			if (isdigit(c))
			{
				last = c;
				if (first == '\0')
					first = c;
			}

		sum += (10 * (first - '0')) + last - '0';
	}

    return to_string(sum);
}

string Day1_2023::part2(const string &input)
{
	int sum = 0;
    map<string, char> spelledNumbers {
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

	stringstream stream (input);
	string line;
	while (getline(stream, line, '\n'))
	{
		char first = '\0';
		char last = '\0';

		while (!line.empty())
		{
            for (const auto &entry : spelledNumbers)
            {
                if (line.starts_with(entry.first))
                {
                    last = entry.second;
                    if (first == '\0')
                        first = entry.second;

                    break;
                }
            }
			if (isdigit(line[0]))
			{
				last = line[0];
				if (first == '\0')
					first = line[0];
			}

			line = line.substr(1);
		}

		sum += (10 * (first - '0')) + last - '0';
	}

	return to_string(sum);
}
