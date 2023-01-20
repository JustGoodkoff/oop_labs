//
// Created by 79631 on 18.01.2023.
//

#ifndef LIFE_ONLINEGAMEMODE_H
#define LIFE_ONLINEGAMEMODE_H

#include "Universe.h"
#include "Game.h"

static const std::string kHelpMessage = "dump <filename> - save universe to file \n"
                                        "tick <n=1> - calculate n (default 1) iterations and print the result.\n"
                                        "exit - close this game\n"
                                        "help - print a command sheet\n";

class OnlineGameMode : Game {
public:
    static void startOnlineGame(Universe *universe);

};

#endif //LIFE_ONLINEGAMEMODE_H
