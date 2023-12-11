#include "day7.h"

#include <math.h>
#include <numeric>

Day7_2023::Day7_2023():AoCDay(2023, 7)
{
}

Day7_2023::~Day7_2023() = default;

enum Type
{
    FIVE_OF_A_KIND,
    FOUR_OF_A_KIND,
    FULL_HOUSE,
    THREE_OF_A_KIND,
    TWO_PAIR,
    PAIR,
    HIGH_CARD
};

struct Hand
{
    string cards;
    Type type;
    int bid;
};

string Day7_2023::part1(const string &input)
{
    string _input = "32T3K 765\n"
                    "T55J5 684\n"
                    "KK677 28\n"
                    "KTJJT 220\n"
                    "QQQJA 483";

    vector<Hand> hands;

    stringstream stream(input);
    string line;
    while (getline(stream, line, '\n'))
    {
        string hand = aoc_string::split(line, " ")[0];
        Type type = HIGH_CARD;

        map<char, int> cards = accumulate(hand.begin(), hand.end(), map<char, int>{}, [](map<char, int> cards, char card){ cards.contains(card) ? cards[card]++ : cards[card] = 1; return cards;});
        vector<int> count = accumulate(cards.begin(), cards.end(), vector<int>{}, [](vector<int> acc, auto card){ acc.push_back(card.second); return acc; });
        std::sort(count.begin(), count.end());

        if (count == vector<int>{5})
            type = FIVE_OF_A_KIND;
        else if (count == vector<int>{1, 4})
            type = FOUR_OF_A_KIND;
        else if (count == vector<int>{2, 3})
            type = FULL_HOUSE;
        else if (count == vector<int>{1, 1, 3})
            type = THREE_OF_A_KIND;
        else if (count == vector<int>{1, 2, 2})
            type = TWO_PAIR;
        else if (count == vector<int>{1, 1, 1, 2})
            type = PAIR;

        hands.push_back({hand, type, stoi(aoc_string::split(line, " ")[1])});
    }

    std::sort(hands.begin(), hands.end(), [](Hand hand, Hand other){
        if (hand.type != other.type) return hand.type > other.type;

        for (int i = 0; i < hand.cards.size(); i++)
            if (hand.cards[i] != other.cards[i]) return string("AKQJT98765432").find(hand.cards[i]) > string("AKQJT98765432").find(other.cards[i]);
        return true;
    });

    int sum = 0;
    for (int i = 0; i < hands.size();)
        sum += hands[i++].bid * i;

    return to_string(sum);
}

string Day7_2023::part2(const string &input)
{
    string _input = "32T3K 765\n"
                    "T55J5 684\n"
                    "KK677 28\n"
                    "KTJJT 220\n"
                    "QQQJA 483";

    vector<Hand> hands;

    stringstream stream(input);
    string line;
    while (getline(stream, line, '\n'))
    {
        string hand = aoc_string::split(line, " ")[0];

        if (hand == "55Q55")
            cout << endl;

        vector<string> jokerHands{hand};
        for (int i = 0; i < accumulate(hand.begin(), hand.end(), 0, [](int acc, auto card){ return acc + (card == 'J' ? 1 : 0); }); i++)
            jokerHands = accumulate(jokerHands.begin(), jokerHands.end(), vector<string>{}, [](vector<string> acc, string hand){
               for (const auto &c : {"2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"})
               {
                   string tmp = hand;
                   tmp.replace(hand.find('J'), 1, c);
                   acc.push_back(tmp);
               }

               return acc;
            });

        Type type = accumulate(jokerHands.begin(), jokerHands.end(), HIGH_CARD, [](Type acc, string jokerHand){
            map<char, int> cards = accumulate(jokerHand.begin(), jokerHand.end(), map<char, int>{}, [](map<char, int> cards, char card){ cards.contains(card) ? cards[card]++ : cards[card] = 1; return cards;});
            vector<int> count = accumulate(cards.begin(), cards.end(), vector<int>{}, [](vector<int> acc, auto card){ acc.push_back(card.second); return acc; });
            std::sort(count.begin(), count.end());

            if (count == vector<int>{5})
                acc = min(acc, FIVE_OF_A_KIND);
            else if (count == vector<int>{1, 4})
                acc = min(acc, FOUR_OF_A_KIND);
            else if (count == vector<int>{2, 3})
                acc = min(acc, FULL_HOUSE);
            else if (count == vector<int>{1, 1, 3})
                acc = min(acc, THREE_OF_A_KIND);
            else if (count == vector<int>{1, 2, 2})
                acc = min(acc, TWO_PAIR);
            else if (count == vector<int>{1, 1, 1, 2})
                acc = min(acc, PAIR);
            return acc;
        });
        hands.push_back({hand, type, stoi(aoc_string::split(line, " ")[1])});
    }

    std::sort(hands.begin(), hands.end(), [](Hand hand, Hand other){
        if (hand.type != other.type) return hand.type > other.type;

        for (int i = 0; i < hand.cards.size(); i++)
            if (hand.cards[i] != other.cards[i]) return string("AKQT98765432J").find(hand.cards[i]) > string("AKQT98765432J").find(other.cards[i]);
        return true;
    });

    int sum = 0;
    for (int i = 0; i < hands.size();)
        sum += hands[i++].bid * i;

    return to_string(sum);
}
