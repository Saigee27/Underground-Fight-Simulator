#include "knockoutsystem.h"
double CalculateKOChance(int performanceDiff, int baseDiff)
{
    double baseChance = 5.0;
    double performanceBonus = performanceDiff * 0.1;
    double baseBonus = baseDiff * 0.05;
    double koChance = baseBonus + performanceBonus + baseChance;

    if(koChance < 2.0)
    {
        koChance = 2.0;
    }
    if(koChance > 15.0)
    {
        koChance = 15.0;
    }
    return koChance;
}