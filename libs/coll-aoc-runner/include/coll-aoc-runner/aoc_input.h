#ifndef COLL_AOC_RUNNER_AOC_INPUT_H
#define COLL_AOC_RUNNER_AOC_INPUT_H

#include <fstream>
#include <streambuf>
#include <string>
#include <regex>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>

using namespace std;

class AoCInput {
private:
    string authCookie;

    void loadAuthCookie();
    void downloadInput(int year, int day);
public:
    AoCInput();
    ~AoCInput();

    string getInput(int year, int day);
};

#endif
