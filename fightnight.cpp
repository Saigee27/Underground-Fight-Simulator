#include "fightnight.h"
#include "Fighter.h"
#include "Bank.h"
#include <iostream>
#include <vector>
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

    std::cout<<"\n====================\n\n";
    std::cout<<" Balance: $"<<Money<<std::endl;
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


    int betchoice=0;
    std::cout << "Place your bet:\n";
    std::cout << "1. " << f1.Name << "\n";
    std::cout << "2. " << f2.Name << "\n";
    std::cout<<"\n";
    std::cout<<"Choice: ";
    std::cin>>betchoice;

    int betamount=0;
    std::cout << "Bet Amount: $";
    std::cin>>betamount;
    std::cout<<"\n";
    std::cin.ignore(1000,'\n');
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
            RoundsWon1++;
            std::cout
            << f1.Name
            << " wins Round "
            << round
            << "\n\n";

            CloseCommentary(f1,f2,diff);

            if (diff >= 50)
            {
                int ko = rand() % 100 + 1;
                if (ko <= 30)
                {
                      std::cout << "\nKNOCKOUT!\n";
                        KOCommentary(f1, f2);
                      winner = &f1;
                      RoundsWon1=3;
                      break;
                    
                }
            }

        }
        else if(performance1 < performance2)
        {
            RoundsWon2++;
            std::cout
            << f2.Name
            << " wins Round "
            << round
            << "\n\n";

            CloseCommentary(f2,f1,diff);

            if (diff>=50)
            {
                int ko = rand() % 100 + 1;
                
                if(ko<=30)
                {
                    
                    std::cout << "\nKNOCKOUT!\n";
                    KOCommentary(f2, f1);
                    winner=&f2;
                    RoundsWon2=3;
                    break;
                }
            }

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

if (winner == &f1)
{
    f1.Wins++;
    f2.Losses++;
}
else
{
    f2.Wins++;
    f1.Losses++;
}

std::cout
<< "\n===== FINAL RESULT =====\n\n";

std::cout
<< "Winner: "
<< winner->Name
<< "\n";

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
          << "\n\n";
    std::cout<<"====================\n";
}


void commentary()
{
    std::vector <std::string> lines =
    {
        "A huge right hand lands clean!",
        "The crowd erupts as both fighters exchange punches!",
        "A crushing body shot connects!",
        "Neither fighter is willing to back down!",
        "A sharp jab snaps the head back!",
        "The pace of this fight is unbelievable!",
        "Both men are trading heavy shots!",
        "A powerful combination lands!",
        "The fighter stumbles but stays standing!",
        "The arena is absolutely electric tonight!"
    };

    int randomline = rand() % lines.size();
    std::cout<<lines[randomline]<<"\n";
}

void CloseCommentary(Fighter& winner, Fighter& loser, int diff)
{
    std::vector <std::string> closeFight =
    {
        "Both fighters are trading evenly!",
        "Neither fighter is giving an inch!",
        "That round was incredibly close!",
        "The crowd cannot separate these two!",
        "Both men are matching each other punch for punch!"
    };

    std::vector <std::string> goodRound = 
    {
        winner.Name + " is starting to find momentum!",
        winner.Name + " is gaining confidence!",
        loser.Name + " needs to answer back quickly!",
        winner.Name + " edges ahead in the fight!",
        winner.Name + " is putting together some good work!"
    };

    std::vector <std::string> dominantRound =
    {
        winner.Name + " lands a devastating combination!",
        loser.Name + " looks badly hurt!",
        winner.Name + " is taking complete control!",
        loser.Name + " is struggling to keep up!",
        winner.Name + " has the crowd on its feet!",
        winner.Name + " is overwhelming the opposition!",
        loser.Name + " is getting battered around the cage!",
        winner.Name + " smells blood!"
    };

    if (diff<15)
    {
        int close = rand() % closeFight.size();
        std::cout<<closeFight[close]<<"\n";
    }

    else if (diff<40)
    {
        int good = rand() % goodRound.size();
        std::cout<<goodRound[good]<<"\n";
    }

    else
    {
        int dom = rand() % dominantRound.size();
        std::cout<<dominantRound[dom]<<"\n"; 
    }
}

void KOCommentary(Fighter& winner, Fighter& loser)
{
    std::vector <std::string> KoLines = 
    {
        winner.Name + " sends " + loser.Name + " crashing to the canvas!",
        winner.Name + " lands a shot from hell!",
        loser.Name + " is OUT COLD!",
        winner.Name + " scores a spectacular knockout!",
        loser.Name + " never saw that punch coming!",
        winner.Name + " shuts the lights out!",
        winner.Name + " ends the fight instantly!"
    };

    int Ko = rand() % KoLines.size();
    std::cout<<KoLines[Ko]<<"\n";
}