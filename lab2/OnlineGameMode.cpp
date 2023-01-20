//
// Created by 79631 on 18.01.2023.
//

#include <iostream>
#include "OnlineGameMode.h"
#include "GameInterface.h"


void OnlineGameMode::startOnlineGame(Universe *universe) {
    std::string command;
    std::getline(std::cin, command);
    int tickCount = 0;
    while (command != "exit") {
        if(command.substr(0, 4) == "dump") {
            std::string output_filename;
            try {
                output_filename = command.substr(5);
            } catch (std::out_of_range& ex) {
                std::cout << "Incorrectly entered file name, the default value is set to default_output.txt\n";
                output_filename = "../default_output.txt";
            }
            universe->setOutputFilename(output_filename);
            OnlineGameMode::dump(universe);
        }
        else if (command.substr(0, 4) == "tick") {
            int tick;
            try {
                tick = std::stoi(command.substr(5));
            } catch (std::invalid_argument& ex) {
                std::cout << "Incorrectly entered number of ticks, try again\n";
                tick = 0;
            } catch (std::out_of_range& ex) {
                std::cout << "Incorrectly entered number of ticks, try again\n";
                tick = 0;
            }
            if (tick < 0) {
                std::cout << "Incorrectly entered number of ticks, try again\n";
                tick = 0;
            }
            tickCount += tick;
            for (int i = 0; i < tick; i++) {
                nextStep(universe);
            }
            std::cout << universe->getUniverseName() << "\n";
            std::cout << "#R B";
            for(int i : universe->getBirthRule()) {
                std::cout << i;
            }
            std::cout << "/S";
            for(int i : universe->getSurviveRule()) {
                std::cout << i;
            }
            std::cout << "\n" << tickCount << "\n";
            GameInterface::print_universe(*universe);
        }
        else if (command == "help") {
            std::cout << kHelpMessage;
        }
        else {
            std::cout << "";
        }
        std::cout << "vvedite commandu: ";
        std::getline(std::cin, command);
    }

}