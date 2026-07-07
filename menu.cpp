#include "menu.h"
#include "Fighter.h"
#include <iostream>

void menu()
{
    int p=0;
    std::cout<<"\n ===== THE PIT ===== \n";

    while (true)
    {
        std::cout<<"1. View Roster"<<std::endl;
        std::cout<<"2. Simulate Fight"<<std::endl;
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
            std::cout<<"\nComing soon\n\n";
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