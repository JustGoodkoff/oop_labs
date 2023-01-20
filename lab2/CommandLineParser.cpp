//
// Created by 79631 on 31.12.2022.
//

#include <iostream>
#include <cstring>
#include "CommandLineParser.h"

CommandLineParser::CommandLineParser(int argc, char **argv) {
    arg_num = argc;
    args = argv;
}

CommandLineParser::CommandLineParser() {}

CmdParsedData CommandLineParser::parseData() {
    CmdParsedData data = CmdParsedData();
    std::string s;

    for (int i = 1; i < this->arg_num; i++) {
        if ((strcmp(args[i], "-o") == 0)) {
            data.setOutputFilename(args[++i]);
        } else if (strncmp(args[i], "--output=", 9) == 0) {
            data.setOutputFilename(std::string(args[i]).substr(9));
        } else if (strcmp(args[i], "-i") == 0) {
            std::string iter = args[i];
            try{
                data.setIterations(std::stoi(args[++i]));
            }
            catch (std::invalid_argument& ex) {
                data.setIterations(5);
            }
        } else if (strncmp(args[i], "--iterations=", 13) == 0) {
            if (args[i] == nullptr) {
                data.setIterations(5);
                continue;
            }
            try {
                std::string it  = args[i];
                it = it.substr(13);
                data.setIterations(std::stoi(it));
            }
            catch (std::invalid_argument& ex) {
                std::cout << "iterations were incorrectly supplied to the command line, the default value is set to 5\n";
                data.setIterations(5);
            }

        } else if (strcmp(args[i], "-if") == 0) {
            std::string inputFilename = args[++i];
            if (inputFilename.empty()) {
                data.setInputFilename("../qwe.txt");
            } else {
                data.setInputFilename(args[i]);
            }
        }

    }
    return data;
};






