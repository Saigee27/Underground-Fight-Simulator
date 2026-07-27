#ifndef BOOKMAKER_H
#define BOOKMAKER_H
#include "Fighter.h"

struct BettingOdds
{
    int Rating1;
    int Rating2;

    float Probability1;
    float Probability2;

    float Odds1;
    float Odds2;
};

int CalculatePowerRating(Fighter fighter);

float CalculateProbability(int rating,int total);

float CalculateOdds(float probability);

BettingOdds GenerateOdds(Fighter f1,Fighter f2);

void DisplayOdds(Fighter f1,Fighter f2, BettingOdds odds);

#endif