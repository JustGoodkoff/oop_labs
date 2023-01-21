//
// Created by 79631 on 18.01.2023.
//

#include <iostream>
#include "OfflineGameMode.h"

namespace GameOfLife {

    void OfflineGameMode::startOfflineMode(Universe *universe) {
        for (int i = 0; i < universe->getIterations(); i++) {
            nextStep(universe);
        }
        dump(universe);
        std::cout << kDone;
    }

}