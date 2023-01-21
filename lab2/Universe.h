//
// Created by 79631 on 01.01.2023.
//

#ifndef LIFE_UNIVERSE_H
#define LIFE_UNIVERSE_H


#include <vector>
#include <string>
#include <map>
#include <set>



    class Universe {
    public:

        Universe();

        Universe(std::map<std::pair<int, int>, int> &field, const std::set<int> &surviveRule,
                 const std::set<int> &birthRule,
                 const std::string &universeName, const std::pair<int, int> &size);

        std::map<std::pair<int, int>, int> getField();

        void setField(const std::map<std::pair<int, int>, int> &field);

        const std::string &getUniverseName() const;

        void setUniverseName(const std::string &universeName);

        const std::pair<int, int> &getSize() const;

        void setSize(const std::pair<int, int> &size);

    private:
        std::map<std::pair<int, int>, int> field;
        std::set<int> surviveRule;
    public:
        const std::set<int> &getSurviveRule() const;

        void setSurviveRule(const std::set<int> &surviveRule);

        const std::set<int> &getBirthRule() const;

        void setBirthRule(const std::set<int> &birthRule);

    private:
        std::set<int> birthRule;
        std::string universeName;
        std::pair<int, int> size;
        std::string inputFilename;
    public:
        const std::string &getInputFilename() const;

        void setInputFilename(const std::string &inputFilename);

        const std::string &getOutputFilename() const;

        void setOutputFilename(const std::string &outputFilename);

        int getIterations() const;

        void setIterations(int iterations);

    private:
        std::string outputFilename;
        int iterations;


    };


#endif //LIFE_UNIVERSE_H
