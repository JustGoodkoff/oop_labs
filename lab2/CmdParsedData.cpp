//
// Created by 79631 on 31.12.2022.
//

#include "CmdParsedData.h"


const std::string &CmdParsedData::getInputFilename() const {
    return input_filename;
}

void CmdParsedData::setInputFilename(const std::string &inputFilename) {
    input_filename = inputFilename;
}

const std::string &CmdParsedData::getOutputFilename() const {
    return output_filename;
}

void CmdParsedData::setOutputFilename(const std::string &outputFilename) {
    output_filename = outputFilename;
}

int CmdParsedData::getIterations() const {
    return iterations;
}

void CmdParsedData::setIterations(int iterations) {
    CmdParsedData::iterations = iterations;
}
