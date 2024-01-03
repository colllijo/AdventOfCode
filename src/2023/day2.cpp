#include "day2.h"

Day2_2023::Day2_2023():AoCDay(2023, 2)
{
}

Day2_2023::~Day2_2023() = default;

string Day2_2023::part1(const string &input, bool example)
{
	int sum = 0;
	string _input = "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green\n"
					"Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue\n"
					"Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red\n"
					"Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red\n"
					"Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green";

	stringstream stream(input);
	string line;
	while (getline(stream, line, '\n'))
	{
		int gameId = stoi(aoc_string::split(aoc_string::split(line, ":")[0], "Game ")[1]);

		string cubes = aoc_string::split(line, ": ")[1];
		bool possible = true;
		for (const auto &set : aoc_string::split(cubes, "; "))
		{
			int reds = 0;
			int blues = 0;
			int greens = 0;

			for (const auto &color : aoc_string::split(set, ", "))
			{
				if (aoc_string::split(color, " ")[1] == "red")
					reds += stoi(aoc_string::split(color, " ")[0]);
				if (aoc_string::split(color, " ")[1] == "green")
					greens += stoi(aoc_string::split(color, " ")[0]);
				if (aoc_string::split(color, " ")[1] == "blue")
					blues += stoi(aoc_string::split(color, " ")[0]);
			}

			if (reds > 12 || greens > 13 || blues > 14)
				possible = false;
		}

		if (possible)
			sum += gameId;
	}

    return to_string(sum);
}

string Day2_2023::part2(const string &input, bool example)
{
	int sum = 0;
	string _input = "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green\n"
					"Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue\n"
					"Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red\n"
					"Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red\n"
					"Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green";

	stringstream stream(input);
	string line;
	while (getline(stream, line, '\n'))
	{
		string cubes = aoc_string::split(line, ": ")[1];
		int maxReds = 0;
		int maxGreens = 0;
		int maxBlues = 0;
		for (const auto &set : aoc_string::split(cubes, "; "))
		{

			for (const auto &color : aoc_string::split(set, ", "))
			{
				if (aoc_string::split(color, " ")[1] == "red" && stoi(aoc_string::split(color, " ")[0]) > maxReds)
					maxReds = stoi(aoc_string::split(color, " ")[0]);
				if (aoc_string::split(color, " ")[1] == "green" && stoi(aoc_string::split(color, " ")[0]) > maxGreens)
					maxGreens = stoi(aoc_string::split(color, " ")[0]);
				if (aoc_string::split(color, " ")[1] == "blue" && stoi(aoc_string::split(color, " ")[0]) > maxBlues)
					maxBlues = stoi(aoc_string::split(color, " ")[0]);
			}

		}
		sum += maxReds * maxGreens * maxBlues;
	}

	return to_string(sum);
}
