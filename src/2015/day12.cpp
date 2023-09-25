#include "day12.h"

#include <jsoncpp/json/json.h>

Day12_2015::Day12_2015():AoCDay(2015, 12)
{
}

Day12_2015::~Day12_2015() = default;

int getJsonValue(const Json::Value& json, const string& ignore = "")
{
    int sum = 0;

    if (json.isArray())
    {
        for (const auto &value: json)
            sum += getJsonValue(value, ignore);
    }
    else if (json.isObject())
    {
        for (const auto &key: json.getMemberNames())
            if (json.get(key, 0).isString() && json.get(key, 0).asString() == ignore)
                return sum;
        for (const auto &key: json.getMemberNames())
            sum += getJsonValue(json.get(key, 0), ignore);
    }
    else if (json.isNumeric())
    {
        sum += json.asInt();
    }

    return sum;
}

string Day12_2015::part1(const string &input)
{
    Json::Value root;
    Json::Reader reader;

    if (!reader.parse(input, root))
    {
        printf("\033[39mError parsing the input string\033[0m\n");
        return "";
    }

    return to_string(getJsonValue(root));
}

string Day12_2015::part2(const string &input)
{
    Json::Value root;
    Json::Reader reader;

    if (!reader.parse(input, root))
    {
        printf("\033[39mError parsing the input string\033[0m\n");
        return "";
    }

    return to_string(getJsonValue(root, "red"));
}
