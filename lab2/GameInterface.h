//
// Created by 79631 on 31.12.2022.
//

#ifndef LIFE_GAMEINTERFACE_H
#define LIFE_GAMEINTERFACE_H


#include "Universe.h"

namespace GameOfLife {

    static const std::string kOfflineMode = "offline";
    static const std::string kOnlineMode = "online";
    static const std::string kChooseMode = "Choose mode (online/offline)";
    static const std::string kAliveCellOut = "0 ";
    static const std::string kDeadCellOut = ". ";

    class GameInterface {

    public:
        GameInterface();

        static void startGame(int argc, char **argv);

        static void print_universe(Universe universe);

    private:
        static std::string chooseGameMode();
    };
}

#endif //LIFE_GAMEINTERFACE_H
