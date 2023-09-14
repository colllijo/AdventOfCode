#include "aoc_runner.h"

AoCRunner::AoCRunner(const function<void(AoCYears*)>& setYears): aocYears(new AoCYears())
{
    setYears(aocYears);

    aocInput = new AoCInput();
}

AoCRunner::~AoCRunner()
{
    delete aocYears;
    delete aocInput;
}

void AoCRunner::run(AoCDelimiter* delimiter)
{
    // Make sure the part specifier only works when a specific day is run
    if (delimiter->year == -1 || delimiter->day == -1)
    {
        delimiter->part = -1;
    }

    for (auto &day : getDaysToRun(delimiter))
    {
        // Get aocInput for day
        string input = this->aocInput->getInput(day.second->getYear(), day.second->getDay());

        switch (delimiter->part)
        {
            case 1:
                runPart(AoCDelimiter(day.second->getYear(), day.second->getDay(), 1), day.second->part1(&input));
                break;
            case 2:
                runPart(AoCDelimiter(day.second->getYear(), day.second->getDay(), 2), day.second->part2(&input));
                break;
            default:
                runPart(AoCDelimiter(day.second->getYear(), day.second->getDay(), 1), day.second->part1(&input));
                runPart(AoCDelimiter(day.second->getYear(), day.second->getDay(), 2), day.second->part2(&input));
                break;
        }
    }
}

void AoCRunner::runPart(AoCDelimiter delimiter, const string &result)
{
    if (!result.empty())
    {
        printf("\033[92m*** Part %i of day %i in year %i Result: %s\033[0m\n", delimiter.part, delimiter.day, delimiter.year, result.c_str());

        string clipCommand = "echo -n " + result + " | clip.exe";
        system(clipCommand.c_str());
    }
}

map<int, AoCDay *> AoCRunner::getDaysToRun(AoCDelimiter *delimiter)
{
    map<int, AoCDay*> daysToRun;

    if (delimiter->year != -1)
    {
        if (delimiter->day != -1)
        {
            AoCDay *day = aocYears->getDay(delimiter->year, delimiter->day);
            if (day != nullptr)
            {
                daysToRun[(int) daysToRun.size()] = day;
            }
        }
        else
        {
            AoCDays *days = aocYears->getYear(delimiter->year);
            if (days != nullptr)
            {
                for (auto &dayIndex : days->getDays())
                {
                    AoCDay *day = aocYears->getDay(delimiter->year, dayIndex);
                    if (day != nullptr)
                    {
                        daysToRun[(int) daysToRun.size()] = day;
                    }
                }
            }
        }
    } else
    {
        for (auto &yearIndex : aocYears->getYears())
        {
            for (auto &dayIndex : aocYears->getYear(yearIndex)->getDays())
            {
                AoCDay *day = aocYears->getDay(yearIndex, dayIndex);
                if (day != nullptr)
                {
                    daysToRun[(int) daysToRun.size()] = day;
                }
            }
        }
    }

    return daysToRun;
}
