#include "GrandPrix.h"
#include "Commentary.h"
#include "Fighter.h"
#include "Bank.h"
#include "Timeline.h"
#include "Popularity.h"
#include "fightnight.h"
#include "Bookmaker.h"
#include "Ranking.h"
#include "knockoutsystem.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

extern std::vector <Fighter> roster;
std::vector<std::pair<int,int>> GrandPrixMatches;
std::vector<std::pair<int,int>> GrandPrixSchedule;
int GrandPrixFightIndex = 0;


void ViewStandings()
{

    std::vector<Fighter> standings = roster;
    std::sort(standings.begin(), standings.end(),[](const Fighter& a, const Fighter& b)
    {
        if (a.SeasonWins == b.SeasonWins)
        { 
            if(a.SeasonLosses == b.SeasonLosses)
            {
                return a.Popularity > b.Popularity;
            }
            return a.SeasonLosses < b.SeasonLosses;
        }
        return a.SeasonWins > b.SeasonWins;
    });
     std::cout << "\n===== THE PIT GRAND PRIX =====\n\n";

     int rank = 1;

    for (const Fighter& fighter : standings)
    {
        std::cout
            << "#" << rank << " "
            << fighter.Name
            << " | "
            << fighter.SeasonWins
            << "-"
            << fighter.SeasonLosses
            << " | Fights: "
            << fighter.SeasonFights
            << "\n";
    rank++;
    }
    std::cout<<"\n";
}

void GenerateGrandPrixSchedule()
{
    GrandPrixSchedule.clear();
    GrandPrixFightIndex = 0;

    std::vector<int> fighters;

    for (int i = 0; i < roster.size(); i++)
    {
        fighters.push_back(i);
    }

    int fixed = fighters[0];

    for (int round = 0; round < 3; round++)
    {
        GrandPrixSchedule.push_back(
            {fixed, fighters[9]}
        );

        GrandPrixSchedule.push_back(
            {fighters[1], fighters[8]}
        );

        GrandPrixSchedule.push_back(
            {fighters[2], fighters[7]}
        );

        GrandPrixSchedule.push_back(
            {fighters[3], fighters[6]}
        );

        GrandPrixSchedule.push_back(
            {fighters[4], fighters[5]}
        );

        int last = fighters.back();

        for (int i = 9; i > 1; i--)
        {
            fighters[i] = fighters[i - 1];
        }

        fighters[1] = last;
    }

    std::random_device rd;
    std::mt19937 generator(rd());

    std::shuffle(
        GrandPrixSchedule.begin(),
        GrandPrixSchedule.end(),
        generator
    );
}


bool GetNextGrandPrixMatch(int& fighter1, int& fighter2)
{
    if (GrandPrixFightIndex >= GrandPrixSchedule.size())
    {
        return false;
    }

    fighter1 = GrandPrixSchedule[GrandPrixFightIndex].first;
    fighter2 = GrandPrixSchedule[GrandPrixFightIndex].second;

    GrandPrixFightIndex++;

    return true;
}




bool HasFoughtBefore(int fighter1, int fighter2)
{
    for (const auto& match : GrandPrixMatches)
    {
        if ((match.first == fighter1 && match.second == fighter2) || (match.first == fighter2 && match.second == fighter1)) 
        {
            return true;
        }
    }
    return false;
}

void RecordMatches(int fighter1, int fighter2)
{
    GrandPrixMatches.push_back({fighter1,fighter2});
}


bool CompleteSeason()
{
    for (const Fighter& fighter : roster)
    {
        if(fighter.SeasonFights < 3)
        {
            return false;
        }
    }
    return true;
}

int RunSemiFinal(int fighter1, int fighter2)
{
    Fighter& f1 = roster[fighter1];
    Fighter& f2 = roster[fighter2];

    int BaseRating1 = f1.Strength + f1.Stamina + f1.Toughness;
    int BaseRating2 = f2.Strength + f2.Stamina + f2.Toughness;

    std::cout << "\n============================\n";
    std::cout << "   GRAND PRIX SEMIFINAL\n";
    std::cout << "============================\n\n";

    ShowDate();

    std::cout << "\nBalance: $" << Money << "\n";

    std::cout << "\n====================\n\n";
    std::cout << f1.Name << " Vs " << f2.Name << "\n\n";

    Bettingmarket market = CreateBettingMarket(f1,f2);
    BettingOdds odds = GenerateOdds(f1,f2,market);

    DisplayOdds(f1,f2,odds);

    const int MIN_BET = 500;
    int betchoice = 0;
    while (true)
    {
        std::cout << "\nBet on:\n";
        std::cout << "1. " << f1.Name << "\n";
        std::cout << "2. " << f2.Name << "\n";
        std::cout << "Choice: ";
        std::cin>>betchoice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cout << "Invalid choice. Enter 1 or 2.\n";
            continue;
        }

        if (betchoice != 1 && betchoice != 2)
        {
            std::cout << "Invalid choice. Enter 1 or 2.\n";
            continue;
        }
        break;
    }
    int betamount = 0;

    while(true)
    {
        std::cout << "\nBalance: $" << Money << "\n";
        std::cout << "Enter bet amount (Minimum $" << MIN_BET << "): $";
        std::cin>>betamount;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid amount.\n";
            continue;
        }

        if (betamount < MIN_BET)
        {
            std::cout << "Minimum bet is $" << MIN_BET << ".\n";
            continue;
        }

        if (betamount > Money)
        {
            std::cout << "Insufficient balance.\n";
            continue;
        }
        break;
    }
    std::cin.ignore(1000,'\n');
    Fighter* chosenfighter;

    if(betchoice==1)
    {
        market.MoneyonFighter1 += betamount;
        chosenfighter = &f1;
    }
    else
    {
        market.MoneyonFighter2 += betamount;
        chosenfighter = &f2;
    }
    Money -= betamount;


    bool KOFinish = false;
    Fighter* winner = nullptr;

