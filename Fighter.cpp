#include "Fighter.h"
#include "NameGen.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>

std::vector<Fighter> roster;



void CreateRoster(){
for (int i = 0; i < 10; i++)
{
    Fighter fighter;
    fighter.Name = GenerateName();
    fighter.Stamina = rand() % 41 + 60;
    fighter.Strength = rand() % 41 + 60;
    fighter.Toughness = rand() % 41 + 60;
    fighter.Popularity = rand() % 31 + 20;
    std::cout << fighter.Name << " has joined the roster!\n\n";
    roster.push_back(fighter);
   
    
}
}




void ViewRoster()
{
    std::cout << "\n=== ROSTER ===\n";
    for (const Fighter& fighter : roster)
    {
        std::cout<<"\n";
        std::cout<<fighter.Name<<std::endl;
        std::cout<<"Strength: "<<fighter.Strength<<std::endl;
        std::cout<<"Stamina: "<<fighter.Stamina<<std::endl;
        std::cout<<"Toughness: "<<fighter.Toughness<<std::endl;
        std::cout<<"Wins: "<<fighter.Wins<<std::endl;
        std::cout<<"Losses: "<<fighter.Losses<<std::endl;
        std::cout<<"Popularity: "<<fighter.Popularity<<std::endl;
        std::cout<<"\n";
    }
    std::cout << "===============\n";
}

void ImproveStats(Fighter& winner, Fighter& loser)
{
    int winnerstats = rand() % 3;
    int winnergained = rand() % 3 + 1;

    int loserstats = rand() % 3;
    int losergained = rand() % 3 - 1;


    if (winnerstats == 0)
    {
        winner.Strength += winnergained;
        if (winner.Strength > 100)
        {
            winner.Strength = 100;
        }
            std::cout << winner.Name << " improved Strength by +" << winnergained << "!\n";
    }
    else if (winnerstats == 1)
    {
        winner.Stamina += winnergained;
        if (winner.Stamina > 100)
        {
            winner.Stamina = 100;
        }
        std::cout<<winner.Name<<" improved Stamina by +"<<winnergained<<"!\n";
    }
    else
    {
        winner.Toughness += winnergained;
        if(winner.Toughness > 100)
        {
            winner.Toughness = 100;
        }
        std::cout << winner.Name <<" improved Toughness by +"<<winnergained<<"!\n";
    }

    if (losergained != 0)
    {
        if (loserstats == 0)
        {
            loser.Strength += losergained;
            if (loser.Strength > 100)
            {
                loser.Strength = 100;
            }
            if (loser.Strength < 50)
            {
                loser.Strength = 50;
            }

            if (losergained > 0)
        {
            std::cout << loser.Name
                      << " improved Strength by +"
                      << losergained
                      << " despite the loss!\n";
        }
        else
        {
            std::cout << loser.Name
                      << " lost "
                      << -losergained
                      << " Strength after the defeat!\n";
        }
        }

        else if (loserstats == 1)
        {
            loser.Stamina += losergained;
            if (loser.Stamina > 100)
            {
                loser.Stamina = 100;
            }
            if (loser.Stamina < 50)
            {
                loser.Stamina = 50;
            }
            
            if (losergained > 0)
            {
                std::cout << loser.Name
                  << " improved Stamina by +"
                  << losergained
                  << " despite the loss!\n";
            }
            else
            {
                std::cout << loser.Name
                  << " lost "
                  << -losergained
                  << " Stamina after the defeat!\n";
            }

        }
        
        else
        {
            loser.Toughness += losergained;

            if (loser.Toughness > 100)
                loser.Toughness = 100;

            if (loser.Toughness < 50)
                loser.Toughness = 50;

            if (losergained > 0)
            {
                std::cout << loser.Name
                        << " improved Toughness by +"
                        << losergained
                        << " despite the loss!\n";
            }
            else
            {
                std::cout << loser.Name
                        << " lost "
                        << -losergained
                        << " Toughness after the defeat!\n";
            }
        }
    }
}