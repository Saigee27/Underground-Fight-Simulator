#ifndef TIMELINE_H
#define TIMELINE_H
#include <iostream>
#include <vector>
extern int week;
extern int monthindex;
extern int year;
extern std::vector<std::string> Months;
void ShowDate();
void AdvanceTime();
void SetStartingYear();
#endif