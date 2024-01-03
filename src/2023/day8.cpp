#include "day8.h"

#include <numeric>

Day8_2023::Day8_2023():AoCDay(2023, 8)
{
}

Day8_2023::~Day8_2023() = default;

string Day8_2023::part1(const string &input, bool example)
{
	string _input = "LLR\n"
					"\n"
					"AAA = (BBB, BBB)\n"
					"BBB = (AAA, ZZZ)\n"
					"ZZZ = (ZZZ, ZZZ)\n";

	string directions = aoc_string::split(input, "\n\n")[0];
	string currentNode = "AAA";
	map<string, pair<string, string>> nodes;

	stringstream stream(aoc_string::split(input, "\n\n")[1]);
	string line;
	while(getline(stream, line, '\n'))
	{
		string node = aoc_string::split(line, " = ")[0];
		nodes[node] = {aoc_string::split(aoc_string::split(aoc_string::split(line, "(")[1], ")")[0], ", ")[0], aoc_string::split(aoc_string::split(aoc_string::split(line, "(")[1], ")")[0], ", ")[1]};
	}

	int steps = 0;
    while ((currentNode = directions[steps++ % directions.size()] == 'L' ? nodes[currentNode].first : nodes[currentNode].second) != "ZZZ");

    return to_string(steps);
}

string Day8_2023::part2(const string &input, bool example)
{
	string _input = "LR\n"
					"\n"
					"11A = (11B, XXX)\n"
					"11B = (XXX, 11Z)\n"
					"11Z = (11B, XXX)\n"
					"22A = (22B, XXX)\n"
					"22B = (22C, 22C)\n"
					"22C = (22Z, 22Z)\n"
					"22Z = (22B, 22B)\n"
					"XXX = (XXX, XXX)\n";

	string directions = aoc_string::split(input, "\n\n")[0];
	vector<string> currentNodes;
	map<string, pair<string, string>> nodes;

	stringstream stream(aoc_string::split(input, "\n\n")[1]);
	string line;
	while(getline(stream, line, '\n'))
	{
		string node = aoc_string::split(line, " = ")[0];
		if (node.ends_with("A"))
			currentNodes.push_back(node);
		nodes[node] = {aoc_string::split(aoc_string::split(aoc_string::split(line, "(")[1], ")")[0], ", ")[0], aoc_string::split(aoc_string::split(aoc_string::split(line, "(")[1], ")")[0], ", ")[1]};
	}

	unsigned long result = 1;
	for (auto &start : currentNodes)
	{
		int steps = 0;
        while (!(start = directions[steps++ % directions.size()] == 'L' ? nodes[start].first : nodes[start].second).ends_with("Z"));
		result = lcm(result, steps);
	}

	return to_string(result);
}
