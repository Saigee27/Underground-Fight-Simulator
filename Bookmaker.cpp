#include "Bookmaker.h"
#include "iomanip"
#include "cmath"
int CalculateMarketScore(Fighter fighter)
{
    int totalFights = fighter.Wins + fighter.Losses;

    float winRate;

    if(totalFights==0)
    {
        winRate = 0.5f;
    }
    else
    {
        winRate = (float)fighter.Wins / totalFights;
    }

    float koRate;
    if(fighter.Wins==0)
    {
        koRate = 0.5f;
    }
    else
    {
        koRate = (float)fighter.KOWins / fighter.Wins;
    }

    float streakFactor = (float)fighter.WinStreak / 5.0f;

    if(streakFactor > 1.0f)
    {
        streakFactor = 1.0f;
    }

    int popularityScore = (int)(fighter.Popularity * 0.40f);

    int winScore = (int)(winRate * 35.0f);

    int koScore = (int)(koRate * 15.0f);

    int streakScore = (int)(streakFactor * 10.0f);

    return 
    popularityScore +
    winScore +
    koScore +
    streakScore;
}

float CalculateProbability(int rating1, int rating2)
{
    float difference = rating1 - rating2;
    return 1.0f / (1.0f + std::exp(-difference/40.0f));
}

float CalculateOdds(float probability)
{
    float bookmakerProbability = probability * 1.05f;
    return 1.0f/bookmakerProbability;
}

float ApplyExperienceUncertainty(float probability, int totalFights)
{
    float confidence;

    if(totalFights>=10)
    {
        confidence=1.0f;
    }
    else
    {
        confidence=(float)totalFights / 10.0f;
    }
    return 0.5f + (probability - 0.5f) * confidence;
}

BettingOdds GenerateOdds(Fighter f1,Fighter f2)
{
    BettingOdds data;

    data.Rating1 = CalculateMarketScore(f1);
    data.Rating2 = CalculateMarketScore(f2);

    data.Probability1 =
        CalculateProbability(data.Rating1,data.Rating2);

    data.Probability2 =
        CalculateProbability(data.Rating2,data.Rating1);

    int fights1 = f1.Wins + f1.Losses;
    int fights2 = f2.Wins + f2.Losses;

    int totalFights = fights1 + fights2;

    data.Probability1 = ApplyExperienceUncertainty(data.Probability1, totalFights);
    data.Probability2 = ApplyExperienceUncertainty(data.Probability2, totalFights);

    data.Odds1 = CalculateOdds(data.Probability1);
    data.Odds2 = CalculateOdds(data.Probability2);

    return data;
}

void DisplayOdds(Fighter f1, Fighter f2, BettingOdds odds)
{
    std::cout << std::fixed << std::setprecision(2);

    std::cout << f1.Name << "\n";
    std::cout << "Popularity : " << f1.Popularity << "\n";
    std::cout << "Odds       : " << odds.Odds1 << "x\n\n";

    std::cout << f2.Name << "\n";
    std::cout << "Popularity : " << f2.Popularity << "\n";
    std::cout << "Odds       : " << odds.Odds2 << "x\n\n";
}