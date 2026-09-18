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

struct Bettingmarket
{
    int MoneyonFighter1;
    int MoneyonFighter2;
};

Bettingmarket GenerateMarket();

int CalculateMarketScore(Fighter fighter);

float CalculateMarketShare(int moneyonFighter, int totalMoney);

float AdjustProbabilityForMarket(float probability, float marketshare);

float CalculateProbability(int rating1, int rating2);

float CalculateOdds(float probability);

BettingOdds GenerateOdds(Fighter f1,Fighter f2);

void DisplayOdds(Fighter f1,Fighter f2, BettingOdds odds);

#endif