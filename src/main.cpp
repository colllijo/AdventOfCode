#include <iostream>
#include <unistd.h>
#include <coll-aoc-runner/aoc_runner.h>

// Include all the days
#include "2015/days.h"

using namespace std;

void setYears(AoCYears *years);
// SetDays Functions
void setDays2015(AoCYears *years);

AoCDelimiter getCommandlineOptions(int argc, char *argv[]);

int main(int argc, char *argv[])
{
	AoCDelimiter delimiter = getCommandlineOptions(argc, argv);

	auto *runner = new AoCRunner(&setYears);
	runner->run(&delimiter);

	return 0;
}

AoCDelimiter getCommandlineOptions(int argc, char *argv[])
{
	AoCDelimiter aocDelimiter;

	// Retrieve commandline options given to the program
	int opt;
	while ((opt = getopt(argc, argv, "y:d:p:")) != -1)
	{
		try
		{
			switch (opt)
			{
				case 'y':
					aocDelimiter.year = stoi(optarg);
					break;
				case 'd':
					aocDelimiter.day = stoi(optarg);
					break;
				case 'p':
					aocDelimiter.part = stoi(optarg);
					break;
				default:
					break;
			}
		}
		catch (const invalid_argument &exception)
		{
			fprintf(stderr, "\033[31mInvalid argument: Received invalid argument for parameter -%c please make sure to supply an integer number.\033[0m", opt);
			exit(1);
		}
		catch (const out_of_range &exception)
		{
			fprintf(stderr, "\033[31mOut of range: Received invalid argument for parameter -%c please make sure to supply an integer number.\033[0m", opt);
			exit(1);
		}
	}

	// Check that the commandline options are in the correct ranges
	if (aocDelimiter.year != -1 && aocDelimiter.year < 2015)
	{
		fprintf(stderr, "\033[33mNo Advent of Code before 2015.\033[0m");
		exit(1);
	}
	else if (aocDelimiter.day != -1 && (aocDelimiter.day < 1 || aocDelimiter.day > 25))
	{
		fprintf(stderr, "\033[31mInvalid argument for day please only use the days from 1 to 25.\033[0m");
		exit(1);
	}
	else if (aocDelimiter.part != -1 && (aocDelimiter.part < 1 || aocDelimiter.part > 2))
	{
		fprintf(stderr, "\033[31mInvalid argument for part please only use 1 or 2.\033[0m");
		exit(1);
	}

	return aocDelimiter;
}

void setYears(AoCYears *years)
{
	setDays2015(years);
}

void setDays2015(AoCYears *years)
{
	years->setDay(2015, 1, new Day1_2015());
	years->setDay(2015, 2, new Day2_2015());
	years->setDay(2015, 3, new Day3_2015());
	years->setDay(2015, 4, new Day4_2015());
	years->setDay(2015, 5, new Day5_2015());
	years->setDay(2015, 6, new Day6_2015());
	years->setDay(2015, 7, new Day7_2015());
	years->setDay(2015, 8, new Day8_2015());
	years->setDay(2015, 9, new Day9_2015());
	years->setDay(2015, 10, new Day10_2015());
	years->setDay(2015, 11, new Day11_2015());
	years->setDay(2015, 12, new Day12_2015());
	years->setDay(2015, 13, new Day13_2015());
	years->setDay(2015, 14, new Day14_2015());
	years->setDay(2015, 15, new Day15_2015());
	years->setDay(2015, 16, new Day16_2015());
	years->setDay(2015, 17, new Day17_2015());
	years->setDay(2015, 18, new Day18_2015());
	years->setDay(2015, 19, new Day19_2015());
	years->setDay(2015, 20, new Day20_2015());
	years->setDay(2015, 21, new Day21_2015());
	years->setDay(2015, 22, new Day22_2015());
	years->setDay(2015, 23, new Day23_2015());
	years->setDay(2015, 24, new Day24_2015());
	years->setDay(2015, 25, new Day25_2015());
}
