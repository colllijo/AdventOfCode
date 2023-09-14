#include "day4.h"

#include <regex>
#include <openssl/md5.h>
#include <iomanip>

Day4_2015::Day4_2015():AoCDay(2015, 4)
{
}

Day4_2015::~Day4_2015() = default;

std::string md5(const std::string &str)
{
    unsigned char hash[MD5_DIGEST_LENGTH];

    MD5_CTX  md5;
    MD5_Init(&md5);
    MD5_Update(&md5, str.c_str(), str.size());
    MD5_Final(hash, &md5);

    std::stringstream stream;

    for (unsigned char c : hash)
    {
        stream << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(c);
    }

    return stream.str();
}

std::string Day4_2015::part1(std::string* input)
{
    unsigned int value = 1;
    std::string hash = md5(input->substr(0, input->size() - 1) + std::to_string(value));

    while (!std::regex_match(hash, std::regex("[0]{5,}.*")))
    {
        value++;
        hash = md5(input->substr(0, input->size() - 1) + std::to_string(value));
    }

    return std::to_string(value);
}

std::string Day4_2015::part2(std::string* input)
{
    unsigned int value = 1;
    std::string hash = md5(input->substr(0, input->size() - 1) + std::to_string(value));

    while (!std::regex_match(hash, std::regex("[0]{6,}.*")))
    {
        value++;
        hash = md5(input->substr(0, input->size() - 1) + std::to_string(value));
    }

    return std::to_string(value);
}
