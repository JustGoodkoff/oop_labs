//
// Created by 79631 on 01.01.2023.
//

#include <cstring>
#include <iostream>
#include "InputFileParser.h"
#include "fstream"


std::pair<int, int> parseCellCoordinates(std::string buf) {
    int i = 0;
    std::string first_str_num;
    std::string second_str_num;
    int start = -1;
    int count = 0;
    while (i < buf.length()) {
        if (isdigit(buf[i])) {
            if (start == -1) {
                start = i;
            }
            count += 1;
        } else if (buf[i] == ' '){
            if (first_str_num.empty()) {
                first_str_num = buf.substr(start, count);
            } else if (second_str_num.empty()) {
                second_str_num = buf.substr(start, count);
            } else {
                break;
            }
            start = -1;
            count = 0;
        } else {
            throw std::invalid_argument("Incorrectly entered data about the size have been replaced with standard ones");
        }
        ++i;
    }
    if (count > 0 && second_str_num.empty()) {
        second_str_num = buf.substr(start, count);
    }
    int first_num = std::stoi(first_str_num);
    int second_num = std::stoi(second_str_num);
    first_num = first_num < 0 ? 0 : first_num;
    second_num = second_num < 0 ? 0 : second_num;
    return std::make_pair(first_num, second_num);
}

std::string parseUniverseName(std::string buf) {
    int i = 0;
    if (buf.empty() || buf.length() <= 3) {
        throw std::invalid_argument("Incorrectly entered universe name has been replaced with the standard one");
    }
    std::string uName;
    while (i < buf.length()) {
        if (buf[i] == '#' && buf[i + 1] == 'N') {
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
        if (buf[i] == 'B' || buf[i] == 'S') {
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
                        if (buf[i] == 'B') {
                            birth.insert(cur_num);
                        } else if (buf[i] == 'S') {
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
    fstream.open("../" + filename);
    if(!fstream.is_open()) {
        fstream.open( "../qwe1.txt");
    }
    std::string buf;
    std::pair<std::set<int>, std::set<int>> rules;
    std::map<std::pair<int, int>, int> coordinates;
    if (fstream.is_open()) {
        while (std::getline(fstream, buf)) {
            int i = 0;
            while (i < buf.length()) {
                if (buf[i] == '#') {
                    if (buf[i + 1] == 'N') {
                        try {
                            data.setUniverseName(parseUniverseName(buf));
                        }
                        catch (std::invalid_argument& ex) {
                            std::cout << ex.what() << "\n";
                            data.setUniverseName("My universe");
                        }
                        break;
                    } else if (buf[i + 1] == 'S') {
                        try{
                            data.setSize(parseCellCoordinates(buf.substr((i + 3), buf.length() - (i + 1))));
                        }
                        catch (std::invalid_argument& ex) {
                            std::cout << ex.what() << "\n";
                            data.setSize(std::make_pair(8, 8));
                        }
                        break;
                    } else if (buf[i + 1] == 'R') {
                        rules = parseRules(buf);
                        break;
                    }
                } else {
                    try {
                        coordinates[parseCellCoordinates(buf)] = 1;
                    }
                   catch (std::invalid_argument& ex) {
                       std::cout << "invalid data in the file was ignored\n";
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
            data.setUniverseName("My universe");
        }
        if (data.getSurviveRule().empty()) {
//            std::set<int> sr = {2, 3};
            data.setSurviveRule({2, 3});
        }
        if (data.getBirthRule().empty()) {
//            std::set<int> br = {3};
            data.setBirthRule({3});
        }
        if (data.getSize().first == -1 || data.getSize().second == -1) {
            data.setSize(std::make_pair(8, 8));
        }
    }
    return data;
}

InputFileParser::InputFileParser(std::string in_filename) {
    filename = in_filename;
}
