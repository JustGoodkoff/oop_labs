//
// Created by 79631 on 31.12.2022.
//

#ifndef LIFE_COMMANDLINEPARSER_H
#define LIFE_COMMANDLINEPARSER_H
#include "CmdParsedData.h"

class CommandLineParser {
public:
    CommandLineParser(int argc, char **argv);
    CommandLineParser();
    CmdParsedData parseData();

private:
    int arg_num;
    char** args;
};


#endif //LIFE_COMMANDLINEPARSER_H
