#include "day3.h"

#include <numeric>

Day3_2023::Day3_2023():AoCDay(2023, 3)
{
}

Day3_2023::~Day3_2023() = default;

string Day3_2023::part1(const string &input) {
	string _input = "467..114..\n"
					"...*......\n"
					"..35..633.\n"
					"......#...\n"
					"617*......\n"
					".....+.58.\n"
					"..592.....\n"
					"......755.\n"
					"...$......\n"
					".664.598..\n";

	vector<string> lines = aoc_string::split(input, "\n");
	lines.erase(remove_if(lines.begin(), lines.end(), [](const std::string &line) { return line.empty(); }), lines.end());

	AoC2DGrid<char> grid((int) lines[0].size(), (int) lines.size());

	for (int y = 0; y < grid.getHeight(); y++)
		for (int x = 0; x < grid.getWidth(); x++)
			grid[y][x] = lines[y][x];

	int sum = 0;
	for (int y = 0; y < grid.getHeight(); y++)
		for (int x = 0; x < grid.getWidth(); x++)
			if (isdigit(grid[y][x])) {
				bool counted = false;
				for (const auto &adjacent: grid.getAdjacentCells(x, y))
					if (!isdigit(adjacent) && adjacent != '.')
						counted = true;

				if (counted) {
					int numStart = x;
					int numEnd = x;

					while (isdigit(grid[y][numStart - 1]) && numStart - 1 >= 0)
						numStart--;
					while (isdigit(grid[y][numEnd + 1]) && numEnd + 1 < grid.getWidth())
						numEnd++;

					string num = "";
					for (int i = numStart; i <= numEnd; i++)
						num += grid[y][i];

					sum += stoi(num);
					x = numEnd;
				}
			}

    return to_string(sum);
}

string Day3_2023::part2(const string &input)
{
	string _input = "467..114..\n"
					"...*......\n"
					"..35..633.\n"
					"......#...\n"
					"617*......\n"
					".....+.58.\n"
					"..592.....\n"
					"......755.\n"
					"...$.*....\n"
					".664.598..\n";

	vector<string> lines = aoc_string::split(input, "\n");
	lines.erase(remove_if(lines.begin(), lines.end(), [](const std::string &line) { return line.empty(); }), lines.end());

	vector<pair<int, int>> gears;
	map<pair<int, int>, vector<int>> gearNumbers;
	AoC2DGrid<char> grid((int) lines[0].size(), (int) lines.size());

	for (int y = 0; y < grid.getHeight(); y++)
		for (int x = 0; x < grid.getWidth(); x++)
			grid[y][x] = lines[y][x];

	for (int y = 0; y < grid.getHeight(); y++)
		for (int x = 0; x < grid.getWidth(); x++)
			if (grid[y][x] == '*')
				gears.emplace_back(x, y);

	for (const auto &gear : gears)
	{
		for (int y = gear.second - 1; y <= gear.second + 1; y++)
		{
			for (int x = gear.first - 1; x <= gear.first + 1; x++)
			{
				if (x < 0 || x == grid.getWidth() || y < 0 || y == grid.getHeight())
					continue;

				if (isdigit(grid[y][x]))
				{
					int numStart = x;
					int numEnd = x;

					while (isdigit(grid[y][numStart - 1]) && numStart - 1 >= 0)
						numStart--;
					while (isdigit(grid[y][numEnd + 1]) && numEnd + 1 < grid.getWidth())
						numEnd++;

					string num = "";
					for (int i = numStart; i <= numEnd; i++)
						num += grid[y][i];

					gearNumbers[gear].push_back(stoi(num));
					x = numEnd;
				}
			}
		}
	}

	int sum = 0;
	for (const auto &gear : gearNumbers)
		if (gear.second.size() == 2)
			sum += (gear.second[0] * gear.second[1]);

	return to_string(sum);
}
