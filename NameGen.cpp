#include "NameGen.h"
#include "Fighter.h"
#include "fightnight.h"

#include <iostream>
#include <vector>
#include <cstdlib>

std::vector <std::string> firstName =
{
    "Alex", "Marcus", "Victor", "Ivan", "Dmitri",
    "Anton", "Roman", "Nikolai", "Andrei", "Sergei",

    "Diego", "Carlos", "Rafael", "Miguel", "Mateo",
    "Bruno", "Lucas", "Thiago", "Santiago", "Nicolas",

    "Akira", "Kenji", "Takumi", "Kaito", "Ren",
    "Haruto", "Daichi", "Riku", "Yuki", "Shota",

    "Ryan", "Jason", "Tyler", "Logan", "Ethan",
    "Nathan", "Connor", "Derek", "Blake", "Cole",

    "Adrian", "Leon", "Damien", "Trevor", "Grant",
    "Jordan", "Mason", "Hunter", "Brandon", "Zach"
};

std::vector <std::string> lastName =
{
       "Stone", "Walker", "King", "Carter", "Miller",
    "Parker", "Turner", "Brooks", "Foster", "Hayes",

    "Volkov", "Petrov", "Orlov", "Kozlov", "Romanov",
    "Morozov", "Antonov", "Sokolov", "Mikhailov", "Vasilyev",

    "Silva", "Santos", "Costa", "Oliveira", "Ferreira",
    "Pereira", "Rocha", "Ribeiro", "Almeida", "Mendes",

    "Takeda", "Tanaka", "Sato", "Yamamoto", "Nakamura",
    "Ito", "Kobayashi", "Fujimoto", "Arai", "Kuroda",

    "Reyes", "Vega", "Castillo", "Ortega", "Morales",
    "Herrera", "Navarro", "Delgado", "Rojas", "Fuentes"
};

std::string FighterNicknames[] =
{
    "The Hammer",
    "Ghost",
    "The Wolf",
    "Iron Fist",
    "The Machine",
    "The Butcher",
    "The Reaper",
    "King",
    "The Beast",
    "The Nightmare",
    "The Titan",
    "Lightning",
    "The Predator",
    "The Outlaw",
    "The Punisher",
    "The Destroyer",
    "The Assassin",
    "The Juggernaut",
    "The Phantom",
    "The Savage"
};



std::string GenerateName()
{
    std::string first = firstName[rand() % firstName.size()];
    std::string nickname = FighterNicknames[rand() % 20];
    std::string last = lastName[rand() % lastName.size()];
    return first + " \"" + nickname + "\" " + last;
}


