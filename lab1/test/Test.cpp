//
// Created by 79631 on 12.11.2022.
//

#include <gtest/gtest.h>
#include "../BigInt.h"
#include <bits/stdc++.h>

namespace BigIntNS {


/**                          Constructors                          **/

    TEST(Constructors, DefaulConstructor) {
        BigInt a;
        EXPECT_EQ(a.getNumber(), "0");
    }

    TEST(Constructors, IntegerConstructor) {
        BigInt testVal = BigInt(0);
        BigInt testVal1 = BigInt(2147483647);
        BigInt testVal2 = BigInt(-2147483648);
        EXPECT_EQ(testVal1.getNumber(), "2147483647");
        EXPECT_EQ(testVal2.getNumber(), "-2147483648");
        EXPECT_EQ(testVal.getNumber(), "0");
    }

    TEST(Constructors, StringConstructor) {
        BigInt testVal = BigInt("0");
        BigInt testVal1 = BigInt("9999999999999999999999999999999999999999999999999999999999999999999999999");
        BigInt testVal2 = BigInt("-999999999999999999999999999999999999999999999999999999999999999999999999");
        EXPECT_EQ(testVal1.getNumber(), "9999999999999999999999999999999999999999999999999999999999999999999999999");
        EXPECT_EQ(std::string(testVal2), "-999999999999999999999999999999999999999999999999999999999999999999999999");
        EXPECT_EQ(testVal.getNumber(), "0");
    }

/**                          UnaryOperators                          **/

    TEST(UnaryOperators, UnaryPlus) {
        BigInt testVal = BigInt(-2);
        testVal = +testVal;
        EXPECT_EQ(std::string(testVal), "-2");
        testVal = BigInt("0");
        testVal = +testVal;
        EXPECT_EQ(std::string(testVal), "0");
    }

    TEST(UnaryOperators, UnaryMinus) {
        BigInt testVal = BigInt("99999999999999999999999999999999999999999999");
        testVal = -testVal;
        EXPECT_EQ(std::string(testVal), "-99999999999999999999999999999999999999999999");
        testVal = BigInt("-99999999999999999999999999999999999999999999");
        testVal = -testVal;
        EXPECT_EQ(std::string(testVal), "99999999999999999999999999999999999999999999");
    }

    TEST(UnaryOperators, Increment) {
        BigInt testVal = BigInt(0);
        BigInt testVal1 = BigInt("99999999999999999999999999999999999999999999999");
        BigInt testVal2 = BigInt("-99999999999999999999999999999999999999999999999");
        testVal++;
        testVal1++;
        testVal2++;
        EXPECT_EQ(std::string(testVal), "1");
        EXPECT_EQ(std::string(testVal1), "100000000000000000000000000000000000000000000000");
        EXPECT_EQ(std::string(testVal2), "-99999999999999999999999999999999999999999999998");
    }

    TEST(UnaryOperators, Decrement) {
        BigInt testVal = BigInt("10000000000000000000000000000000000000000000000");
        BigInt testVal1 = BigInt("99999999999999999999999999999999999999999999999");
        BigInt testVal2 = BigInt("-99999999999999999999999999999999999999999999999");
        testVal--;
        testVal1--;
        testVal2--;
        EXPECT_EQ(std::string(testVal), "9999999999999999999999999999999999999999999999");
        EXPECT_EQ(std::string(testVal1), "99999999999999999999999999999999999999999999998");
        EXPECT_EQ(std::string(testVal2), "-100000000000000000000000000000000000000000000000");
    }


/**                          ArithmeticOperators                          **/

    TEST(ArithmeticOperators, Addition) {
        // 1
        BigInt testVal = BigInt(10);
        BigInt testVal1 = BigInt(-19);
        BigInt resVal = testVal + testVal1;
        EXPECT_EQ(std::string(resVal), "-9");
        // 2
        testVal = BigInt("99999999999999");
        testVal1 = BigInt("2");
        resVal = testVal + testVal1;
        EXPECT_EQ(resVal.getNumber(), "100000000000001");
        // 3
        testVal = BigInt("1233212133211233211321321321");
        testVal1 = BigInt("132135513212421321512132321321554");
        resVal = testVal + testVal1;
        EXPECT_EQ(std::string(resVal), "132136746424554532745343642642875");
        // 4
        testVal = BigInt("-505050505050505050505050505050");
        testVal1 = BigInt("99999999999999999999999999999999999999999999");
        testVal += testVal1;
        EXPECT_EQ(testVal.getNumber(), "99999999999999494949494949494949494949494949");
    }


