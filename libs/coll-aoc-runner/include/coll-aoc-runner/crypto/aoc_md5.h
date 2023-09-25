#ifndef COLL_AOC_RUNNER_AOC_MD5_H
#define COLL_AOC_RUNNER_AOC_MD5_H

#pragma once

#include <openssl/md5.h>
#include <iomanip>
#include <string>

namespace aoc_crypto
{
    inline static std::string md5(const std::string &str)
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
}

#endif
