//
// Created by 79631 on 31.12.2022.
//

#ifndef LIFE_GAMEINTERFACE_H
#define LIFE_GAMEINTERFACE_H


#include "Universe.h"

class GameInterface {
    static const int kOFFLINE_MODE = 0;
    static const int kONLINE_MODE = 1;
public:
    GameInterface();
    static void startGame(int argc, char** argv);
    static void print_universe(Universe universe);

    static std::string chooseGameMode();
};


#endif //LIFE_GAMEINTERFACE_H
