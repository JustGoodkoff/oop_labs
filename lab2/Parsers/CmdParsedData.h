//
// Created by 79631 on 31.12.2022.
//

#ifndef LIFE_CMDPARSEDDATA_H
#define LIFE_CMDPARSEDDATA_H
#include "fstream"
namespace GameOfLife {
    class CmdParsedData {
    public:
        const std::string &getInputFilename() const;

        void setInputFilename(const std::string &inputFilename);

        const std::string &getOutputFilename() const;

        void setOutputFilename(const std::string &outputFilename);

        int getIterations() const;

        void setIterations(int iterations);

    private:
        std::string inputFilename;
        std::string outputFilename;
        int iterations = 0;
    };

}
#endif //LIFE_CMDPARSEDDATA_H