    TEST(ArithmeticOperators, Substraction) {
        // 1
        BigInt testVal = BigInt(10);
        BigInt testVal1 = BigInt(19);
        BigInt resVal = testVal - testVal1;
        EXPECT_EQ(std::string(resVal), "-9");
        // 2
        testVal = BigInt("505050505050505050505050505050");
        testVal1 = BigInt("121212131323232132132132321323123213122313213231213213132132132");
        resVal = testVal - testVal1;
        EXPECT_EQ(std::string(resVal), "-121212131323232132132132321323122708071808162726162708081627082");
        // 3
        testVal = BigInt("-505050505050505050505050505050");
        testVal1 = BigInt("-121212131323232132132132321323123213122313213231213213132132132");
        testVal -= testVal1;
        EXPECT_EQ(std::string(testVal), "121212131323232132132132321323122708071808162726162708081627082");
    }

    TEST(ArithmeticOperators, Multiplication) {
        // 1
        BigInt testVal = BigInt(10);
        BigInt testVal1 = BigInt(-19);
        BigInt resVal = testVal * testVal1;
        EXPECT_EQ(std::string(resVal), "-190");
        // 2
        testVal = BigInt("505050505050505050505050505050");
        testVal1 = BigInt("121212131323232132132132321323123213122313213231213213132132132");
        resVal = testVal * testVal1;
        EXPECT_EQ(std::string(resVal),
                  "61218248143046531379864808748990909591409081363172263035762125649938225649883225649933266600");
        // 3
        testVal = BigInt("-505050505050505050505050505050");
        testVal1 = BigInt("-121212131323232132132132321323123213122313213231213213132132132");
        resVal = testVal * testVal1;
        EXPECT_EQ(std::string(resVal),
                  "61218248143046531379864808748990909591409081363172263035762125649938225649883225649933266600");
    }

    TEST(ArithmeticOperators, Division) {
        // 1
        BigInt testVal = BigInt(10);
        BigInt testVal1 = BigInt(-19);
        BigInt resVal = testVal / testVal1;
        EXPECT_EQ(std::string(resVal), "0");
        // 2
        testVal = BigInt("121212131323232132132132321323123213122313213231213213132132132");
        testVal1 = BigInt("505050505050505050505050505050");
        resVal = testVal / testVal1;
        EXPECT_EQ(std::string(resVal), "240000020019999621621621996220023");
        // 3
        testVal = BigInt("99999999999999999999999999999999999999999999999999999999999999");
        testVal1 = BigInt("-33333333333333333");
        resVal = testVal / testVal1;
        EXPECT_EQ(std::string(resVal), "-3000000000000000030000000000000000300000000000");
    }

    TEST(ArithmeticOperators, Modulo) {
        BigInt testVal = BigInt(10);
        BigInt testVal1 = BigInt(-19);
        BigInt resVal = testVal % testVal1;
        EXPECT_EQ(std::string(resVal), "10");
        testVal = BigInt("99999999999999999999999999999999999999999999999999999999999999");
        testVal1 = BigInt("-33333333333333333");
        resVal = testVal % testVal1;
        EXPECT_EQ(std::string(resVal), "99999999999");
        testVal = BigInt("121212131323232132132132321323123213122313213231213213132132132");
        testVal1 = BigInt("505050505050505050505050505050");
        resVal = testVal % testVal1;
        EXPECT_EQ(std::string(resVal), "485859697051423951406059515982");
    }


    TEST(BoolOperators, Equality) {
        BigInt testVal = BigInt(10);
        BigInt testVal1 = BigInt(-19);
        bool resVal = testVal == testVal1;
        EXPECT_FALSE(resVal);
        testVal = BigInt("3211656548948949651233565449894864135154984915146848");
        testVal1 = BigInt("3211656548948949651233565449894864135154984915146848");
        resVal = testVal == testVal1;
        EXPECT_TRUE(resVal);
        testVal = BigInt("3211656548948949651233565449894864135154984915146848");
        testVal1 = BigInt("-3211656548948949651233565449894864135154984915146848");
        resVal = testVal == testVal1;
        EXPECT_FALSE(resVal);
    }

