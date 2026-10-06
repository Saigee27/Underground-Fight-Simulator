#ifndef FIGHTHISTORY_H
#define FIGHTHISTORY_H
#include "Fighter.h"
#include <vector>
enum class Event
{
    Grand_Prix,
    Ranked
};
enum class Method
{
    KO,
    TKO,
    Submission,
    Decision,
    Draw,
    DQ
};
struct FightResult
{
    Fighter* Fighter1;
    Fighter* Fighter2;
    Fighter* Winner;
    Fighter* Loser;
    Event event;
    Method method;
    int Round;
    int Duration;

    double OpponentStrength;
    double WinQuality;

    double WinnerProbability;
    double UpsetValue;

    std::string DecisionType;
    std::string Date;
};
extern std::vector <FightResult> fightHistory;
void RecordFights(const FightResult& result);
void showFightHistory();
double CalculateWinQuality(const FightResult& result);
double CalculateUpsetValue(double winnerProbability);
double CalculateRecentForm(const Fighter& fighter);
double CalculateTrajectoryScore(const Fighter& fighter);
std::string GetTrajectoryState(const Fighter& fighter);
#endif
