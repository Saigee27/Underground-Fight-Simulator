#include "GrandPrix.h"
#include "Commentary.h"
#include "Fighter.h"
#include "Bank.h"
#include "Timeline.h"
#include "Popularity.h"
#include "fightnight.h"
#include "Bookmaker.h"
#include "Ranking.h"
#include "knockoutsystem.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

extern std::vector <Fighter> roster;
std::vector<std::pair<int,int>> GrandPrixMatches;
std::vector<std::pair<int,int>> GrandPrixSchedule;
int GrandPrixFightIndex = 0;


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

void GenerateGrandPrixSchedule()
{
    GrandPrixSchedule.clear();
    GrandPrixFightIndex = 0;

    std::vector<int> fighters;

    for (int i = 0; i < roster.size(); i++)
    {
        fighters.push_back(i);
    }

    int fixed = fighters[0];

    for (int round = 0; round < 3; round++)
    {
        GrandPrixSchedule.push_back(
            {fixed, fighters[9]}
        );

        GrandPrixSchedule.push_back(
            {fighters[1], fighters[8]}
        );

        GrandPrixSchedule.push_back(
            {fighters[2], fighters[7]}
        );

        GrandPrixSchedule.push_back(
            {fighters[3], fighters[6]}
        );

        GrandPrixSchedule.push_back(
            {fighters[4], fighters[5]}
        );

        int last = fighters.back();

        for (int i = 9; i > 1; i--)
        {
            fighters[i] = fighters[i - 1];
        }

        fighters[1] = last;
    }

    std::random_device rd;
    std::mt19937 generator(rd());

    std::shuffle(
        GrandPrixSchedule.begin(),
        GrandPrixSchedule.end(),
        generator
    );
}


bool GetNextGrandPrixMatch(int& fighter1, int& fighter2)
{
    if (GrandPrixFightIndex >= GrandPrixSchedule.size())
    {
        return false;
    }

    fighter1 = GrandPrixSchedule[GrandPrixFightIndex].first;
    fighter2 = GrandPrixSchedule[GrandPrixFightIndex].second;

    GrandPrixFightIndex++;

    return true;
}




bool HasFoughtBefore(int fighter1, int fighter2)
{
    for (const auto& match : GrandPrixMatches)
    {
        if ((match.first == fighter1 && match.second == fighter2) || (match.first == fighter2 && match.second == fighter1)) 
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

std::vector <int> GetTopFour()
{
    std::vector <int> indices;
    for(int i=0; i<roster.size(); i++)
    {
        indices.push_back(i);
    }
    std::sort(indices.begin(), indices.end(), [](int a, int b)
    {
        if(roster[a].SeasonWins == roster[b].SeasonWins)
        {
            if(roster[a].SeasonLosses == roster[b].SeasonLosses)
            {
                return roster[a].Popularity > roster[b].Popularity;
            }
            return roster[a].SeasonLosses < roster[b].SeasonLosses;
        }
        return roster[a].SeasonWins > roster[b].SeasonWins;
    });
    indices.resize(4);
    return indices;
}
