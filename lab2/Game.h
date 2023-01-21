//
// Created by 79631 on 31.12.2022.
//

#ifndef LIFE_GAME_H
#define LIFE_GAME_H
#include "string"
#include "Universe.h"
// "acorn.txt", "glider.txt"

namespace GameOfLife {


    static const std::vector<std::string> universes = {"herschel.txt", "glider.txt", "acorn.txt", "blinker.txt",
                                                       "switch-engine.txt"};
    static const std::string kLifeVersion = "#Life 1.06";
    static const std::string kName = "#N ";
    static const std::string kRule = "#R ";
    static const std::string kBirthRule = "B";
    static const std::string kSurviveRule = "/S";
    static const std::string kSize = "#S ";
    static const std::string kSpace = " ";
    static const std::string kDefaultOutFilename = "../default_output.txt";

    class Game {
    private:
        static const int kAliveCell = 1;
        static const int kDeadCell = 0;

    public:
        static void nextStep(Universe *universe);

        static int getCountOfNearAliveCells(Universe universe, std::pair<int, int> pos);

        static void dump(Universe *universe);
    };

}
#endif //LIFE_GAME_H
