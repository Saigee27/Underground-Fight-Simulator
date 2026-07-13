#ifndef FIGHTNIGHT_H
#define FIGHTNIGHT_H
#include "Fighter.h"
void FightNight();
void commentary();
void CloseCommentary(Fighter& winner, Fighter& loser, int diff);
void KOCommentary(Fighter& winner, Fighter& loser);
#endif