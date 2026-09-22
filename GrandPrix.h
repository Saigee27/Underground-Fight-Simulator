#ifndef GRANDPRIX_H
#define GRANDPRIX_H
#include <vector>
void ViewStandings();
bool HasFoughtBefore(int fighter1, int fighter2);
bool CompleteSeason();
void RecordMatches(int fighter1, int fighter2);
bool GetNextGrandPrixMatch(int& fighter1, int& fighter2);
void GenerateGrandPrixSchedule();
std::vector <int> GetTopFour();
#endif