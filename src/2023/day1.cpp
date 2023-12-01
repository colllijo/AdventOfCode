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

		for (const auto &c : line) {
			if (isdigit(c))
			{
				last = c;
				if (first == '\0')
					first = c;
			}
		}

		cout << first << last << endl;

		sum += (10 * (first - '0')) + last - '0';
	}

    return to_string(sum);
}

string Day1_2023::part2(const string &input)
{
	int sum = 0;

	stringstream stream (input);
	string line;
	while (getline(stream, line, '\n'))
	{
		char first = '\0';
		char last = '\0';

		while (!line.empty())
		{
			if (line.starts_with("one"))
			{
				last = '1';
				if (first == '\0')
					first = '1';
			}
			else if (line.starts_with("two"))
			{
				last = '2';
				if (first == '\0')
					first = '2';
			}
			else if (line.starts_with("three"))
			{
				last = '3';
				if (first == '\0')
					first = '3';
			}
			else if (line.starts_with("four"))
			{
				last = '4';
				if (first == '\0')
					first = '4';
			}
			else if (line.starts_with("five"))
			{
				last = '5';
				if (first == '\0')
					first = '5';
			}
			else if (line.starts_with("six"))
			{
				last = '6';
				if (first == '\0')
					first = '6';
			}
			else if (line.starts_with("seven"))
			{
				last = '7';
				if (first == '\0')
					first = '7';
			}
			else if (line.starts_with("eight"))
			{
				last = '8';
				if (first == '\0')
					first = '8';
			}
			else if (line.starts_with("nine"))
			{
				last = '9';
				if (first == '\0')
					first = '9';
			}
			else if (isdigit(line[0]))
			{
				last = line[0];
				if (first == '\0')
					first = line[0];
			}

			line = line.substr(1);
		}

		cout << first << last << endl;

		sum += (10 * (first - '0')) + last - '0';
	}

	return to_string(sum);
}