    TEST(BoolOperators, NotEquality) {
        BigInt testVal = BigInt(10);
        BigInt testVal1 = BigInt(-19);
        bool resVal = testVal != testVal1;
        EXPECT_TRUE(resVal);
        testVal = BigInt("3211656548948949651233565449894864135154984915146848");
        testVal1 = BigInt("3211656548948949651233565449894864135154984915146848");
        resVal = (testVal != testVal1);
        EXPECT_FALSE(resVal);
        testVal = BigInt("3211656548948949651233565449894864135154984915146848");
        testVal1 = BigInt("-3211656548948949651233565449894864135154984915146848");
        resVal = testVal != testVal1;
        EXPECT_TRUE(resVal);
    }

    TEST(BoolOperators, LessThan) {
        BigInt testVal = BigInt(10);
        BigInt testVal1 = BigInt(-19);
        bool resVal = testVal < testVal1;
        EXPECT_FALSE(resVal);
        testVal = BigInt("3211656548948949651233565449894864135154984915146848");
        testVal1 = BigInt("3211656548948949651233565449894864135154984915146848");
        resVal = testVal < testVal1;
        EXPECT_FALSE(resVal);
        testVal = BigInt("3211656548948949651233565449894864135154984915146848");
        testVal1 = BigInt("-3211656548948949651233565449894864135154984915146848");
        resVal = testVal < testVal1;
        EXPECT_FALSE(resVal);
    }


    TEST(BoolOperators, EqualityOrLessThan) {
        BigInt testVal = BigInt(10);
        BigInt testVal1 = BigInt(-19);
        bool resVal = testVal <= testVal1;
        EXPECT_FALSE(resVal);
        testVal = BigInt("3211656548948949651233565449894864135154984915146848");
        testVal1 = BigInt("3211656548948949651233565449894864135154984915146848");
        resVal = testVal <= testVal1;
        EXPECT_TRUE(resVal);
        testVal = BigInt("3211656548948949651233565449894864135154984915146848");
        testVal1 = BigInt("-3211656548948949651233565449894864135154984915146848");
        resVal = testVal <= testVal1;
        EXPECT_FALSE(resVal);
    }

    TEST(BoolOperators, GreaterThan) {
        BigInt testVal = BigInt(10);
        BigInt testVal1 = BigInt(-19);
        bool resVal = testVal > testVal1;
        EXPECT_TRUE(resVal);
        testVal = BigInt("3211656548948949651233565449894864135154984915146848");
        testVal1 = BigInt("3211656548948949651233565449894864135154984915146848");
        resVal = testVal > testVal1;
        EXPECT_FALSE(resVal);
        testVal = BigInt("3211656548948949651233565449894864135154984915146848");
        testVal1 = BigInt("-3211656548948949651233565449894864135154984915146848");
        resVal = testVal > testVal1;
        EXPECT_TRUE(resVal);
    }

    TEST(BoolOperators, EqualityOrGreaterThan) {
        BigInt testVal = BigInt(10);
        BigInt testVal1 = BigInt(-19);
        bool resVal = testVal >= testVal1;
        EXPECT_TRUE(resVal);
        testVal = BigInt("3211656548948949651233565449894864135154984915146848");
        testVal1 = BigInt("3211656548948949651233565449894864135154984915146848");
        resVal = testVal >= testVal1;
        EXPECT_TRUE(resVal);
        testVal = BigInt("3211656548948949651233565449894864135154984915146848");
        testVal1 = BigInt("-3211656548948949651233565449894864135154984915146848");
        resVal = testVal >= testVal1;
        EXPECT_TRUE(resVal);
    }

    TEST(BitwiseOperators, AND) {
        BigInt testVal = BigInt(5);
        BigInt testVal1 = BigInt(-7);
        BigInt resVal = testVal & testVal1;
        EXPECT_EQ(std::string(resVal), "1");
        testVal = BigInt("99999999999999999999999999999999999999999999999999999999999999");
        testVal1 = BigInt("33333333333333333");
        resVal = testVal & testVal1;
        EXPECT_EQ(std::string(resVal), "33333333333333333");
        testVal = BigInt("121212131323232132132132321323123213122313213231213213132132132");
        testVal1 = BigInt("505050505050505050505050505050");
        resVal = testVal & testVal1;
        EXPECT_EQ(std::string(resVal), "477500633653197768726733262592");
    }

