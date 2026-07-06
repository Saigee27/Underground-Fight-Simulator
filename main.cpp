#include <iostream>
#include "Fighter.h"
    std::string OwnerName;
    std::string SyndicateName;
void Show()
{
    std::cout<<"_________________________________________\n";
    std::cout<<"\n";
    std::cout<<"Owner : "<<OwnerName<<std::endl;
    std::cout<<"Syndicate : "<<SyndicateName;
    std::cout<<"\n_________________________________________\n";
}
int main()
{
    
    std::cout<<"Enter your name: ";
    std::getline(std::cin,OwnerName);
    std::cout<<"Name your syndicate: ";
    std::getline(std::cin,SyndicateName);
    Show();
    std::cout<<"\nENTER YOUR FIRST 4 FIGHTERS\n";
    CreateRoster();
    ViewRoster();
    
}