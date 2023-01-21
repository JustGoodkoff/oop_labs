//
// Created by 79631 on 18.01.2023.
//

#ifndef LIFE_OFFLINEGAMEMODE_H
#define LIFE_OFFLINEGAMEMODE_H

#include "../Game.h"

namespace GameOfLife {

    static const std::string kDone = "done!\n";

    class OfflineGameMode : Game {
    public:
        static void startOfflineMode(Universe *universe);
    };

#endif //LIFE_OFFLINEGAMEMODE_H

}