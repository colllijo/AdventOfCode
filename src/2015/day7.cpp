#include "day7.h"

Day7_2015::Day7_2015():AoCDay(2015, 7)
{
}

Day7_2015::~Day7_2015() = default;

string Day7_2015::part1(const string &input)
{
    map<string, unsigned short> wires;
    map<vector<string>, string> gates;

    stringstream stream (input);
    string connection;
    while (getline(stream, connection, '\n'))
    {
        gates[aoc_string::split(aoc_string::split(connection, " -> ").at(0), " ")] = aoc_string::split(connection, " -> ").at(1);
    }

    while (!gates.empty())
    {
        auto iter = gates.begin();
        while (iter != gates.end())
        {
            unsigned short lvalue;
            unsigned short rvalue;

            // Check for type of gate based on inputs (1: direct assignment, 2: not, 3: operation)
            switch (iter->first.size())
            {
                case 1:
                    if (aoc_string::isNumber(iter->first.at(0)))
                        lvalue = (unsigned short) stoi(iter->first.at(0));
                    else if (wires.find(iter->first.at(0)) != wires.end())
                        lvalue = (unsigned short) wires[iter->first.at(0)];
                    else
                        break;

                    wires[iter->second] = lvalue;
                    iter = gates.erase(iter);
                    continue;
                case 2:
                    if (aoc_string::isNumber(iter->first.at(1)))
                        lvalue = (unsigned short) stoi(iter->first.at(1));
                    else if (wires.find(iter->first.at(1)) != wires.end())
                        lvalue = (unsigned short) wires[iter->first.at(1)];
                    else
                        break;

                    if (iter->first.at(0) == "NOT")
                        wires[iter->second] = (unsigned int) ~lvalue;
                    else
                        break;

                    iter = gates.erase(iter);
                    continue;
                case 3:
                    if (aoc_string::isNumber(iter->first.at(0)))
                        lvalue = (unsigned short) stoi(iter->first.at(0));
                    else if (wires.find(iter->first.at(0)) != wires.end())
                        lvalue = (unsigned short) wires[iter->first.at(0)];
                    else
                        break;

                    if (aoc_string::isNumber(iter->first.at(2)))
                        rvalue = (unsigned short) stoi(iter->first.at(2));
                    else if (wires.find(iter->first.at(2)) != wires.end())
                        rvalue = (unsigned short) wires[iter->first.at(2)];
                    else
                        break;

                    if (iter->first.at(1) == "AND")
                        wires[iter->second] = (unsigned short) (lvalue & rvalue);
                    else if (iter->first.at(1) == "OR")
                        wires[iter->second] = (unsigned short) (lvalue | rvalue);
                    else if (iter->first.at(1) == "LSHIFT")
                        wires[iter->second] = (unsigned short) (lvalue << rvalue);
                    else if (iter->first.at(1) == "RSHIFT")
                        wires[iter->second] = (unsigned short) (lvalue >> rvalue);
                    else
                        break;

                    iter = gates.erase(iter);
                    continue;
                default:
                    break;
            }

            iter++;
        }
    }

    return to_string(wires["a"]);
}

string Day7_2015::part2(const string &input)
{
    map<string, unsigned short> wires;
    map<vector<string>, string> gates;

    stringstream stream (input);
    string connection;
    while (getline(stream, connection, '\n'))
    {
        gates[aoc_string::split(aoc_string::split(connection, " -> ").at(0), " ")] = aoc_string::split(connection, " -> ").at(1);
    }

    while (!gates.empty())
    {
        auto iter = gates.begin();
        while (iter != gates.end())
        {
            unsigned short lvalue;
            unsigned short rvalue;

            // Check for type of gate based on inputs (1: direct assignment, 2: not, 3: operation)
            switch (iter->first.size())
            {
                case 1:
                    if (aoc_string::isNumber(iter->first.at(0)))
                        lvalue = (unsigned short) stoi(iter->first.at(0));
                    else if (wires.find(iter->first.at(0)) != wires.end())
                        lvalue = (unsigned short) wires[iter->first.at(0)];
                    else
                        break;

                    // Override b with the value of a from part 1
                    if (iter->second == "b")
                        lvalue = (unsigned short) stoi(part1(input));

                    wires[iter->second] = lvalue;
                    iter = gates.erase(iter);
                    continue;
                case 2:
                    if (aoc_string::isNumber(iter->first.at(1)))
                        lvalue = (unsigned short) stoi(iter->first.at(1));
                    else if (wires.find(iter->first.at(1)) != wires.end())
                        lvalue = (unsigned short) wires[iter->first.at(1)];
                    else
                        break;

                    if (iter->first.at(0) == "NOT")
                        wires[iter->second] = (unsigned int) ~lvalue;
                    else
                        break;

                    iter = gates.erase(iter);
                    continue;
                case 3:
                    if (aoc_string::isNumber(iter->first.at(0)))
                        lvalue = (unsigned short) stoi(iter->first.at(0));
                    else if (wires.find(iter->first.at(0)) != wires.end())
                        lvalue = (unsigned short) wires[iter->first.at(0)];
                    else
                        break;

                    if (aoc_string::isNumber(iter->first.at(2)))
                        rvalue = (unsigned short) stoi(iter->first.at(2));
                    else if (wires.find(iter->first.at(2)) != wires.end())
                        rvalue = (unsigned short) wires[iter->first.at(2)];
                    else
                        break;

                    if (iter->first.at(1) == "AND")
                        wires[iter->second] = (unsigned short) (lvalue & rvalue);
                    else if (iter->first.at(1) == "OR")
                        wires[iter->second] = (unsigned short) (lvalue | rvalue);
                    else if (iter->first.at(1) == "LSHIFT")
                        wires[iter->second] = (unsigned short) (lvalue << rvalue);
                    else if (iter->first.at(1) == "RSHIFT")
                        wires[iter->second] = (unsigned short) (lvalue >> rvalue);
                    else
                        break;

                    iter = gates.erase(iter);
                    continue;
                default:
                    break;
            }

            iter++;
        }
    }

    return to_string(wires["a"]);
}
