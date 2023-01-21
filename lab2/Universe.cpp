//
// Created by 79631 on 01.01.2023.
//

#include "Universe.h"


    const std::string &Universe::getUniverseName() const {
        return universeName;
    }

    void Universe::setUniverseName(const std::string &universeName) {
        this->universeName = universeName;
    }

    const std::pair<int, int> &Universe::getSize() const {
        return size;
    }

    void Universe::setSize(const std::pair<int, int> &size) {
        Universe::size = size;
    }

    Universe::Universe(std::map<std::pair<int, int>, int> &field, const std::set<int> &surviveRule,
                       const std::set<int> &birthRule, const std::string &universeName, const std::pair<int, int> &size)
            : field(field), surviveRule(surviveRule), birthRule(birthRule), universeName(universeName), size(size) {}

    Universe::Universe() {}

    std::map<std::pair<int, int>, int> Universe::getField() {
        return field;
    }

    void Universe::setField(const std::map<std::pair<int, int>, int> &field) {
        Universe::field = field;
    }

    const std::set<int> &Universe::getSurviveRule() const {
        return surviveRule;
    }

    void Universe::setSurviveRule(const std::set<int> &surviveRule) {
        this->surviveRule = surviveRule;
    }

    const std::set<int> &Universe::getBirthRule() const {
        return birthRule;
    }

    void Universe::setBirthRule(const std::set<int> &birthRule) {
        this->birthRule = birthRule;
    }

    const std::string &Universe::getInputFilename() const {
        return inputFilename;
    }

    void Universe::setInputFilename(const std::string &inputFilename) {
        this->inputFilename = inputFilename;
    }

    const std::string &Universe::getOutputFilename() const {
        return outputFilename;
    }

    void Universe::setOutputFilename(const std::string &outputFilename) {
        this->outputFilename = outputFilename;
    }

    int Universe::getIterations() const {
        return iterations;
    }

    void Universe::setIterations(int iterations) {
        Universe::iterations = iterations;
    }



