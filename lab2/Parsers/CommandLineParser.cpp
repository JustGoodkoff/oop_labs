//
// Created by 79631 on 31.12.2022.
//

#include <iostream>
#include <cstring>
#include "../Game.h"
#include "CommandLineParser.h"
#include <time.h>


namespace GameOfLife {
    CommandLineParser::CommandLineParser(int argc, char **argv) {
        argNum = argc;
        args = argv;
    }

    CommandLineParser::CommandLineParser() {}

    CmdParsedData CommandLineParser::parseData() {
        CmdParsedData data = CmdParsedData();
        std::string s;

        for (int i = 1; i < this->argNum; i++) {
            if ((strcmp(args[i], kShortOutputFilenameCommand) == 0)) {
                data.setOutputFilename(args[++i]);
            } else if (strncmp(args[i], kFullOutputFilenameCommand, kFOFCommandLength) == 0) {
                data.setOutputFilename(std::string(args[i]).substr(kFOFCommandLength));
            } else if (strcmp(args[i], kShortIterationsCommand) == 0) {
                std::string iter = args[i];
                try {
                    data.setIterations(std::stoi(args[++i]));
                }
                catch (std::invalid_argument &ex) {
                    data.setIterations(kDefaultIterations);
                }
            } else if (strncmp(args[i], kFullIterationsCommand, kFICommandLength) == 0) {
                if (args[i] == nullptr) {
                    data.setIterations(kDefaultIterations);
                    continue;
                }
                try {
                    std::string it = args[i];
                    it = it.substr(kFICommandLength);
                    data.setIterations(std::stoi(it));
                }
                catch (std::invalid_argument &ex) {
                    std::cout << kIncorrectIterationsMsg;
                    data.setIterations(kDefaultIterations);
                }

            } else if (strcmp(args[i], kInputFilenameCommand) == 0) {
                std::string inputFilename = args[++i];
                if (inputFilename.empty()) {
                    inputFilename = universes[rand() % (universes.size() - 1)];
                    data.setInputFilename(inputFilename);
                } else {
                    data.setInputFilename(args[i]);
                }
            }
        }
        std::string inputFilename = data.getInputFilename();
        if (inputFilename.empty()) {
            srand(time(NULL));
            inputFilename = universes[rand() % (universes.size())];
            data.setInputFilename(inputFilename);
        }
        if (data.getOutputFilename().empty()) {
            data.setOutputFilename(kDefaultOutputFilename);
        }

        return data;
    };
}