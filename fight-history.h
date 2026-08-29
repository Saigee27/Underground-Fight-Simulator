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
    Decision
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
};
extern std::vector <FightResult> fightHistory;
void RecordFights(const FightResult& result);
void showFightHistory();
#endif