int RoundsWon1 = 0;
int RoundsWon2 = 0;

for (int round = 1; round <= 3; round++)
{
    std::cout << "\n===== ROUND "
              << round
              << " =====\n\n";

    commentary();
    commentary();
    std::cout << "\n";

    int form1 = rand() % 61 - 30;
    int form2 = rand() % 61 - 30;

    int performance1 = BaseRating1 + form1;
    int performance2 = BaseRating2 + form2;

    int diff = abs(performance1 - performance2);
    int baseDiff = abs(BaseRating1 - BaseRating2);

    double koChance = CalculateKOChance(diff, baseDiff);
    int ko = rand() % 100 + 1;

    if (performance1 > performance2)
    {
        if (ko <= koChance)
        {
            std::cout << "\nKNOCKOUT!\n";
            KOCommentary(f1, f2);

            winner = &f1;
            KOFinish = true;

            break;
        }

        RoundsWon1++;

        CloseCommentary(f1, f2, diff);

        std::cout << "\n";
        std::cout
            << f1.Name
            << " wins Round "
            << round
            << "\n\n";
    }
    else if (performance1 < performance2)
    {
        if (ko <= koChance)
        {
            std::cout << "\nKNOCKOUT!\n";
            KOCommentary(f2, f1);

            winner = &f2;
            KOFinish = true;

            break;
        }

        RoundsWon2++;

        CloseCommentary(f2, f1, diff);

        std::cout << "\n";
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

  if (winner==nullptr)
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

    Fighter* loser = (winner == &f1) ? &f2 : &f1;

    if (winner == &f1)
    {
        f1.Wins++;
        f2.Losses++;

        f1.SeasonWins++;
        f2.SeasonLosses++;

        f1.SeasonFights++;
        f2.SeasonFights++;

        if (KOFinish)
        {
            f1.KOWins++;
            f2.KOLosses++;
        }
    }
    else
    {
        f2.Wins++;
        f1.Losses++;

        f2.SeasonWins++;
        f1.SeasonLosses++;

        f2.SeasonFights++;
        f1.SeasonFights++;

        if (KOFinish)
        {
            f2.KOWins++;
            f1.KOLosses++;
        }
    }

    bool Upset = false;
    if (winner == &f1)
    {
        if (BaseRating1 + 40 < BaseRating2)
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

    std::cout << "\n===== FINAL RESULT =====\n\n";
    std::cout << "Winner: " << winner->Name << "\n\n";

    std::cout << winner->Name
              << " is now on a "
              << winner->WinStreak
              << "-fight win streak!\n";

    PauseGame();

    if (winner == &f1)
    {
        showHeadline(f1, f2, KOFinish);
    }
    else
    {
        showHeadline(f2, f1, KOFinish);
    }

    std::cout << "\n\n";

    std::cout << "===== POST FIGHT DEVELOPMENT =====\n\n";

    if (winner == &f1)
    {
        ImproveStats(f1, f2);
        UpdatePopularity(f1, f2, KOFinish, Upset);
    }
    else
    {
        ImproveStats(f2, f1);
        UpdatePopularity(f2, f1, KOFinish, Upset);
    }

    RecordMatches(fighter1, fighter2);

    std::cout << "\nGrand Prix Matches Played: "
              << GrandPrixMatches.size()
              << "/18\n";

    PauseGame();

        if (chosenfighter == &f1 && winner == &f1)
    {
        int payout = static_cast<int>(betamount * odds.Odds1);

        Money += payout;

        std::cout << "\nBET WON!\n";
        std::cout << "Earned $" << payout << '\n';
    }
    else if (chosenfighter == &f2 && winner == &f2)
    {
        int payout = static_cast<int>(betamount * odds.Odds2);

        Money += payout;

        std::cout << "\nBET WON!\n";
        std::cout << "Earned $" << payout << '\n';
    }
    else
    {
        std::cout << "\nBET LOST!\n";
        std::cout << "Lost $" << betamount << '\n';
    }

    std::cout << "\nCurrent Balance: $"
              << Money
              << "\n\n";

    std::cout << "====================\n";

    AdvanceTime();

    return winner == &f1 ? fighter1 : fighter2;
}

std::vector <int> GetTopFour()
{
    std::vector <int> indices;
    for(int i=0; i<roster.size(); i++)
    {
        indices.push_back(i);
    }
    std::sort(indices.begin(), indices.end(), [](int a, int b)
    {
        if(roster[a].SeasonWins == roster[b].SeasonWins)
        {
            if(roster[a].SeasonLosses == roster[b].SeasonLosses)
            {
                return roster[a].Popularity > roster[b].Popularity;
            }
            return roster[a].SeasonLosses < roster[b].SeasonLosses;
        }
        return roster[a].SeasonWins > roster[b].SeasonWins;
    });
    indices.resize(4);
    return indices;
}
