#include <iostream>
#include "Fighter.h"
#include "menu.h"
#include <ctime>
#include <cstdlib>

    std::string OwnerName;
    std::string OrgName;
void Show()
{
    std::cout<<"_________________________________________\n";
    std::cout<<"\n";
    std::cout<<"Owner : "<<OwnerName<<std::endl;
    std::cout<<"Organization : "<<OrgName;
    std::cout<<"\n_________________________________________\n";
}

    int main()
{
    srand(time(0));
    std::cout<<"Enter your name: ";
    std::getline(std::cin,OwnerName);
    std::cout<<"Name your Organization: ";
    std::getline(std::cin,OrgName);
    Show();
    
    CreateRoster();
    
    menu();
    
}