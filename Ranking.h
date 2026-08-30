#ifndef RANKING_H
#define RANKING_H
#include <vector>
#include "Fighter.h"
extern std::vector <Fighter*> Rankings;
void UpdateRankings();
void ViewRankings();
double CalculateFighterStrength(const Fighter& man);
struct Match
{
    int Fighter1;
    int Fighter2;
};

Match SelectMatch();
int SelectRankedFighter();
int SelectOpponent(int FighterIndex);
#endif