//
// Created by 79631 on 18.01.2023.
//

#include <iostream>
#include "OnlineGameMode.h"
#include "../GameInterface.h"
#include "../Parsers/CommandLineParser.h"


void OnlineGameMode::startOnlineGame(Universe *universe) {
    std::string command;
    std::cout << kFirstMessage;
    std::getline(std::cin, command);
    int tickCount = 0;
    while (command != kExitCommand) {
        if(command.substr(0, kTickCommandLength) == kDumpCommand) {
            std::string output_filename;
            try {
                output_filename = command.substr(kTickCommandLength + 1);
            } catch (std::out_of_range& ex) {
                std::cout << kIncorrectOutputFilename;
                output_filename = kDefaultOutputFilename;
            }
            universe->setOutputFilename(output_filename);
            OnlineGameMode::dump(universe);
        }
        else if (command.substr(0, kTickCommandLength) == kTickCommand) {
            int tick;
            try {
                tick = std::stoi(command.substr(kTickCommandLength + 1));
            } catch (std::invalid_argument& ex) {
                std::cout << kIncorrectNumberOfTicks;
                tick = 0;
            } catch (std::out_of_range& ex) {
                tick = 1;
            }
            if (tick < 0) {
                std::cout << kIncorrectNumberOfTicks;
                tick = 0;
            }
            tickCount += tick;
            for (int i = 0; i < tick; i++) {
                nextStep(universe);
            }
            std::cout << universe->getUniverseName() << "\n";
            std::cout << kRule << kBirthRule;
            for(int i : universe->getBirthRule()) {
                std::cout << i;
            }
            std::cout << kSurviveRule;
            for(int i : universe->getSurviveRule()) {
                std::cout << i;
            }
            std::cout << "\n" << tickCount << "\n";
            GameInterface::print_universe(*universe);
        }
        else if (command == kHelpCommand) {
            std::cout << kHelpMessage;
        }
        else {
            std::cout << "";
        }
        std::cout << kEnterCommand;
        std::getline(std::cin, command);
    }

}