//
// Created by 79631 on 21.01.2023.
//

#include <gtest/gtest.h>
#include <fstream>
#include "../Game.h"
#include "../GameInterface.h"
#include "../Universe.h"
#include "../Parsers/InputFileParser.h"
#include "../Parsers/FileParsedData.h"

namespace GameOfLife {

    TEST(GameMechanics, getCountOfNearAliveCells) {
        InputFileParser parser = InputFileParser("../../test/test-universe1.txt");
        FileParsedData fpd = parser.parse("../../test/test-universe1.txt");
        Universe universe = Universe();
        universe.setSurviveRule(fpd.getSurviveRule());
        universe.setBirthRule(fpd.getBirthRule());
        universe.setSize(fpd.getSize());
        universe.setField(fpd.getField());
        universe.setUniverseName(fpd.getUniverseName());

        std::vector<int> trueCountOfCells = {1, 3, 1, 2, 0, 0, 0, 1,
                                             1, 5, 3, 3, 0, 0, 0, 1,
                                             2, 3, 2, 2, 0, 0, 0, 1,
                                             1, 2, 2, 1, 0, 0, 0, 0,
                                             0, 0, 0, 0, 0, 0, 0, 0,
                                             0, 0, 0, 0, 0, 0, 0, 0,
                                             0, 0, 0, 0, 0, 0, 0, 0,
                                             0, 1, 1, 1, 0, 0, 0, 0};
        std::vector<int> countOfCells;

        for (int i = 0; i < universe.getSize().first; i++) {
            for (int j = 0; j < universe.getSize().second; j++) {
                countOfCells.push_back(Game::getCountOfNearAliveCells(universe, std::make_pair(i, j)));
            }
        }
        EXPECT_EQ(trueCountOfCells, countOfCells);
    }


    TEST(GameMechanics, OutputInFile) {
        InputFileParser parser = InputFileParser("../../test/test-universe1.txt");
        FileParsedData fpd = parser.parse("../../test/test-universe1.txt");
        Universe universe = Universe();
        universe.setSurviveRule(fpd.getSurviveRule());
        universe.setBirthRule(fpd.getBirthRule());
        universe.setSize(fpd.getSize());
        universe.setField(fpd.getField());
        universe.setUniverseName(fpd.getUniverseName());
        universe.setOutputFilename("../../test/test-output1.txt");
        Game::dump(&universe);

        InputFileParser parser1 = InputFileParser("../test/test-output1.txt");
        FileParsedData fpd1 = parser.parse("../test/test-output1.txt");
        Universe universe1 = Universe();
        universe1.setSurviveRule(fpd.getSurviveRule());
        universe1.setBirthRule(fpd.getBirthRule());
        universe1.setSize(fpd.getSize());
        universe1.setField(fpd.getField());
        universe1.setUniverseName(fpd.getUniverseName());
        std::map<std::pair<int, int>, int> u1;
        u1.insert({std::make_pair(0, 2), 1});
        u1.insert({std::make_pair(1, 0), 1});
        u1.insert({std::make_pair(1, 2), 1});
        u1.insert({std::make_pair(2, 1), 1});
        u1.insert({std::make_pair(2, 2), 1});
        EXPECT_EQ(universe1.getSize().first, 8);
        EXPECT_EQ(universe1.getSize().second, 8);
        EXPECT_EQ(universe1.getBirthRule(), std::set<int>{3});
        std::set<int> survivalRuleTest = {2, 3};
        EXPECT_EQ(universe1.getSurviveRule(), survivalRuleTest);
        EXPECT_EQ(universe1.getField(), u1);
        EXPECT_EQ(universe1.getUniverseName(), "Glider");

    }


    TEST(GameMechanics, OutputInFile1) {
        InputFileParser parser = InputFileParser("../../test/bad-test-universe1.txt");
        FileParsedData fpd = parser.parse("../../test/bad-test-universe1.txt");
        Universe universe = Universe();
        universe.setSurviveRule(fpd.getSurviveRule());
        universe.setBirthRule(fpd.getBirthRule());
        universe.setSize(fpd.getSize());
        universe.setField(fpd.getField());
        universe.setUniverseName(fpd.getUniverseName());
        universe.setOutputFilename("../../test/bad-test-output1.txt");
        Game::dump(&universe);

        InputFileParser parser1 = InputFileParser("../test/bad-test-output1.txt");
        FileParsedData fpd1 = parser.parse("../test/bad-test-output1.txt");
        Universe universe1 = Universe();
        universe1.setSurviveRule(fpd.getSurviveRule());
        universe1.setBirthRule(fpd.getBirthRule());
        universe1.setSize(fpd.getSize());
        universe1.setField(fpd.getField());
        universe1.setUniverseName(fpd.getUniverseName());
        std::map<std::pair<int, int>, int> u1;
        u1.insert({std::make_pair(0, 2), 1});
        u1.insert({std::make_pair(1, 0), 1});
        u1.insert({std::make_pair(1, 2), 1});
        u1.insert({std::make_pair(2, 1), 1});
        u1.insert({std::make_pair(2, 2), 1});
        EXPECT_EQ(universe1.getBirthRule(), std::set<int>{3});
        std::set<int> survivalRuleTest = {2, 3};
        EXPECT_EQ(universe1.getSurviveRule(), survivalRuleTest);
        EXPECT_EQ(universe1.getSize().first, 8);
        EXPECT_EQ(universe1.getSize().second, 8);
        EXPECT_EQ(universe1.getField(), u1);
        EXPECT_EQ(universe1.getUniverseName(), "My universe");
    }

    TEST(GameMechanics, NextStep) {
        InputFileParser parser = InputFileParser("../../test/test-universe1.txt");
        FileParsedData fpd = parser.parse("../../test/test-universe1.txt");
        Universe universe = Universe();
        universe.setSurviveRule(fpd.getSurviveRule());
        universe.setBirthRule(fpd.getBirthRule());
        universe.setSize(fpd.getSize());
        universe.setField(fpd.getField());
        universe.setUniverseName(fpd.getUniverseName());
        universe.setOutputFilename("../../test/test-output1.txt");
        Game::nextStep(&universe);
        std::map<std::pair<int, int>, int> field;
        field.insert({std::make_pair(0, 1), 1});
        field.insert({std::make_pair(1, 2), 1});
        field.insert({std::make_pair(1, 3), 1});
        field.insert({std::make_pair(2, 1), 1});
        field.insert({std::make_pair(2, 2), 1});
        EXPECT_EQ(field, universe.getField());
    }
}