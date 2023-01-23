//
// Created by 79631 on 31.12.2022.
//

#include "CmdParsedData.h"

namespace GameOfLife {
    const std::string &CmdParsedData::getInputFilename() const {
        return inputFilename;
    }

    void CmdParsedData::setInputFilename(const std::string &inputFilename) {
        this->inputFilename = inputFilename;
    }

    const std::string &CmdParsedData::getOutputFilename() const {
        return outputFilename;
    }

    void CmdParsedData::setOutputFilename(const std::string &outputFilename) {
        this->outputFilename = outputFilename;
    }

    int CmdParsedData::getIterations() const {
        return iterations;
    }

    void CmdParsedData::setIterations(int iterations) {
        CmdParsedData::iterations = iterations;
    }
}