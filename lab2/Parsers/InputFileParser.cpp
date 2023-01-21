//
// Created by 79631 on 01.01.2023.
//

#include <cstring>
#include <iostream>
#include "InputFileParser.h"
#include "fstream"
#include "../Game.h"
#include <time.h>

namespace GameOfLife {

    std::pair<int, int> parseCellCoordinates(std::string buf) {
        int i = 0;
        std::string firstStrNum;
        std::string secondStrNum;
        int start = -1;
        int count = 0;
        while (i < buf.length()) {
            if (isdigit(buf[i])) {
                if (start == -1) {
                    start = i;
                }
                count += 1;
            } else if (buf[i] == kSpaceChar) {
                if (firstStrNum.empty()) {
                    firstStrNum = buf.substr(start, count);
                } else if (secondStrNum.empty()) {
                    secondStrNum = buf.substr(start, count);
                } else {
                    break;
                }
                start = -1;
                count = 0;
            } else {
                throw std::invalid_argument(kIncorrectSizeMsg);
            }
            ++i;
        }
        if (count > 0 && secondStrNum.empty()) {
            secondStrNum = buf.substr(start, count);
        }
        int firstNum = std::stoi(firstStrNum);
        int secondNum = std::stoi(secondStrNum);
        firstNum = firstNum < 0 ? 0 : firstNum;
        secondNum = secondNum < 0 ? 0 : secondNum;
        return std::make_pair(firstNum, secondNum);
    }

    std::string parseUniverseName(std::string buf) {
        int i = 0;
        if (buf.empty() || buf.length() <= 3) {
            throw std::invalid_argument(kIncorrectUniverseNameMsg);
        }
        std::string uName;
        while (i < buf.length()) {
            if (buf[i] == kHashChar && buf[i + 1] == kUniverseNameChar) {
                uName = buf.substr(i + 3, buf.length() - (i + 1));
            }
            ++i;
        }
        return uName;
    }

    std::pair<std::set<int>, std::set<int>> parseRules(std::string buf) {
        int i = 0;
        std::set<int> survival;
        std::set<int> birth;
        while (i < buf.length()) {
            if (buf[i] == kBirthChar || buf[i] == kSurvivalChar) {
                int j = 1;
                while (j < buf.length() - i) {
                    if (isdigit(buf[i + j])) {
                        int cur_num;
                        try {
                            cur_num = std::stoi(std::string(1, buf[i + j]));
                        }
                        catch (std::invalid_argument &ex1) {
                            continue;
                        }
                        if (cur_num >= 0 && cur_num <= 8) {
                            if (buf[i] == kBirthChar) {
                                birth.insert(cur_num);
                            } else if (buf[i] == kSurvivalChar) {
                                survival.insert(cur_num);
                            }
                        }
                    } else {
                        break;
                    }
                    j += 1;
                }
            }
            i += 1;
        }
        return std::make_pair(birth, survival);
    }


    FileParsedData InputFileParser::parse(std::string filename) {
        FileParsedData data = FileParsedData();
        std::fstream fstream;
        fstream.open(filename);
        if (!fstream.is_open()) {
            srand(time(NULL));
            fstream.open(kUniverseExamplesPath + universes[rand() % (universes.size())]);
        }
        std::string buf;
        std::pair<std::set<int>, std::set<int>> rules;
        std::map<std::pair<int, int>, int> coordinates;
        if (fstream.is_open()) {
            while (std::getline(fstream, buf)) {
                int i = 0;
                while (i < buf.length()) {
                    if (buf[i] == kHashChar) {
                        if (buf[i + 1] == kUniverseNameChar) {
                            try {
                                data.setUniverseName(parseUniverseName(buf));
                            }
                            catch (std::invalid_argument &ex) {
                                std::cout << ex.what() << "\n";
                                data.setUniverseName(kDefaultUniverseName);
                            }
                            break;
                        } else if (buf[i + 1] == kSurvivalChar) {
                            try {
                                data.setSize(parseCellCoordinates(buf.substr((i + 3), buf.length() - (i + 1))));
                            }
                            catch (std::invalid_argument &ex) {
                                std::cout << ex.what() << "\n";
                                data.setSize(std::make_pair(kDefaultSize, kDefaultSize));
                            }
                            break;
                        } else if (buf[i + 1] == kRuleChar) {
                            rules = parseRules(buf);
                            break;
                        } else if (buf == kFormat) {
                            break;
                        }
                    } else {
                        try {
                            coordinates[parseCellCoordinates(buf)] = kAliveCell;
                        }
                        catch (std::invalid_argument &ex) {
                            std::cout << kIgnoreInvalidDataMsg;
                        }
                        break;
                    }
                    i += 1;
                }
            }
            data.setBirthRule(rules.first);
            data.setSurviveRule(rules.second);
            data.setField(coordinates);
            fstream.close();
            if (data.getUniverseName().empty()) {
                data.setUniverseName(kDefaultUniverseName);
            }
            if (data.getSurviveRule().empty()) {
                data.setSurviveRule({kDefaultSurvivalRuleFirst, kDefaultSurvivalRuleSecond});
            }
            if (data.getBirthRule().empty()) {
                data.setBirthRule({kDefaultBirthRule});
            }
            if (data.getSize().first == kNoSize || data.getSize().second == kNoSize) {
                data.setSize(std::make_pair(kDefaultSize, kDefaultSize));
            }
        }
        return data;
    }

    InputFileParser::InputFileParser(std::string inputFilename) {
        filename = inputFilename;
    }

}