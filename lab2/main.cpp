#include <iostream>
#include "CommandLineParser.h"
#include "GameInterface.h"

int main(int argc, char* argv[]) {
    GameInterface::startGame(argc, argv);
    return 0;
}