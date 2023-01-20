//
// Created by 79631 on 31.12.2022.
//

#include <iostream>
#include <cstring>
#include "GameInterface.h"
#include "CommandLineParser.h"
#include "Game.h"
#include "fstream"
#include "Universe.h"
#include "InputFileParser.h"
#include "OnlineGameMode.h"
#include "OfflineGameMode.h"

void GameInterface::startGame(int argc, char **argv) {
    std::string game_mode = GameInterface::chooseGameMode();
    CommandLineParser commandLineParser = CommandLineParser(argc, argv);
    CmdParsedData data = commandLineParser.parseData();
    InputFileParser inputFileParser = InputFileParser(data.getInputFilename());
    FileParsedData fpd = inputFileParser.parse(data.getInputFilename());
    Universe universe = Universe();
    universe.setSurviveRule(fpd.getSurviveRule());
    universe.setBirthRule(fpd.getBirthRule());
    universe.setSize(fpd.getSize());
    universe.setField(fpd.getField());
    universe.setUniverseName(fpd.getUniverseName());

    universe.setIterations(data.getIterations());
    universe.setOutputFilename(data.getOutputFilename());
    universe.setInputFilename(data.getInputFilename());


    if (game_mode == "online") {
        OnlineGameMode::startOnlineGame(&universe);
    } else if (game_mode == "offline") {
        OfflineGameMode::startOfflineMode(&universe);
    }
    GameInterface::print_universe(universe);

}

void GameInterface::print_universe(Universe universe) {
    for (int i = 0; i < universe.getSize().first; i++) {
        for (int j = 0; j < universe.getSize().second; j++) {
            std::cout << universe.getField()[std::make_pair(i, j)] << " ";
        }
        std::cout << "\n";
    }
}


std::string GameInterface::chooseGameMode() {
    std::string game_mode;
    while (game_mode != "online" && game_mode != "offline") {
        std::cout << "Vvedit rezhim (online/offline)" << std::endl;
        std::cin >> game_mode;
    }
    return game_mode;
}

