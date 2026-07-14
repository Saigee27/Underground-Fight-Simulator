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
        std::cout<<"\n";
    }
    std::cout << "===============\n";
}