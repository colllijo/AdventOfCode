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
	map<int, pair<vector<int>, vector<int>>> cards;
	vector<pair<int, pair<vector<int>, vector<int>>>> currentCards;

	stringstream stream(input);
	string line;
	while (getline(stream, line, '\n'))
	{
		int cardNum = stoi(aoc_string::split(aoc_string::split(line, "Card ")[1], ": ")[0]);

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

		cards[cardNum] = {winningNumbers, myNumbers};
	}

	for (const auto &card : cards)
	{
		currentCards.emplace_back(card);
		cardsSum++;
	}

	while (!currentCards.empty())
	{
		int cardNumber = currentCards[0].first;
		int copies = accumulate(currentCards.begin(), currentCards.end(), 0, [cardNumber](int acc, auto card){
			if (card.first == cardNumber)
				acc++;

			return acc;
		});

		int count = 0;
		for (const auto &num : currentCards[0].second.second)
			if (std::find(currentCards[0].second.first.begin(), currentCards[0].second.first.end(), num) != currentCards[0].second.first.end())
				count++;

		currentCards.erase(remove_if(currentCards.begin(), currentCards.end(), [cardNumber](auto card){ return card.first == cardNumber; }), currentCards.end());

		for (int c = 0; c < copies; c++)
		{
			for (int i = 1; i <= count; i++)
			{
				currentCards.emplace_back(cardNumber + i, cards[cardNumber + i]);
				cardsSum++;
			}
		}
	}

	return to_string(cardsSum);
}
