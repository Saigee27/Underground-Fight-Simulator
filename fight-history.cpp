#include "fight-history.h"
#include <iostream>
std::vector <FightResult> fightHistory;
void RecordFights(const FightResult& result)
{
    fightHistory.push_back(result);
}
void showFightHistory()
{
    std::cout << "\n=====================================\n";
    std::cout << "          THE PIT FIGHT HISTORY\n";
    std::cout << "=====================================\n\n";

    for (const FightResult& result : fightHistory)
    {
        std::cout << result.Fighter1->Name
                  << " vs "
                  << result.Fighter2->Name
                  << "\n";

        std::cout << "Winner : "
                  << result.Winner->Name
                  << "\n";

        std::cout << "Event : ";

        if (result.event == Event::Grand_Prix)
            std::cout << "Grand Prix\n";
        else
            std::cout << "Ranked\n";

        std::cout << "Method : ";

        if (result.method == Method::KO)
            std::cout << "KO\n";
        else
            std::cout << "Decision\n";

        
        std::cout << "-------------------------------------\n";
    }
}


double CalculateRecentForm(const Fighter& fighter)
    {
        std::vector<const FightResult*> recentFights;
        for (const FightResult& fight : fightHistory)
        {
            if (fight.event != Event::Ranked)
            {
                continue;
            }
            if (fight.Fighter1 != &fighter && fight.Fighter2 != &fighter)
            {
                continue;
            }
            recentFights.push_back(&fight);
        }

        int start = 0;

        if (recentFights.size() > 5)
        {
            start = recentFights.size() - 5;
        }
        double recentForm = 0;
        int weight = 1;

        for (int i = start; i < recentFights.size(); i++)
        {
            const FightResult& fight = *recentFights[i];

            if (fight.Winner == &fighter)
            {
                recentForm += weight;
            }
            else 
            {
                recentForm -= weight;
            }
            weight++;
        }
        return recentForm;
    }


double CalculateTrajectoryScore(const Fighter& fighter)
{
    double recentForm = CalculateRecentForm(fighter);
    double trajectoryScore = ((recentForm + 15.0) / 30.0) * 100.0;
    return trajectoryScore;
}

std::string GetTrajectoryState(const Fighter& fighter)
{
    double score = CalculateTrajectoryScore(fighter);

    if (score <= 30)
    {
        return "Declining";
    }
    else if (score <= 45)
    {
        return "Cold";
    }
    else if (score <= 55)
    {
        return "Stable";
    }
    else if (score <= 70)
    {
        return "Improving";
    }
    else
    {
        return "Rising";
    }
}