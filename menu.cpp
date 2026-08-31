#include "menu.h"
#include "Fighter.h"
#include "fightnight.h"
#include "Bank.h"
#include "GrandPrix.h"
#include "Ranking.h"
#include "fight-history.h"
#include "Timeline.h"
#include <iostream>

void menu()
{
    std::cout<<"\n";
    std::cout<<"====================";
    std::cout<<"\n\n";
    std::cout<<"Balance: $"<<Money<<std::endl;
    int p=0;
    std::cout<<"\n===== THE PIT ===== \n";

    while (true)
    {
        
        if(!GrandPrixFinished)
        {
            std::cout<<"\n====================\n";
            ShowDate();
            std::cout<<"\n====================\n\n";
            
            std::cout<<"1. View Roster"<<std::endl;
            std::cout<<"2. Fight Night"<<std::endl;
            std::cout<<"3. View Grand Prix Standings\n";
            std::cout<<"4. View Fight History\n";
            std::cout<<"5. Exit"<<std::endl;
        }
        else
        {
            std::cout<<"1. View Roster\n";
            std::cout<<"2. Fight Night\n";
            std::cout<<"3. Official Rankings\n";
            std::cout<<"4. Grand Prix History\n";
            std::cout<<"5. View Fight History\n";
            std::cout<<"6. Exit\n";
        }
        std::cout<<"\n";
        std::cout<<"Choice: ";
        std::cin>>p;

        if(!GrandPrixFinished)
        {
        switch (p)
        {
        case 1:
            ViewRoster();
            break;

        case 2:
            FightNight();
            break;

        case 3:
        ViewStandings();
            break;

        case 4:
        showFightHistory();
            break;

        case 5:
            std::cout<<"\nGood-Bye\n\n";
            return;

        default:
            std::cout<<"Invalid Request\n";
            break;
        }
        }

        else
        {
            switch(p)
            {
                case 1:
                ViewRoster();
                break;

                case 2:
                FightNight();
                break;

                case 3:
                ViewRankings();
                break;

                case 4:
                ViewStandings();
                break;

                case 5:
                showFightHistory();
                break;

                case 6:
                std::cout<<"\nGood-Bye\n\n";
                return;

                default:
                std::cout<<"Invalid Request\n";
                break;
            }
        }
    };
    
}