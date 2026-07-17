#include "Popularity.h"
#include <iostream>
void UpdatePopularity(Fighter& winner, Fighter& loser, bool KOFinish, bool Upset)
{
    int winnergain=0;
    int losergain=0;

    if (Upset)
    {
        winnergain = 5;
        losergain = 2;
    }

    else if (KOFinish)
    {
        winnergain = 5;
        losergain = 0;
    }
    
    else
    {
        winnergain = 2;
        losergain = 1;
    }
   
    winner.Popularity += winnergain;
    loser.Popularity += losergain;

    if (winner.Popularity > 100)
    {
        winner.Popularity = 100;
    }
    if (loser.Popularity > 100)
    {
        loser.Popularity = 100;
    }

    std::cout << "\n===== POPULARITY =====\n\n";

    if (Upset)
    {
        std::cout << "*** UNDERDOG SHOCKS THE CROWD! ***\n\n";
    }

    
    std::cout << winner.Name
              << " gains +"
              << winnergain
              << " popularity!\n";

    if (losergain > 0)
    {
        std::cout << loser.Name
                  << " gains +"
                  << losergain
                  << " popularity!\n";
    }

    std::cout << "\n";
}

void DecayPopularity()
{
    for (Fighter& fighter : roster)
    {
        if (fighter.Popularity > 30)
        {
            fighter.Popularity--;
        }
    }
}