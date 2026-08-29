#include "fight-history.h"
#include <iostream>
std::vector <FightResult> fightHistory;
void RecordFights(const FightResult& result)
{
    fightHistory.push_back(result);
}
void showFightHistory()
{
    std::cout << "\n=====================================\n";
    std::cout << "          THE PIT FIGHT HISTORY\n";
    std::cout << "=====================================\n\n";

    for (const FightResult& result : fightHistory)
    {
        std::cout << result.Fighter1->Name
                  << " vs "
                  << result.Fighter2->Name
                  << "\n";

        std::cout << "Winner : "
                  << result.Winner->Name
                  << "\n";

        std::cout << "Event : ";

        if (result.event == Event::Grand_Prix)
            std::cout << "Grand Prix\n";
        else
            std::cout << "Ranked\n";

        std::cout << "Method : ";

        if (result.method == Method::KO)
            std::cout << "KO\n";
        else
            std::cout << "Decision\n";

        
        std::cout << "-------------------------------------\n";
    }
}
