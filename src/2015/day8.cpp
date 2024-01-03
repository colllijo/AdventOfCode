#include "day8.h"

Day8_2015::Day8_2015():AoCDay(2015, 8)
{
}

Day8_2015::~Day8_2015() = default;

string Day8_2015::part1(const string &input, bool example)
{
    int codeChars = 0;
    int memoryChars = 0;

    stringstream stream (input);
    string line;
    while(getline(stream, line, '\n'))
    {
        int memSize = 0;
        string in = line.substr(1, line.length() - 2);

        for (int index = 0; index < in.length(); index++)
        {
            memSize++;

            if (in[index] == '\\')
            {
                if (in[index + 1] == 'x')
                    index += 3;
                else
                    index += 1;
            }
        }
        codeChars += (int) line.length();
        memoryChars += memSize;
    }
    return to_string(codeChars - memoryChars);
}

string Day8_2015::part2(const string &input, bool example)
{
    int codeChars = 0;
    int encodedChars = 0;

    stringstream stream (input);
    string line;
    while(getline(stream, line, '\n'))
    {
        int encodedSize = 6;
        string in = line.substr(1, line.length() - 2);

        for (int index = 0; index < in.length(); index++)
        {
            encodedSize++;

            if (in[index] == '\\')
            {
                if (in[index + 1] == 'x')
                {
                    encodedSize += 4;
                    index += 3;
                }
                else {
                    encodedSize += 3;
                    index += 1;
                }
            }
        }
        codeChars += (int) line.length();
        encodedChars += encodedSize;
    }
    return to_string(encodedChars - codeChars);
}
