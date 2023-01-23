#include <iostream>
#include "Parsers/CommandLineParser.h"
#include "GameInterface.h"

using namespace GameOfLife;

int main(int argc, char* argv[]) {
    GameInterface::startGame(argc, argv);
    return 0;
}
