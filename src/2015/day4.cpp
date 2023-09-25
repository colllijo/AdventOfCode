#include "day4.h"

#include <thread>

Day4_2015::Day4_2015():AoCDay(2015, 4)
{
}

Day4_2015::~Day4_2015() = default;

string Day4_2015::part1(const string &input)
{
    static unsigned int result = 0;
    auto hasher = [](const string &input, unsigned int start, int increment)
    {
        unsigned int value = start;

        string hash = aoc_crypto::md5(input.substr(0, input.size() - 1) + std::to_string(value));
        while (!hash.starts_with("00000") && result == 0)
        {
            value += increment;
            hash = aoc_crypto::md5(input.substr(0, input.size() - 1) + std::to_string(value));
        }

        if (result == 0)
        {
            result = value;
        }
    };

     std::thread hashing_thread_1(hasher, input, 1, 8);
     std::thread hashing_thread_2(hasher, input, 2, 8);
     std::thread hashing_thread_3(hasher, input, 3, 8);
     std::thread hashing_thread_4(hasher, input, 4, 8);
     std::thread hashing_thread_5(hasher, input, 5, 8);
     std::thread hashing_thread_6(hasher, input, 6, 8);
     std::thread hashing_thread_7(hasher, input, 7, 8);
     std::thread hashing_thread_8(hasher, input, 8, 8);

     hashing_thread_1.join();
     hashing_thread_2.join();
     hashing_thread_3.join();
     hashing_thread_4.join();
     hashing_thread_5.join();
     hashing_thread_6.join();
     hashing_thread_7.join();
     hashing_thread_8.join();

    return std::to_string(result);
}

string Day4_2015::part2(const string &input)
{
    static unsigned int result = 0;
    auto hasher = [](const string &input, unsigned int start, int increment)
    {
        unsigned int value = start;

        string hash = aoc_crypto::md5(input.substr(0, input.size() - 1) + std::to_string(value));
        while (!hash.starts_with("000000") && result == 0)
        {
            value += increment;
            hash = aoc_crypto::md5(input.substr(0, input.size() - 1) + std::to_string(value));
        }

        if (result == 0)
        {
            result = value;
        }
    };

    std::thread hashing_thread_1(hasher, input, 1, 8);
    std::thread hashing_thread_2(hasher, input, 2, 8);
    std::thread hashing_thread_3(hasher, input, 3, 8);
    std::thread hashing_thread_4(hasher, input, 4, 8);
    std::thread hashing_thread_5(hasher, input, 5, 8);
    std::thread hashing_thread_6(hasher, input, 6, 8);
    std::thread hashing_thread_7(hasher, input, 7, 8);
    std::thread hashing_thread_8(hasher, input, 8, 8);

    hashing_thread_1.join();
    hashing_thread_2.join();
    hashing_thread_3.join();
    hashing_thread_4.join();
    hashing_thread_5.join();
    hashing_thread_6.join();
    hashing_thread_7.join();
    hashing_thread_8.join();

    return std::to_string(result);
}
