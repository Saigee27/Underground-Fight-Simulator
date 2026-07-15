#ifndef COMMENTARY_H
#define COMMENTARY_H
#include "Fighter.h"
void commentary();
void CloseCommentary(Fighter& winner, Fighter& loser, int diff);
void KOCommentary(Fighter& winner, Fighter& loser);
void showHeadline(Fighter& winner, Fighter& loser, bool KO);
#endif
