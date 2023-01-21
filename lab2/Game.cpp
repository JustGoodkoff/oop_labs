//
// Created by 79631 on 31.12.2022.
//

#include <fstream>
#include "Game.h"
#include "Universe.h"

namespace GameOfLife {


    int Game::getCountOfNearAliveCells(Universe universe, std::pair<int, int> pos) {
        int x = pos.first;
        int y = pos.second;
        int max_x = universe.getSize().first;
        int max_y = universe.getSize().second;
        return universe.getField()[std::make_pair((x + 1) % max_x, y)] +
               universe.getField()[std::make_pair((x + 1) % max_x, (y + 1) % max_y)] +
               universe.getField()[std::make_pair(x, (y + 1) % max_y)] +
               universe.getField()[std::make_pair((x - 1 < 0 ? max_x + (x - 1) : (x - 1)), y)] +
               universe.getField()[std::make_pair((x - 1 < 0 ? max_x + (x - 1) : (x - 1)),
                                                  (y - 1 < 0 ? max_y + (y - 1) : (y - 1)))] +
               universe.getField()[std::make_pair(x, (y - 1 < 0 ? max_y + (y - 1) : (y - 1)))] +
               universe.getField()[std::make_pair(x - 1 < 0 ? max_x + (x - 1) : (x - 1), (y + 1) % max_y)] +
               universe.getField()[std::make_pair((x + 1) % max_x, (y - 1 < 0 ? max_y + (y - 1) : (y - 1)))];

    }

    void Game::nextStep(Universe *universe) {
        std::map<std::pair<int, int>, int> new_field;
        for (int i = 0; i < universe->getSize().first; i++) {
            for (int j = 0; j < universe->getSize().second; j++) {
                if (universe->getField()[std::make_pair(i, j)] == kDeadCell) {
                    if (universe->getBirthRule().find(getCountOfNearAliveCells(*universe, std::make_pair(i, j))) !=
                        universe->getBirthRule().end()) {
                        new_field[std::make_pair(i, j)] = kAliveCell;
                    }
                } else {
                    if (universe->getSurviveRule().find(getCountOfNearAliveCells(*universe, std::make_pair(i, j))) !=
                        universe->getSurviveRule().end()) {
                        new_field[std::make_pair(i, j)] = kAliveCell;
                    }
                }
            }
        }
        universe->setField(new_field);
    }


    void Game::dump(Universe *universe) {
        std::ofstream outputFile;
        outputFile.open(universe->getOutputFilename());
        if (!outputFile.is_open()) {
            outputFile.open(kDefaultOutFilename);
        }
        if (outputFile.is_open()) {
            outputFile.clear();
            outputFile << kLifeVersion << "\n";
            outputFile << kName << universe->getUniverseName() << "\n";
            outputFile << kRule << kBirthRule;
            for (int i: universe->getBirthRule()) {
                outputFile << i;
            }
            outputFile << kSurviveRule;
            for (int i: universe->getSurviveRule()) {
                outputFile << i;
            }
            outputFile << "\n";
            outputFile << kSize << universe->getSize().first << kSpace << universe->getSize().second << "\n";
            for (int i = 0; i < universe->getSize().first; i++) {
                for (int j = 0; j < universe->getSize().second; j++) {
                    if (universe->getField()[std::make_pair(i, j)] == kAliveCell) {
                        outputFile << i << " " << j << "\n";
                    }
                }
            }
        }
        outputFile.close();
    }

}