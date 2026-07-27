#include "Bookmaker.h"
#include "iomanip"
int CalculatePowerRating(Fighter fighter)
{
    return
    (fighter.Strength*3)+
    (fighter.Stamina*2)+
    (fighter.Toughness*2)+
    fighter.Popularity+
    (fighter.WinStreak*5)+
    (fighter.KOWins*3);
}

float CalculateProbability(int rating,int total)
{
    return (float)rating/total;
}

float CalculateOdds(float probability)
{
    return 1.0f/probability;
}

BettingOdds GenerateOdds(Fighter f1,Fighter f2)
{
    BettingOdds data;

    data.Rating1 = CalculatePowerRating(f1);
    data.Rating2 = CalculatePowerRating(f2);

    int Total = data.Rating1 + data.Rating2;

    data.Probability1 =
        CalculateProbability(data.Rating1,Total);

    data.Probability2 =
        CalculateProbability(data.Rating2,Total);

    data.Odds1 =
        CalculateOdds(data.Probability1);

    data.Odds2 =
        CalculateOdds(data.Probability2);

    return data;
}

void DisplayOdds(Fighter f1,Fighter f2, BettingOdds odds)
{
    std::cout<<std::fixed<<std::setprecision(2);

    std::cout<<"\n===== BOOKMAKER =====\n\n";

    std::cout<<f1.Name<<"\n";
    std::cout<<"Rating : "<<odds.Rating1<<"\n";
    std::cout<<"Chance : "<<odds.Probability1*100<<"%\n";
    std::cout<<"Odds   : "<<odds.Odds1<<"x\n\n";

    std::cout<<f2.Name<<"\n";
    std::cout<<"Rating : "<<odds.Rating2<<"\n";
    std::cout<<"Chance : "<<odds.Probability2*100<<"%\n";
    std::cout<<"Odds   : "<<odds.Odds2<<"x\n\n";
}