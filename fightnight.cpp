#include "fightnight.h"
#include "Commentary.h"
#include "Bank.h"
#include "Timeline.h"
#include "Popularity.h"
#include "GrandPrix.h"
#include <iostream>
#include <vector>
#include <cstdlib>
extern std::vector<std::pair<int,int>> GrandPrixMatches;
void PauseGame()
{
    std::cout << "\nPress Enter to continue...";
    std::cin.get();
}

void FightNight()
{

    if (GrandPrixFinished)
    {
        std::cout
        << "\nThe Grand Prix has already concluded!\n";

        return;
    }

    
    int fighter1;
    int fighter2;


     if (roster.size() < 2)
    {
        std::cout << "Not enough fighters!\n";
        return;
    }

    if (CompleteSeason())
    {
        ViewStandings();
        CrownChampion();
    }

    int attempts = 0;

do
{
    fighter1 = rand() % roster.size();
    fighter2 = rand() % roster.size();

    attempts++;

    if (attempts > 1000)
    {
        std::cout << "\nNo valid fights remaining!\n";
        return;
    }

}
while
(
    fighter1 == fighter2 ||
    roster[fighter1].SeasonFights >= 3 ||
    roster[fighter2].SeasonFights >= 3 ||
    HasFoughtBefore(fighter1,fighter2)
);

    Fighter & f1 = roster[fighter1];
    Fighter & f2 = roster[fighter2];

    std::cout<<"\n====================\n\n";
    ShowDate();
    std::cout<<"\nBalance: $"<<Money<<"\n";
    std::cout<<"\n====================\n\n";

    std::cout<<"\n===== FIGHT NIGHT =====\n\n";
    std::cout<<f1.Name<<" Vs "<<f2.Name<<"\n\n";

    std::cout << f1.Name << "\n";
    std::cout << "STR: " << f1.Strength << "\n";
    std::cout << "STA: " << f1.Stamina << "\n";
    std::cout << "TGH: " << f1.Toughness << "\n\n";

    std::cout << f2.Name << "\n";
    std::cout << "STR: " << f2.Strength << "\n";
    std::cout << "STA: " << f2.Stamina << "\n";
    std::cout << "TGH: " << f2.Toughness << "\n\n";


    int BaseRating1 = f1.Strength + f1.Stamina + f1.Toughness;
    int BaseRating2 = f2.Strength + f2.Stamina + f2.Toughness;

    int RoundsWon1=0;
    int RoundsWon2=0;

    Fighter* winner = nullptr;
    bool KOFinish=false;


    int betchoice=0;
    std::cout << "Place your bet:\n";
    std::cout << "1. " << f1.Name << "\n";
    std::cout << "2. " << f2.Name << "\n";
    std::cout<<"\n";
    std::cout<<"Choice: ";
    
    while (true)
{
    std::cin >> betchoice;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input!\nChoice: ";
        continue;
    }

    if (betchoice != 1 && betchoice != 2)
    {
        std::cout << "Choose 1 or 2!\nChoice: ";
        continue;
    }

    break;
}



    int betamount=0;
while(true)
{
    std::cout << "Bet Amount: $";

    std::cin >> betamount;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input!\n";
        continue;
    }

    if (betamount > Money)
    {
        std::cout << "Insufficient Funds!\n";
        continue;
    }

    if (betamount <= 0)
    {
        std::cout << "Invalid Bet!\n";
        continue;
    }

    break;
}
std::cin.ignore(1000,'\n');



    Fighter* chosenfighter;
    if(betchoice==1)
    {
        chosenfighter = &f1;
    }
    else if(betchoice==2)
    {
        chosenfighter = &f2;
    }
    else 
    {
        std::cout << "Invalid Choice!\n";
        return;
    }




    for (int round=1; round<=3; round++)
    {
        std::cout << "\n===== ROUND "
              << round
              << " =====\n\n";
              commentary();
              commentary();
              std::cout<<"\n";

        int form1 = rand() % 61 - 30;
        int form2 = rand() % 61 - 30;

        int performance1 = BaseRating1 + form1;
        int performance2 = BaseRating2 + form2;

        int diff = abs(performance1 - performance2);



        if (performance1 > performance2)
        {
            

            if (diff >= 50)
            {
                int ko = rand() % 100 + 1;
                if (ko <= 40)
                {
                      std::cout << "\nKNOCKOUT!\n";
                        KOCommentary(f1, f2);
                      winner = &f1;
                      KOFinish=true;
                      break;
                    
                }
            }

            RoundsWon1++;
            CloseCommentary(f1,f2,diff);
            std::cout<<"\n";
            std::cout
            << f1.Name
            << " wins Round "
            << round
            << "\n\n";

            

        }
        else if(performance1 < performance2)
        {
            
            if (diff>=50)
            {
                int ko = rand() % 100 + 1;
                
                if(ko<=40)
                {
                    
                    std::cout << "\nKNOCKOUT!\n";
                    KOCommentary(f2, f1);
                    winner=&f2;
                    KOFinish=true;
                    break;
                }
            }

            RoundsWon2++;
            CloseCommentary(f2,f1,diff);
            std::cout<<"\n";
            std::cout
            << f2.Name
            << " wins Round "
            << round
            << "\n\n";

            


        }

        else 
        {
              if (rand() % 2 == 0)
    {
        RoundsWon1++;

        std::cout
        << "Close round! Judges favor "
        << f1.Name
        << "\n";
    }
    else
    {
        RoundsWon2++;

        std::cout
        << "Close round! Judges favor "
        << f2.Name
        << "\n";
    }
        }


        std::cout
        << "\nSCOREBOARD:\n";

        std::cout
        << f1.Name
        << ": "
        << RoundsWon1
        << "\n";

        std::cout
        << f2.Name
        << ": "
        << RoundsWon2
        << "\n";

        if (round < 3)
        {
            std::cout
            << "\n-------------------------\n";

            std::cout
            << "Press Enter for next round...";

            std::cin.get();
        }
    }


    if (winner == nullptr)
{
    if (RoundsWon1 > RoundsWon2)
    {
        winner = &f1;
    }
    else
    {
        winner = &f2;
    }
}


