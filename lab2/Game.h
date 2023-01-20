//
// Created by 79631 on 31.12.2022.
//

#ifndef LIFE_GAME_H
#define LIFE_GAME_H
#include "string"
#include "Universe.h"

class Game {

public:
    static void nextStep(Universe *universe);
    static int getCountOfNearAliveCells(Universe universe, std::pair<int, int> pos);
    static void dump(Universe *universe);
};


#endif //LIFE_GAME_H
