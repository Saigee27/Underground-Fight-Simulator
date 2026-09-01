#include "knockoutsystem.h"
double CalculateKOChance(int performanceDiff)
{
    double baseChance = 5.0;
    double bonus = performanceDiff * 0.1;
    double koChance = bonus + baseChance;

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