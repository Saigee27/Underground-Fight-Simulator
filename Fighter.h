#ifndef FIGHTER_H
#define FIGHTER_H
#include <vector>
#include <iostream>


class Fighter 
{
    public:
    std::string Name;
    std::string Nickname;
    int Strength=0;
    int Stamina=0;
    int Toughness=0;
    int Wins = 0;
    int Losses = 0;
    int Popularity;
    int WinStreak = 0;
    int LoseStreak = 0;

    int SeasonWins=0;
    int SeasonLosses=0;
    int SeasonFights=0;

    int KOWins = 0;
    int KOLosses = 0;

    int Ranking=0;
    double RankedScore=0.0;
};

extern std::vector<Fighter> roster;
void CreateRoster();
void ViewRoster();

void ImproveStats(Fighter& winner, Fighter& loser);
#endif