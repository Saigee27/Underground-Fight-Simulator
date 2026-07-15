#include "Timeline.h"
#include <vector>
#include <iostream>

int monthindex=0;
int year=2026;
int week=1;
std::vector<std::string> Months =
{
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

void SetStartingYear()
{
    std::cout<<"Enter the current year: ";
    std::cin>>year;
    std::cin.ignore(1000,'\n');
}

void ShowDate()
{
    std::cout << "Week " << week
              << " | "
              << Months[monthindex]
              << " | "
              << year;
}

void AdvanceTime()
{
    week++;
    if (week > 4)
    {
        week=1;
        monthindex++;
    }
    if (monthindex > 11)
    {
        monthindex=0;
        year++;
    }
}