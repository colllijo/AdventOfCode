#include "aoc_input.h"

AoCInput::AoCInput()
{
	// Make sure the input directory exists
	if (!filesystem::is_directory("input"))
		filesystem::create_directory("input");
};

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
        if (input.ends_with('\n'))
            input.pop_back();
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
    char *cookie = std::getenv("CAOC_AUTH_COOKIE");
	if (cookie == nullptr)
	{
		fprintf(stderr, "\033[31mAuthorisation cookie not set.\nPlease set the `CAOC_AUTH_COOKIE` environment variable.\033[0m\n");
		exit(1);
	}
    else if (!regex_match(cookie, regex("[0-9a-f]{128}")))
    {
        fprintf(stderr, "\033[31mInvalid authorisation cookie\033[0m\n");
        exit(1);
    }

    authCookie = cookie;
}

void AoCInput::downloadInput(int year, int day)
{
	// Make sure the directory for the year exists
	if (!filesystem::is_directory("input/" + to_string(year)))
		filesystem::create_directory("input/" + to_string(year));

    string url = "https://adventofcode.com/" + to_string(year) + "/day/" + to_string(day) + "/input";
    string filename = "input/" + to_string(year) + "/day" + to_string(day) + ".txt";

    try
    {
        curlpp::Cleanup cleaner;
        curlpp::Easy request;

		ofstream file(filename.c_str(), ios::binary | ios::out);
		if (!file)
		{
            fprintf(stderr, "Could not open file to write input/n");
            exit(1);
		}

		request.setOpt(new curlpp::options::WriteStream(&file));

        request.setOpt(new curlpp::options::Url(url));
        request.setOpt(new curlpp::options::Cookie("session=" + authCookie));
        request.perform();

		file.close();
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
