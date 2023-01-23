//
// Created by 79631 on 31.12.2022.
//

#include <iostream>
#include "GameInterface.h"
#include "Parsers/CommandLineParser.h"
#include "Game.h"
#include "Parsers/InputFileParser.h"
#include "GameModes/OnlineGameMode.h"
#include "GameModes/OfflineGameMode.h"

namespace GameOfLife {

    void GameInterface::startGame(int argc, char **argv) {
        std::string gameMode = GameInterface::chooseGameMode();
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


        if (gameMode == kOnlineMode) {
            OnlineGameMode::startOnlineGame(&universe);
        } else if (gameMode == kOfflineMode) {
            OfflineGameMode::startOfflineMode(&universe);
        }
        GameInterface::print_universe(universe);

    }

    void GameInterface::print_universe(Universe universe) {
        for (int i = 0; i < universe.getSize().first; i++) {
            for (int j = 0; j < universe.getSize().second; j++) {
                if (universe.getField()[std::make_pair(i, j)]) {
                    std::cout << kAliveCellOut;
                } else {
                    std::cout << kDeadCellOut;
                }
            }
            std::cout << "\n";
        }
    }


    std::string GameInterface::chooseGameMode() {
        std::string gameMode;
        while (gameMode != kOnlineMode && gameMode != kOfflineMode) {
            std::cout << kChooseMode << std::endl;
            std::cin >> gameMode;
        }
        return gameMode;
    }

}
