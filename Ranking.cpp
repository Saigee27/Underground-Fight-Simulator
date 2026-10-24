#include "Ranking.h"
#include "Fighter.h"
#include "fight-history.h"
#include <iostream>
#include <vector>
#include <algorithm>

std::vector <Fighter*> Rankings;





double CalculateOpponentStrength(const Fighter& opponent)
{
    if (opponent.Ranking <= 0)
    {return 0;}

    return 100.0 / opponent.Ranking;
}


double CalculateWinQuality(const FightResult& result)
{
    double quality = 0;
    double opponentStrength = 0;
    if(result.Winner == result.Fighter1)
    {
        opponentStrength = result.Fighter1OpponentStrength;
    }
    else if(result.Winner == result.Fighter2)
    {
        opponentStrength = result.Fighter2OpponentStrength;
    }
    else
    {
        return 0.0;
    }

    quality += opponentStrength * 0.5; 

    if(result.method == Method::KO || result.method == Method::TKO || result.method == Method::Submission)
    {
        quality += 30;
    }
    else if(result.method == Method::Decision)
    {
        quality += 15;
    }
    
    if (result.method == Method::KO || result.method == Method::TKO || result.method == Method::Submission)
    {
        quality += (4 - result.Round) * 5;
    }
    return quality;
}


double CalculateUpsetValue(double winnerProbability)
{
    return (1.0 - winnerProbability) * 100.0;
}



void UpdateRankings()
{
    Rankings.clear();
    for (Fighter &fighter : roster)
    {
        fighter.PreviousRanking = fighter.Ranking;
        Rankings.push_back(&fighter);
    }

    for(Fighter* fighter : Rankings)
    {
        fighter->RankedScore = CalculateRankedScore(*fighter);
    }

    std::sort(Rankings.begin(), Rankings.end(), [](Fighter* a, Fighter* b)
    {
       
        if (a->RankedScore != b->RankedScore)
        {
            return a->RankedScore > b->RankedScore;
        }

        if (a->SeasonWins != b->SeasonWins)
        {
            return a->SeasonWins > b->SeasonWins;
        }

        if (a->SeasonLosses != b->SeasonLosses)
        {
            return a->SeasonLosses < b->SeasonLosses;
        }

        return a->KOWins > b->KOWins;

    });

    for(int i=0; i<Rankings.size(); i++)
    {
        Rankings[i]->Ranking=i+1;
    }
}

void ViewRankings()
{
    if (Rankings.empty())
{
    std::cout << "\nNo rankings available yet.\n";
    return;
}

    std::cout << "\n=====================================\n";
    std::cout << "     OFFICIAL THE PIT RANKINGS\n";
    std::cout << "=====================================\n\n";


    for (Fighter* fighter : Rankings)
    {
        if(fighter->Ranking == 1)
        {
            std::cout << "THE PIT CHAMPION\n\n";
        }

        std::cout
        << "#"
        << fighter->Ranking
        << " "
        << fighter->Name;

        if (fighter->PreviousRanking == 0)
{
    std::cout << " (NEW)";
}
else if (fighter->Ranking < fighter->PreviousRanking)
{
    std::cout << " (UP "
              << fighter->PreviousRanking - fighter->Ranking
              << ")";
}
else if (fighter->Ranking > fighter->PreviousRanking)
{
    std::cout << " (DOWN "
              << fighter->Ranking - fighter->PreviousRanking
              << ")";
}
else
{
    std::cout << " (UNCHANGED)";
}

        std::cout<< "\n";

        std::cout
        << "Record : "
        << fighter->Wins
        << "-"
        << fighter->Losses
        << "\n";

        std::cout
        << "Ranked Score : "
        << fighter->RankedScore
        << "\n";

        std::cout
        << "Popularity : "
        << fighter->Popularity
        << "\n";

        std::cout
        << "KO Wins : "
        << fighter->KOWins
        << "\n";

        std::cout
        << "--------------------------------------\n";
    }

    std::cout << "\n===== TITLE CONTENDERS =====\n\n";

    int contenderCount = 0;
    for (Fighter* fighter : Rankings)
    {
        if (fighter->Ranking >= 2 && fighter->Ranking <= 4)
        {
            std::cout << "#" << fighter->Ranking
                  << " " << fighter->Name << "\n";
            contenderCount++;
        }
    }
   if (contenderCount == 0)
    {
        std::cout << "No title contenders available yet.\n";
    }
}



Match SelectMatch()
{
    Match match = {-1, -1};

    if (roster.size() < 2)
    {
        return match;
    }

    UpdateRankings();

    match.Fighter1 = rand() % roster.size();

    int bestOpponent = -1;
    int smallestRankDifference = roster.size();

    for (int i = 0; i < roster.size(); i++)
    {
        if (i == match.Fighter1)
        {
            continue;
        }

        int rankDifference = abs(
            roster[match.Fighter1].Ranking - roster[i].Ranking
        );

        if (rankDifference < smallestRankDifference)
        {
            smallestRankDifference = rankDifference;
            bestOpponent = i;
        }
    }

    match.Fighter2 = bestOpponent;
    return match;
}

double CalculateFighterStrength(const Fighter& man)
{
    int totalFighters = roster.size();
    if (totalFighters <= 1)
    {
        return 0;
    }
    return 100.0 * (totalFighters - man.Ranking) / (totalFighters - 1);
}

double CalculateRankedScore(const Fighter& fighter)
{
    double totalScore = 0.0;

    for (const FightResult& fight : fightHistory)
    {
        if (fight.event != Event::Ranked)
        {
            continue;
        }

        if (fight.Fighter1 != &fighter &&
            fight.Fighter2 != &fighter)
        {
            continue;
        }

        double resultWeight;
        double performanceWeight;

        if (fight.Winner == &fighter)
        {
            resultWeight = 1.0;
            performanceWeight =
                fight.WinQuality + fight.UpsetValue;
        }
        else if (fight.Loser == &fighter)
        {
            resultWeight = -1.0;
            performanceWeight = 20.0;
        }
        else
        {
            continue;
        }

        double OpponentStrength;

        if(fight.Fighter1 == &fighter)
        {
            OpponentStrength = fight.Fighter1OpponentStrength;
        }
        else
        {
            OpponentStrength = fight.Fighter2OpponentStrength;
        }

        double contribution =
            resultWeight *
            OpponentStrength *
            performanceWeight / 100.0;

        contribution *= CalculateRecencyWeight(fight);

        totalScore += contribution;
    }

    
    totalScore *= CalculateInactivityFactor(fighter);

    return totalScore;
}

    
