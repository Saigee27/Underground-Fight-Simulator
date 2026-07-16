#include "Commentary.h"
#include "Fighter.h"
#include <iostream>
#include <cstdlib>
#include <vector>

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


    std::vector<std::string> NormalHeadlines =
{
    "%WINNER% survives a tough challenge and gets the victory!",
    "%WINNER% outworks %LOSER% over three hard-fought rounds!",
    "Another strong performance sees %WINNER% leave with the win!",
    "%WINNER% proves the better fighter when it matters most!",
    "The judges favor %WINNER% after a competitive battle!",
    "The crowd applauds as %WINNER% secures a well-earned victory!",
    "%WINNER% adds another win to the record books tonight!",
    "After an exhausting contest, %WINNER% gets his hand raised!",
    "%LOSER% fought bravely, but %WINNER% was one step ahead!",
    "A disciplined performance earns %WINNER% the victory!"
};

std::vector<std::string> KOHeadlines =
{
    "LIGHTS OUT! %WINNER% scores a devastating knockout!",
    
    "%LOSER% never saw it coming as %WINNER% ends the fight instantly!",

    "The arena explodes as %WINNER% lands a fight-ending bomb!",

    "One punch changes everything! %WINNER% gets the knockout!",

    "A highlight-reel finish from %WINNER% leaves the crowd stunned!",

    "%WINNER% sends a message to the entire division with that knockout!",

    "Absolute destruction! %WINNER% ends the fight in brutal fashion!",

    "The referee rushes in as %WINNER% scores a crushing finish!",

    "%LOSER% hits the canvas after a thunderous shot from %WINNER%!",

    "A terrifying display of power from %WINNER% ends the night!"
};

void showHeadline(Fighter& winner, Fighter& loser, bool KO)
{
    std::string headline;
    if (KO)
    {
        headline = KOHeadlines[rand() % KOHeadlines.size()];
    }
    else 
    {
        headline = NormalHeadlines[rand() % NormalHeadlines.size()];
    }

    size_t pos;
    while((pos = headline.find("%WINNER%")) != std::string::npos)
    {
        headline.replace(pos,std::string("%WINNER%").length(),winner.Name);
    }
    while((pos=headline.find("%LOSER%")) != std::string::npos)
    {
        headline.replace(pos,std::string("%LOSER%").length(),loser.Name);
    }

    std::cout << "\n==================================\n\n";
    std::cout << "HEADLINE: \n";
    std::cout << headline << "\n";
    std::cout << "\n==================================\n";
};