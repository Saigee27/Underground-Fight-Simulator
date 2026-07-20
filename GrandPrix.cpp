#include "GrandPrix.h"
#include "Fighter.h"
#include <iostream>
#include <vector>
#include <algorithm>

extern std::vector <Fighter> roster;
std::vector<std::pair<int,int>> GrandPrixMatches;


void ViewStandings()
{

    std::vector<Fighter> standings = roster;
    std::sort(standings.begin(), standings.end(),[](const Fighter& a, const Fighter& b)
    {
        if (a.SeasonWins == b.SeasonWins)
        { 
            if(a.SeasonLosses == b.SeasonLosses)
            {
                return a.Popularity > b.Popularity;
            }
            return a.SeasonLosses < b.SeasonLosses;
        }
        return a.SeasonWins > b.SeasonWins;
    });
     std::cout << "\n===== THE PIT GRAND PRIX =====\n\n";

     int rank = 1;

    for (const Fighter& fighter : standings)
    {
        std::cout
            << "#" << rank << " "
            << fighter.Name
            << " | "
            << fighter.SeasonWins
            << "-"
            << fighter.SeasonLosses
            << " | Fights: "
            << fighter.SeasonFights
            << "\n";
    rank++;
    }
    std::cout<<"\n";
}

bool HasFoughtBefore(int fighter1, int fighter2)
{
    for (const auto& match : GrandPrixMatches)
    {
        if ((match.first == fighter1 && match.second == fighter2) || (match.first == fighter2 && match.second == fighter2)) 
        {
            return true;
        }
    }
    return false;
}

void RecordMatches(int fighter1, int fighter2)
{
    GrandPrixMatches.push_back({fighter1,fighter2});
}


bool CompleteSeason()
{
    for (const Fighter& fighter : roster)
    {
        if(fighter.SeasonFights < 3)
        {
            return false;
        }
    }
    return true;
}

void CrownChampion()
{
    std::vector <Fighter> standings = roster;

    std::sort(standings.begin(), standings.end(),[](const Fighter& a, const Fighter& b)
{
    if (a.SeasonWins == b.SeasonWins)
    {
        if(a.SeasonLosses == b.SeasonLosses)
        {
            return a.Popularity > b.Popularity;
        }
        return a.SeasonLosses < b.SeasonLosses;
    }
    return a.SeasonWins > b.SeasonWins;
});

Fighter contender1 = standings[0];
Fighter contender2 = standings[1];

std::cout << "\n==============================\n";
    std::cout << "     GRAND PRIX FINAL\n";
    std::cout << "==============================\n\n";

   
    std::cout << "CHAMPIONSHIP FIGHT:\n";
    std::cout << contender1.Name
              << " VS "
              << contender2.Name
              << "\n\n";

    int BaseRating1 =
        contender1.Strength +
        contender1.Stamina +
        contender1.Toughness;

    int BaseRating2 =
        contender2.Strength +
        contender2.Stamina +
        contender2.Toughness;

    int rounds1 = 0;
    int rounds2 = 0;

    for(int round = 1; round <= 3; round++)
    {
        int performance1 =
            BaseRating1 + (rand() % 61 - 30);

        int performance2 =
            BaseRating2 + (rand() % 61 - 30);

        if(performance1 > performance2)
        {
            rounds1++;
        }
        else
        {
            rounds2++;
        }
    }

    Fighter champion;

    if(rounds1 > rounds2)
    {
        champion = contender1;
    }
    else
    {
        champion = contender2;
    }

    std::cout
        << "Champion: "
        << champion.Name
        << "\n\n";

    std::cout
        << champion.Name
        << " becomes the inaugural Grand Prix Champion!\n";

}