    TEST(BitwiseOperators, OR) {
        BigInt testVal = BigInt(5);
        BigInt testVal1 = BigInt(7);
        BigInt resVal = testVal | testVal1;
        EXPECT_EQ(std::string(resVal), "7");
        testVal = BigInt("99999999999999999999999999999999999999999999999999999999999999");
        testVal1 = BigInt("33333333333333333");
        resVal = testVal | testVal1;
        EXPECT_EQ(std::string(resVal), "99999999999999999999999999999999999999999999999999999999999999");
        BigInt tv = BigInt("48616513546484489151353568446");
        BigInt tv1 = BigInt("5465465445645456645651331");
        BigInt rv = tv | tv1;
        EXPECT_EQ(std::string(rv), "48616533822924140300933660607");
    }

    TEST(BitwiseOperators, XOR) {
        BigInt testVal = BigInt(5);
        BigInt testVal1 = BigInt(7);
        BigInt resVal = testVal ^ testVal1;
        EXPECT_EQ(std::string(resVal), "2");
        testVal = BigInt("99999999999999999999999999999999999999999999999999999999999999");
        testVal1 = BigInt("33333333333333333");
        resVal = testVal ^ testVal1;
        EXPECT_EQ(std::string(resVal), "99999999999999999999999999999999999999999999966666666666666666");
        testVal = BigInt("121212131323232132132132321323123213122313213231213213132132132");
        testVal1 = BigInt("505050505050505050505050505050");
        resVal = testVal ^ testVal1;
        EXPECT_EQ(std::string(resVal), "121212131323232132132132321323122763171550957340726264716111998");
    }

    TEST(BitwiseOperators, NOT) {
        BigInt testVal = BigInt(5);
        BigInt resVal = ~testVal;
        EXPECT_EQ(std::string(resVal), "-6");
        testVal = BigInt("16513233156654645465");
        resVal = ~testVal;
        EXPECT_EQ(std::string(resVal), "-16513233156654645466");

    }

    TEST(OtherOperations, decToBin) {
        std::string a = "102";
        std::string b = "-102";
        std::string res = fromDecToBin(a);
        std::string res1 = fromDecToBin(b);
        EXPECT_EQ(res, "1100110");
        EXPECT_EQ(res1, "0011010");
    }

    TEST(OtherOperations, binToDec) {
        std::string a = "101010100101000110";
        std::string b = "1000000010110110010101100101100101010101";
        std::string res = fromBinToDec(a);
        std::string res1 = fromBinToDec(b);
        EXPECT_EQ(res, "174406");
        EXPECT_EQ(res1, "552814926165");
    }

    TEST(OtherOperations, binInverse) {
        std::string a = "101010100101000110";
        std::string b = "1000000010110110010101100101100101010101";
        binInverse(a);
        EXPECT_EQ(a, "010101011010111001");
        binInverse(b);
        EXPECT_EQ(b, "0111111101001001101010011010011010101010");
    }

    TEST(OtherOperations, removeLeadingZeroes) {
        std::string a = "000102";
        removeLeadingZeroes(a);
        EXPECT_EQ(a, "102");
        std::string b = "0000000101010011011001";
        removeLeadingZeroes(b);
        EXPECT_EQ(b, "101010011011001");
    }

    TEST(OtherOperations, maxBinLen) {
        BigInt *testVal = new BigInt("1556611651165");
        BigInt testVal1 = BigInt("56498893531261");
        const BigInt *resVal = BigInt::maxBinLen(testVal, testVal1);
        EXPECT_EQ(std::string(*resVal), "56498893531261");
    }


    TEST(OtherOperations, minBinLen) {
        BigInt *testVal = new BigInt("1556611651165");
        BigInt testVal1 = BigInt("56498893531261");
        const BigInt *resVal = BigInt::minBinLen(testVal, testVal1);
        EXPECT_EQ(std::string(*resVal), "1556611651165");
    }


    TEST(OtherOperations, pow) {
        BigInt testVal = BigInt("100");
        BigInt testVal1 = BigInt("3");
        BigInt resVal = pow(testVal, testVal1);
        EXPECT_EQ(std::string(resVal), "1000000");
        testVal = BigInt("9999999999");
        testVal1 = BigInt("5");
        resVal = pow(testVal, testVal1);
        EXPECT_EQ(std::string(resVal), "99999999950000000009999999999000000000049999999999");
    }


}
