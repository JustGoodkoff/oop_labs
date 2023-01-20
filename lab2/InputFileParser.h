//
// Created by 79631 on 01.01.2023.
//

#ifndef LIFE_INPUTFILEPARSER_H
#define LIFE_INPUTFILEPARSER_H


#include <string>
#include "FileParsedData.h"

class InputFileParser {
    const std::string game_version_h = "#Life 1.06";
    const std::string name_h = "#N";
    const std::string rule_h = "#R";
    const std::string size_h = "#S";
private:
    std::string filename;
public:
    InputFileParser(std::string in_filename);
    FileParsedData parse(std::string filename);

    const std::string &getFilename() const;

    void setFilename(const std::string &filename);
};


#endif //LIFE_INPUTFILEPARSER_H