Fighter* loser;

if (winner == &f1)
{
    loser = &f2;
}
else
{
    loser = &f1;
}


if (winner == &f1)
{
    f1.Wins++;
    f2.Losses++;

    f1.WinStreak++;
    f1.LoseStreak = 0;

    f2.LoseStreak++;
    f2.WinStreak = 0;


    f1.SeasonWins++;
    f2.SeasonLosses++;

    f1.SeasonFights++;
    f2.SeasonFights++;
    
}
else
{
    f2.Wins++;
    f1.Losses++;

    f2.WinStreak++;
    f2.LoseStreak = 0;

    f1.LoseStreak++;
    f1.WinStreak = 0;
    
    f2.SeasonWins++;
    f1.SeasonLosses++;

    f2.SeasonFights++;
    f1.SeasonFights++;
}

bool Upset = false;
if (winner == &f1)
{
    if(BaseRating1 + 40 < BaseRating2)
    {
        Upset = true;
    }
}
else
{
    if (BaseRating2 + 40 < BaseRating1)
    {
        Upset = true;
    }
}


std::cout
<< "\n===== FINAL RESULT =====\n\n";

std::cout
<< "Winner: "
<< winner->Name
<< "\n\n";

   
   std::cout
<< winner->Name
<< " is now on a "
<< winner->WinStreak
<< "-fight win streak!\n";
    

if (winner->WinStreak == 3)
{
    std::cout << winner->Name
              << " is on fire with three straight victories!\n";
}
else if (winner->WinStreak == 5)
{
    std::cout <<  winner->Name
              << " has become one of the hottest fighters in The Pit!\n";
}
else if (winner->WinStreak >= 7)
{
    std::cout <<  winner->Name
              << " is building a legendary winning streak!\n";
}

if (loser->LoseStreak == 3)
{
    std::cout << "⚠ "
              << loser->Name
              << " has now lost three fights in a row!\n";
}
else if (loser->LoseStreak >= 5)
{
    std::cout << "🚨 "
              << loser->Name
              << "'s career is in serious trouble after "
              << loser->LoseStreak
              << " consecutive losses!\n";
}

    PauseGame();

    if(winner==&f1)
    {
        showHeadline(f1,f2,KOFinish);
    }
    else
    {
        showHeadline(f2,f1,KOFinish);
    }

std::cout<<"\n\n";

    std::cout << "===== POST FIGHT DEVELOPMENT =====\n\n";
if (winner == &f1)
{  
    ImproveStats(f1,f2);
    UpdatePopularity(f1,f2,KOFinish,Upset);
    
}
else
{
    ImproveStats(f2,f1);
    UpdatePopularity(f2,f1,KOFinish,Upset);
    
}

if (winner->WinStreak >= 7)
{
    winner->Popularity += 5;
    std::cout << "The Industry cannot stop talking about " << winner->Name << "!\n";
}

else if (winner->WinStreak >= 5)
{
    winner->Popularity += 3;
    std::cout << winner->Name << "'s popularity continues to soar.\n";
}

else if (winner->WinStreak >= 3)
{
    winner->Popularity += 2;
    std::cout << winner->Name << " is winning over more fans with every victory.\n";
}

if (loser->LoseStreak >= 7)
{
    loser->Popularity -= 5;
     std::cout << loser->Name << "'s reputation has hit rock bottom.\n";
}

else if (loser->LoseStreak >= 5)
{
    loser->Popularity -= 3;
    std::cout << loser->Name << "'s popularity is fading.\n";
}

else if (loser->LoseStreak >= 3)
{
    loser->Popularity -= 2;
    std::cout << loser->Name << " is losing the support of the fans.\n";
}

if (winner->Popularity > 100)
{
    winner->Popularity = 100;
}

if (loser->Popularity < 0)
{
    loser->Popularity = 0;
}

RecordMatches(fighter1,fighter2);
std::cout
<< "\nGrand Prix Matches Played: "
<< GrandPrixMatches.size()
<< "/15\n";
std::cout << "\n=============================\n";

PauseGame();


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
          << "\n\n";
    std::cout<<"====================\n\n";

    AdvanceTime();
}





