#include "day4.h"

#include <cmath>
#include <numeric>

Day4_2023::Day4_2023():AoCDay(2023, 4)
{
}

Day4_2023::~Day4_2023() = default;

string Day4_2023::part1(const string &input)
{
	string _input = "Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53\n"
					"Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19\n"
					"Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1\n"
					"Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83\n"
					"Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36\n"
					"Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11";

	int sum = 0;

	stringstream stream(input);
	string line;
	while (getline(stream, line, '\n'))
	{
		string nums = aoc_string::split(line, ": ")[1];

		string winning = aoc_string::split(nums, " | ")[0];
		string mine = aoc_string::split(nums, " | ")[1];

		vector<int> winningNumbers{};
		for (const auto &num : aoc_string::split(winning, " "))
			if (aoc_string::isNumber(num))
				winningNumbers.emplace_back(stoi(num));
		vector<int> myNumbers{};
		for (const auto &num : aoc_string::split(mine, " "))
			if (aoc_string::isNumber(num))
				myNumbers.emplace_back(stoi(num));

		int count = 0;
		for (const auto &num : myNumbers)
			if (std::find(winningNumbers.begin(), winningNumbers.end(), num) != winningNumbers.end())
				count++;

		sum += (int) pow(2, (count - 1));
	}

    return to_string(sum);
}

string Day4_2023::part2(const string &input)
{
	string _input = "Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53\n"
					"Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19\n"
					"Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1\n"
					"Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83\n"
					"Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36\n"
					"Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11";

	int cardsSum = 0;
	map<int, pair<vector<string>, vector<string>>> cards;
	map<int, int> cardMultiplier;

	stringstream stream(input);
	string line;
	while (getline(stream, line, '\n'))
	{
		int cardNum = stoi(aoc_string::split(aoc_string::split(line, "Card ")[1], ": ")[0]);
		string nums = aoc_string::split(line, ": ")[1];
		vector<string> winningNumbers = aoc_string::split(aoc_string::split(nums, " | ")[0], " ");
        winningNumbers.erase(remove_if(winningNumbers.begin(), winningNumbers.end(), [](auto num) {return num.empty(); }), winningNumbers.end());
		vector<string> myNumbers = aoc_string::split(aoc_string::split(nums, " | ")[1], " ");
        myNumbers.erase(remove_if(myNumbers.begin(), myNumbers.end(), [](auto num) {return num.empty(); }), myNumbers.end());

		cards[cardNum] = {winningNumbers, myNumbers};
	}

    for (const auto &card : cards)
    {
        int count = 0;
        for (const auto &num : card.second.second)
            if (std::find(card.second.first.begin(), card.second.first.end(), num) != card.second.first.end())
                count++;

        for (int i = 1; i <= count; i++)
        {
            if (cardMultiplier.contains(card.first))
            {
                if (cardMultiplier.contains(card.first + i))
                    cardMultiplier[card.first + i] += cardMultiplier[card.first];
                else
                    cardMultiplier[card.first + i] = 1 + cardMultiplier[card.first];
            }
            else
            {
                if (cardMultiplier.contains(card.first + i))
                    cardMultiplier[card.first + i]++;
                else
                    cardMultiplier[card.first + i] = 2;
            }
        }

        if (cardMultiplier.contains(card.first))
            cardsSum += cardMultiplier[card.first];
        else
            cardsSum++;
    }

	return to_string(cardsSum);
}
