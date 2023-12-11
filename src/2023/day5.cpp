#include "day5.h"

#include <numeric>

Day5_2023::Day5_2023():AoCDay(2023, 5)
{
}

Day5_2023::~Day5_2023() = default;

string Day5_2023::part1(const string &input)
{
	string _input = "seeds: 79 14 55 13\n"
					"\n"
					"seed-to-soil map:\n"
					"50 98 2\n"
					"52 50 48\n"
					"\n"
					"soil-to-fertilizer map:\n"
					"0 15 37\n"
					"37 52 2\n"
					"39 0 15\n"
					"\n"
					"fertilizer-to-water map:\n"
					"49 53 8\n"
					"0 11 42\n"
					"42 0 7\n"
					"57 7 4\n"
					"\n"
					"water-to-light map:\n"
					"88 18 7\n"
					"18 25 70\n"
					"\n"
					"light-to-temperature map:\n"
					"45 77 23\n"
					"81 45 19\n"
					"68 64 13\n"
					"\n"
					"temperature-to-humidity map:\n"
					"0 69 1\n"
					"1 0 69\n"
					"\n"
					"humidity-to-location map:\n"
					"60 56 37\n"
					"56 93 4";

	vector<long> seeds;
	vector<vector<vector<string>>> maps;

	for (const auto &part : aoc_string::split(input, "\n\n"))
	{
		if (part.starts_with("seeds:"))
		{
			for (const auto & seed : aoc_string::split(aoc_string::split(part, ": ")[1], " "))
				seeds.emplace_back(stol(seed));
		}
		else
		{
			vector<vector<string>> curMap;
			for (const auto &values : aoc_string::split(aoc_string::split(part, ":\n")[1], "\n"))
			{
				vector<string> intValues;
				for (const auto &value : aoc_string::split(values, " "))
					intValues.emplace_back(value);
				curMap.emplace_back(intValues);
			}
			maps.emplace_back(curMap);
		}
	}

	vector<long> locations;
	for (const auto &seed : seeds)
	{
		long location = seed;
		for (const auto &map : maps)
		{
			// Check if current value is in a range
			for (const auto &mapping : map)
			{
				if (location >= stol(mapping[1]) && location < stol(mapping[1]) + stol(mapping[2]))
				{
					location += stol(mapping[0]) - stol(mapping[1]);
					break;
				}
			}
		}
		locations.emplace_back(location);
	}

	std::sort(locations.begin(), locations.end());

    return to_string(locations[0]);
}

struct range {
	long start;
	long end;
};

string Day5_2023::part2(const string &input)
{
	string _input = "seeds: 79 14 55 13\n"
					"\n"
					"seed-to-soil map:\n"
					"50 98 2\n"
					"52 50 48\n"
					"\n"
					"soil-to-fertilizer map:\n"
					"0 15 37\n"
					"37 52 2\n"
					"39 0 15\n"
					"\n"
					"fertilizer-to-water map:\n"
					"49 53 8\n"
					"0 11 42\n"
					"42 0 7\n"
					"57 7 4\n"
					"\n"
					"water-to-light map:\n"
					"88 18 7\n"
					"18 25 70\n"
					"\n"
					"light-to-temperature map:\n"
					"45 77 23\n"
					"81 45 19\n"
					"68 64 13\n"
					"\n"
					"temperature-to-humidity map:\n"
					"0 69 1\n"
					"1 0 69\n"
					"\n"
					"humidity-to-location map:\n"
					"60 56 37\n"
					"56 93 4\n";

	vector<range> seedRanges;
	vector<long> seeds;
	vector<vector<pair<range, range>>> maps;

	for (const auto &part : aoc_string::split(input, "\n\n"))
		if (part.starts_with("seeds:"))
			for (const auto & seed : aoc_string::split(aoc_string::split(part, ": ")[1], " "))
				seeds.emplace_back(stol(seed));
		else
		{
			vector<pair<range, range>> curMap;
			for (const auto &values : aoc_string::split(aoc_string::split(part, ":\n")[1], "\n"))
			{
				if (values.empty())
					continue;

				vector<long> longValues;
				for (const auto &value : aoc_string::split(values, " "))
					longValues.emplace_back(stol(value));
				curMap.push_back({{longValues[1], longValues[1] + longValues[2] - 1}, {longValues[0], longValues[0] + longValues[2] - 1}});
			}
			maps.emplace_back(curMap);
		}

	for (int i = 0; i < seeds.size() / 2; i++)
		seedRanges.push_back({seeds[i*2], seeds[i*2] + seeds[i*2 + 1] - 1});

	for (const auto &map : maps)
	{
		vector<range> mappedRange {};
		for (auto &range : seedRanges)
		{
			bool mapped = false;
			for (const auto &mapping : map)
			{
				if (mapping.first.start <= range.start && range.end <= mapping.first.end)
				{
					mapped = true;
					mappedRange.push_back({mapping.second.start + (range.start - mapping.first.start), mapping.second.start + (range.end - mapping.first.start)});
					break;
				}
				if (mapping.first.start <= range.start && range.start <= mapping.first.end && mapping.first.end < range.end)
				{
					mappedRange.push_back({mapping.second.start + (range.start - mapping.first.start), mapping.second.end});
					range.start = mapping.first.end + 1;
				}
				if (range.start < mapping.first.start && mapping.first.start <= range.end && range.end <= mapping.first.end)
				{
					mappedRange.push_back({mapping.second.start, mapping.second.start + (range.end - mapping.first.start)});
					range.end = mapping.first.start - 1;
				}
			}

			if (!mapped) mappedRange.push_back(range);
		}

		seedRanges = mappedRange;
	}

    return to_string(accumulate(seedRanges.begin(), seedRanges.end(), LONG_MAX, [](long acc, auto range){ return min(acc, range.start); }));
}
