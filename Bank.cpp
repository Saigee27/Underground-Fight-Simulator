#include "Bank.h"
#include "fightnight.h"
#include "Fighter.h"
#include <iostream>

int Money = 5000;
bool GrandPrixFinished = false;
void BankMenu()
{
    std::cout << "\n===== BANK =====\n\n";
    std::cout << "Balance: $" << Money << "\n";
    std::cout<<"\n==========\n\n";
}

