#include "aoc_input.h"

AoCInput::AoCInput() = default;

AoCInput::~AoCInput() = default;

string AoCInput::getInput(int year, int day)
{
    string input;

    ifstream inputFile ("input/" + to_string(year) + "/day" + to_string(day) + ".txt");
    if (!inputFile)
    {
        loadAuthCookie();
        downloadInput(year, day);
        inputFile.open("input/" + to_string(year) + "/day" + to_string(day) + ".txt");
    }

    if (inputFile && inputFile.is_open())
    {
        input = string((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
        return input;
    }
    else
    {
        fprintf(stderr, "\033[31mError loading the input: Input file not found please try to manually create it.\033[0m\n");
        exit(1);
    }
}

void AoCInput::loadAuthCookie()
{
    string cookie = std::getenv("CAOC_AUTH_COOKIE");
    if (!regex_match(cookie, regex("[0-9a-f]{128}")))
    {
        fprintf(stderr, "\033[31mInvalid authorisation cookie\033[0m\n");
        exit(1);
    }

    authCookie = cookie;
}

void AoCInput::downloadInput(int year, int day)
{
    string url = "https://adventofcode.com/" + to_string(year) + "/day/" + to_string(day) + "/input";
    string filename = "input/" + to_string(year) + "/day" + to_string(day) + ".txt";

    try
    {
        curlpp::Cleanup cleaner;
        curlpp::Easy request;

        curlpp::options::WriteFunctionCurlFunction writeFunction(
            [](char* ptr, size_t size, size_t nmemb, void *f)
            {
                FILE *file = (FILE *)f;
                return fwrite(ptr, size, nmemb, file);
            }
        );

        FILE *file = fopen(filename.c_str(), "wb");
        if (file == nullptr)
        {
            fprintf(stderr, "%s/n", strerror(errno));
            exit(1);
        }

        curlpp::OptionTrait<void *, CURLOPT_WRITEDATA> input(file);

        request.setOpt(writeFunction);
        request.setOpt(input);

        request.setOpt(new curlpp::options::Url(url));
        request.setOpt(new curlpp::options::Cookie("session=" + authCookie));
        request.perform();
    }
    catch (curlpp::LogicError & exception)
    {
        printf("%s\n", exception.what());
    }
    catch (curlpp::RuntimeError & exception)
    {
        printf("%s\n", exception.what());
    }
}
