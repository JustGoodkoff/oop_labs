//
// Created by 79631 on 01.01.2023.
//

#include "Universe.h"




const std::string &Universe::getUniverseName() const {
    return universe_name;
}

void Universe::setUniverseName(const std::string &universeName) {
    universe_name = universeName;
}

const std::pair<int, int> &Universe::getSize() const {
    return size;
}

void Universe::setSize(const std::pair<int, int> &size) {
    Universe::size = size;
}

Universe::Universe( std::map<std::pair<int, int>, int>  &field, const  std::set<int> &surviveRule,
                   const  std::set<int> &birthRule, const std::string &universeName, const std::pair<int, int> &size)
        : field(field), survive_rule(surviveRule), birth_rule(birthRule), universe_name(universeName), size(size) {}

Universe::Universe() {}

std::map<std::pair<int, int>, int> Universe::getField() {
    return field;
}

void Universe::setField(const std::map<std::pair<int, int>, int> &field) {
    Universe::field = field;
}

const std::set<int> &Universe::getSurviveRule() const {
    return survive_rule;
}

void Universe::setSurviveRule(const std::set<int> &surviveRule) {
    survive_rule = surviveRule;
}

const std::set<int> &Universe::getBirthRule() const {
    return birth_rule;
}

void Universe::setBirthRule(const std::set<int> &birthRule) {
    birth_rule = birthRule;
}

const std::string &Universe::getInputFilename() const {
    return input_filename;
}

void Universe::setInputFilename(const std::string &inputFilename) {
    input_filename = inputFilename;
}

const std::string &Universe::getOutputFilename() const {
    return output_filename;
}

void Universe::setOutputFilename(const std::string &outputFilename) {
    output_filename = outputFilename;
}

int Universe::getIterations() const {
    return iterations;
}

void Universe::setIterations(int iterations) {
    Universe::iterations = iterations;
}

