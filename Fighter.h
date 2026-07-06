#ifndef FIGHTER_H
#define FIGHTER_H
#include <iostream>
class Fighter 
{
    public:
    std::string Name;
    int Strength;
    int Stamina;
    int Toughness;
    
};

void CreateRoster();
void ViewRoster();
#endif