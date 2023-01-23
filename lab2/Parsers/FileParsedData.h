//
// Created by 79631 on 01.01.2023.
//

#ifndef LIFE_FILEPARSEDDATA_H
#define LIFE_FILEPARSEDDATA_H


#include <vector>
#include <string>
#include <map>
#include <set>

namespace GameOfLife {

    class FileParsedData {
    private:
        std::map<std::pair<int, int>, int> field;
        std::set<int> surviveRule;
        std::set<int> birthRule;
        std::string universeName;
        std::pair<int, int> size = {-1, -1};
    public:
        FileParsedData();

        FileParsedData(const std::map<std::pair<int, int>, int> &field, const std::set<int> &surviveRule,
                       const std::set<int> &birthRule, const std::string &universeName,
                       const std::pair<int, int> &size);

        const std::map<std::pair<int, int>, int> &getField() const;

        void setField(const std::map<std::pair<int, int>, int> &field);

        const std::set<int> &getSurviveRule() const;

        void setSurviveRule(const std::set<int> &surviveRule);

        const std::set<int> &getBirthRule() const;

        void setBirthRule(const std::set<int> &birthRule);

        const std::string &getUniverseName() const;

        void setUniverseName(const std::string &universeName);

        const std::pair<int, int> &getSize() const;

        void setSize(const std::pair<int, int> &size);
    };

}
#endif //LIFE_FILEPARSEDDATA_H
