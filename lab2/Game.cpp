//
// Created by 79631 on 31.12.2022.
//

#include <fstream>
#include "Game.h"
#include "Universe.h"

int Game::getCountOfNearAliveCells(Universe universe, std::pair<int, int> pos) {
    int x = pos.first;
    int y = pos.second;
    int max_x = universe.getSize().first;
    int max_y = universe.getSize().second;
    return universe.getField()[std::make_pair((x + 1) % max_x, y)] +
    universe.getField()[std::make_pair((x + 1) % max_x, (y + 1) % max_y)] +
            universe.getField()[std::make_pair(x, (y + 1) % max_y)] +
            universe.getField()[std::make_pair((x - 1 < 0 ? max_x + (x - 1) : (x - 1)), y)] +
            universe.getField()[std::make_pair((x - 1 < 0 ? max_x + (x - 1) : (x - 1)), (y - 1 < 0 ? max_y + (y - 1) : (y - 1)))] +
            universe.getField()[std::make_pair(x, (y - 1 < 0 ? max_y + (y - 1) : (y - 1)))] +
            universe.getField()[std::make_pair(x - 1 < 0 ? max_x + (x - 1) : (x - 1), (y + 1) % max_y)] +
            universe.getField()[std::make_pair((x + 1) % max_x,(y - 1 < 0 ? max_y + (y - 1) : (y - 1)))];

}

 void Game::nextStep(Universe *universe) {
    std::map<std::pair<int, int>, int> new_field;
    for(int i = 0; i < universe->getSize().first; i++) {
        for(int j = 0; j < universe->getSize().second; j++) {
            if (universe->getField()[std::make_pair(i, j)] == 0) {
                if (universe->getBirthRule().find(getCountOfNearAliveCells(*universe, std::make_pair(i, j))) != universe->getBirthRule().end()) {
                    new_field[std::make_pair(i, j)] = 1;
                }
            }
            else {
                if (universe->getSurviveRule().find(getCountOfNearAliveCells(*universe, std::make_pair(i, j))) != universe->getSurviveRule().end()) {
                    new_field[std::make_pair(i, j)] = 1;
                }
            }
        }
    }
    universe->setField(new_field);
}


void Game::dump(Universe *universe) {
    std::ofstream outputFile;
    outputFile.open(universe->getOutputFilename());
    if(outputFile.is_open()) {
        outputFile.clear();
        outputFile << "#Life 1.06\n";
        outputFile << "#N " << universe->getUniverseName() << "\n";
        outputFile << "#R B";
        for(int i : universe->getBirthRule()) {
            outputFile << i;
        }
        outputFile << "/S";
        for (int i : universe->getSurviveRule()) {
            outputFile << i;
        }
        outputFile << "\n";
        for(int i = 0; i < universe->getField().size(); i++) {
            for (int j = 0; j < universe->getField().size(); j ++) {
                if (universe->getField()[std::make_pair(i, j)] == 1) {
                    outputFile << i << " " << j << "\n";
                }
            }
        }
    }
    outputFile.close();
}
