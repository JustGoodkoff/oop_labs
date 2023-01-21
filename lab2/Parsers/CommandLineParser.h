//
// Created by 79631 on 31.12.2022.
//

#ifndef LIFE_COMMANDLINEPARSER_H
#define LIFE_COMMANDLINEPARSER_H
#include "CmdParsedData.h"


static const char *const kShortOutputFilenameCommand = "-o";
static const char *const kFullOutputFilenameCommand = "--output=";
static const int kFOFCommandLength = 9;
static const char *const kShortIterationsCommand = "-i";
static const char *const kFullIterationsCommand = "--iterations=";
static const int kFICommandLength = 13;
static const char *const kInputFilenameCommand = "-if";
static const int kDefaultIterations = 5;

static const std::string kDefaultOutputFilename = "../default_output.txt";

static const std::string kIncorrectIterationsMsg = "Iterations were incorrectly supplied to the command line, the default value is set to 5\n";

class CommandLineParser {
public:
    CommandLineParser(int argc, char **argv);
    CommandLineParser();
    CmdParsedData parseData();

private:
    int argNum;
    char** args;
};


#endif //LIFE_COMMANDLINEPARSER_H
