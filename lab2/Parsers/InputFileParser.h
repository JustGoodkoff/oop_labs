//
// Created by 79631 on 01.01.2023.
//

#ifndef LIFE_INPUTFILEPARSER_H
#define LIFE_INPUTFILEPARSER_H


#include <string>
#include "FileParsedData.h"

static const std::string kDefaultUniverseName = "My universe";
static const std::string kIgnoreInvalidDataMsg = "Invalid data in the file was ignored\n";
static const std::string kIncorrectUniverseNameMsg = "Incorrectly entered universe name has been replaced with the standard one\n";
static const std::string kIncorrectSizeMsg = "Incorrectly entered data about the size have been replaced with standard ones\n";
static const std::string kFormat = "#Life 1.06";

static const char kBirthChar = 'B';
static const char kSurvivalChar = 'S';
static const char kRuleChar = 'R';
static const char kUniverseNameChar = 'N';
static const char kHashChar = '#';
static const char kSpaceChar = ' ';

static const int kAliveCell = 1;
static const int kDefaultSurvivalRuleFirst = 2;
static const int kDefaultSurvivalRuleSecond = 3;
static const int kDefaultBirthRule = 3;
static const int kDefaultSize = 8;
static const int kNoSize = -1;

static const std::string kUniverseExamplesPath = "../universe-examples/";





class InputFileParser {

private:
    std::string filename;
public:
    InputFileParser(std::string in_filename);
    FileParsedData parse(std::string filename);

    const std::string &getFilename() const;

    void setFilename(const std::string &filename);
};


#endif //LIFE_INPUTFILEPARSER_H
