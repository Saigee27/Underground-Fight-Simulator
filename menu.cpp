#include "menu.h"
#include "Fighter.h"
#include "fightnight.h"
#include "Bank.h"
#include <iostream>

void menu()
{
    std::cout<<"\n";
    std::cout<<"====================";
    std::cout<<"\n\n";
    std::cout<<"Balance: $"<<Money<<std::endl;
    int p=0;
    std::cout<<"\n===== THE PIT ===== \n\n";

    while (true)
    {
        std::cout<<"\n";
        std::cout<<"1. View Roster"<<std::endl;
        std::cout<<"2. Fight Night"<<std::endl;
        std::cout<<"3. Exit"<<std::endl;
        std::cout<<"\n";
        std::cout<<"Choice: ";
        std::cin>>p;

        switch (p)
        {
        case 1:
            ViewRoster();
            break;

        case 2:
            FightNight();
            break;

        case 3:
            std::cout<<"\nGood-Bye\n\n";
            return;

        default:
            std::cout<<"Invalid Request\n";
            break;
        }
    }
    
}