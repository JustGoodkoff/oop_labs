//
// Created by 79631 on 01.01.2023.
//

#include "FileParsedData.h"


FileParsedData::FileParsedData() {}

const std::map<std::pair<int, int>, int> &FileParsedData::getField() const {
    return field;
}

void FileParsedData::setField(const std::map<std::pair<int, int>, int> &field) {
    FileParsedData::field = field;
}

const std::set<int> &FileParsedData::getSurviveRule() const {
    return survive_rule;
}

void FileParsedData::setSurviveRule(const std::set<int> &surviveRule) {
    survive_rule = surviveRule;
}

const std::set<int> &FileParsedData::getBirthRule() const {
    return birth_rule;
}

void FileParsedData::setBirthRule(const std::set<int> &birthRule) {
    birth_rule = birthRule;
}

const std::string &FileParsedData::getUniverseName() const {
    return universe_name;
}

void FileParsedData::setUniverseName(const std::string &universeName) {
    universe_name = universeName;
}

const std::pair<int, int> &FileParsedData::getSize() const {
    return size;
}

void FileParsedData::setSize(const std::pair<int, int> &size) {
    FileParsedData::size = size;
}

FileParsedData::FileParsedData(const std::map<std::pair<int, int>, int> &field, const std::set<int> &surviveRule,
                               const std::set<int> &birthRule, const std::string &universeName,
                               const std::pair<int, int> &size) {

}



