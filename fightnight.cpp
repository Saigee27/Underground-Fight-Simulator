#include "fightnight.h"
#include "Fighter.h"
#include "Bank.h"
#include <iostream>
#include <cstdlib>

void FightNight()
{
    int fighter1 = rand() % roster.size();
    int fighter2 = rand() % roster.size();

    if (roster.size() < 2)
    {
        std::cout << "Not enough fighters!\n";
        return;
    }

    while (fighter1==fighter2)
    {
        fighter2 = rand() % roster.size();
    }

    Fighter & f1 = roster[fighter1];
    Fighter & f2 = roster[fighter2];

    std::cout<<"\n====================\n";
    std::cout<<"Balance: $"<<Money<<std::endl;
    std::cout<<"\n====================\n\n";

    std::cout << "\n===== FIGHT NIGHT =====\n";
    std::cout<<f1.Name<<" Vs "<<f2.Name<<"\n\n";

    std::cout << f1.Name << "\n";
    std::cout << "STR: " << f1.Strength << "\n";
    std::cout << "STA: " << f1.Stamina << "\n";
    std::cout << "TGH: " << f1.Toughness << "\n\n";

    std::cout << f2.Name << "\n";
    std::cout << "STR: " << f2.Strength << "\n";
    std::cout << "STA: " << f2.Stamina << "\n";
    std::cout << "TGH: " << f2.Toughness << "\n\n";


    int score1 = f1.Strength + f1.Stamina + f1.Toughness;
    int score2 = f2.Strength + f2.Stamina + f2.Toughness;

    int betchoice=0;
    std::cout << "Place your bet:\n";
    std::cout << "1. " << f1.Name << "\n";
    std::cout << "2. " << f2.Name << "\n";
    std::cout<<"Choice: ";
    std::cin>>betchoice;

    int betamount=0;
    std::cout << "Bet Amount: $";
    std::cin>>betamount;

    if (betamount > Money)
{
    std::cout << "Insufficient Funds!\n";
    return;
}

if (betamount <= 0)
{
    std::cout << "Invalid Bet!\n";
    return;
}

    Fighter* chosenfighter;
    if(betchoice==1)
    {
        chosenfighter = &f1;
    }
    else
    {
        chosenfighter=&f2;
    }


    Fighter* winner;
    if (score1 > score2)
    {
        winner=&f1;
        std::cout << "Winner: "
          << f1.Name
          << "\n";
        f1.Wins++;
        f2.Losses++;
    }

    else if (score1==score2)
    {
        if(rand() % 2 == 0)
        {
            winner=&f1;
            std::cout << "Winner: "
          << f1.Name
          << "\n";
        f1.Wins++;
        f2.Losses++;
        }
        else
        {
            winner=&f2;
            std::cout<<"Winner: "<<f2.Name<<"\n";
            f2.Wins++;
            f1.Losses++;
        }
    }

    else
    {
        winner=&f2;
        std::cout<<"Winner: "<<f2.Name<<"\n";
        f2.Wins++;
        f1.Losses++;
    }

    std::cout<<"\n";


    if (chosenfighter==winner)
    {
        Money=Money+betamount;
        std::cout << "\nBET WON!\n";
        std::cout << "Earned $" << betamount << '\n';
    }
    else
    {
        Money=Money-betamount;
        std::cout << "\nBET LOST!\n";
        std::cout << "Lost $" << betamount << '\n';
    }
    
    std::cout << "\nCurrent Balance: $"
          << Money
          << "\n";
}

