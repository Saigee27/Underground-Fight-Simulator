#include "Ranking.h"
#include "fightnight.h"
#include <iostream>
#include <vector>
#include <algorithm>
std::vector <Fighter*> Rankings;

void UpdateRankings()
{
    Rankings.clear();
    for (Fighter &fighter : roster)
    {
        Rankings.push_back(&fighter);
    }

    std::sort(Rankings.begin(), Rankings.end(), [](Fighter* a, Fighter* b)
    {
        if (a->SeasonWins != b->SeasonWins)
        {
            return a->SeasonWins > b->SeasonWins;
        }
        if (a->SeasonLosses != b->SeasonLosses)
        {
            return a->SeasonLosses < b->SeasonLosses;
        }
        if (a->Popularity != b->Popularity)
        {
            return a->Popularity > b->Popularity;
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
        << fighter->Name
        << "\n";

        std::cout
        << "Record : "
        << fighter->Wins
        << "-"
        << fighter->Losses
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
}
