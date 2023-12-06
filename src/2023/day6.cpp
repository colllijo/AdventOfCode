#include "day6.h"

#include <numeric>

Day6_2023::Day6_2023():AoCDay(2023, 6)
{
}

Day6_2023::~Day6_2023() = default;

string Day6_2023::part1(const string &input)
{
	string _input = "Time:      7  15   30\n"
					"Distance:  9  40  200";

	int result = 1;

	vector<int> times;
	vector<int> distances;


	stringstream stream(input);
	string line;
	while(getline(stream, line, '\n'))
	{
		if (line.starts_with("Time: "))
			for (const auto &part : aoc_string::split(aoc_string::split(line, "Time: ")[1], " "))
			{
				if (aoc_string::isNumber(part))
					times.push_back(stoi(part));
			}
		if (line.starts_with("Distance: "))
			for (const auto &part : aoc_string::split(aoc_string::split(line, "Distance: ")[1], " "))
				if (aoc_string::isNumber(part))
					distances.push_back(stoi(part));
	}

	for (size_t i = 0; i < times.size(); i++)
	{
		int winning = 0;
		for (int time = 0; time <= times[i]; time++)
		{
			int distance = time * (times[i] - time);

			if (distance > distances[i])
				winning++;
		}

		result *= winning;
	}

    return to_string(result);
}

string Day6_2023::part2(const string &input)
{
	string _input = "Time:      7  15   30\n"
					"Distance:  9  40  200";

	long time;
	long distance;

	stringstream stream(input);
	string line;
	while(getline(stream, line, '\n'))
	{
		if (line.starts_with("Time: "))
		{
			string timeString = aoc_string::split(line, ": ")[1];
			timeString.erase(remove_if(timeString.begin(), timeString.end(), [](auto c){ return isspace(c); }), timeString.end());
			time = stol(timeString);
		}
		if (line.starts_with("Distance: "))
		{
			string distanceString = aoc_string::split(line, ": ")[1];
			distanceString.erase(remove_if(distanceString.begin(), distanceString.end(), [](auto c){ return isspace(c); }), distanceString.end());
			distance = stol(distanceString);
		}
	}

	int winning = 0;
	for (long t = 0; t <= time; t++)
	{
		long d = t * (time - t);

		if (d > distance)
			winning++;
	}

	return to_string(winning);
}
