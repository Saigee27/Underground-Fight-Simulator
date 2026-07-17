#ifndef POPULARITY_H
#define POPULARITY_H
#include "Fighter.h"
void UpdatePopularity(Fighter& winner, Fighter& loser, bool KOFinish, bool Upset);
void DecayPopularity();
#endif