#include "Fighter.h"
#include <vector>
#include <iostream>

std::vector<Fighter> roster;

void CreateRoster(){
for (int i = 0; i < 4; i++)
{
    Fighter fighter;
    std::cout << "\nEnter Fighter Name: ";
    std::getline(std::cin,fighter.Name);
    roster.push_back(fighter);
}
}


void ViewRoster()
{
    std::cout << "\n=== ROSTER ===\n";
    std::cout<<"\n";
    for (const Fighter& fighter : roster)
    {
        std::cout<<fighter.Name<<std::endl;
    }
    std::cout<<"\n";
}