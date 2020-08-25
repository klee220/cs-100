#ifndef POW_TEST_H
#define POW_TEST_H

#include "gtest/gtest.h"
#include "pow.hpp"
#include "mult.hpp"

TEST(PowTest, PowEvaluateNonZero){
    Op* two = new Op(2);
    Op* three = new Op(3);
    Pow* test = new Pow(two, three);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(PowTest, PowStringifyNonZero){
    Op* two = new Op(2);
    Op* three = new Op(3);
    Pow* test = new Pow(two, three);
    EXPECT_EQ(test->stringify(), "2.000000**3.000000");
}

TEST(PowTest, PowEvaluate5Pow0){
    Op* val = new Op(5);
    Op* val2 = new Op(0);
    Pow* test = new Pow(val, val2);
    EXPECT_EQ(test->evaluate(), 1);
}

TEST(PowTest, PowStringify5Pow0){
    Op* val = new Op(5);
    Op* val2 = new Op(0);
    Pow* test = new Pow(val, val2);
    EXPECT_EQ(test->stringify(), "5.000000**0.000000");
}

TEST(PowTest, PowEvaluate0Pow6){
    Op* val = new Op(0);
    Op* val2 = new Op(6);
    Pow* test = new Pow(val, val2);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(PowTest, PowStringify0Pow6){
    Op* val = new Op(0);
    Op* val2 = new Op(6);
    Pow* test = new Pow(val, val2);
    EXPECT_EQ(test->stringify(), "0.000000**6.000000");
}

TEST(PowTest, PowEvaluateNeg2Pow2){
    Op* val = new Op(-2);
    Op* val2 = new Op(2);
    Pow* test = new Pow(val, val2);
    EXPECT_EQ(test->evaluate(), 4);
}

TEST(PowTest, PowStringifyNeg2Pow2){
    Op* val = new Op(-2);
    Op* val2 = new Op(2);
    Pow* test = new Pow(val, val2);
    EXPECT_EQ(test->stringify(), "-2.000000**2.000000");
}

TEST(PowTest, PowEvaluateNeg2Pow3){
    Op* val = new Op(-2);
    Op* val2 = new Op(3);
    Pow* test = new Pow(val, val2);
    EXPECT_EQ(test->evaluate(), -8);
}

TEST(PowTest, PowStringifyNeg2Pow3){
    Op* val = new Op(-2);
    Op* val2 = new Op(3);
    Pow* test = new Pow(val, val2);
    EXPECT_EQ(test->stringify(), "-2.000000**3.000000");
}

TEST(PowTest, PowEvaluateWithMult) {
    Base* val = new Op(2);
    Base* val2 = new Op(3);
    Mult* mult = new Mult(val, val2);
    Pow* test = new Pow(val, mult);
    EXPECT_EQ(test->evaluate(), 64);
}

TEST(PowTest, PowStringifyWithMult) {
    Base* val = new Op(2);
    Base* val2 = new Op(3);
    Mult* mult = new Mult(val, val2);
    Pow* test = new Pow(val, mult);
    EXPECT_EQ(test->stringify(), "2.000000**2.000000*3.000000");
}

TEST(PowTest, PowEvaluateWithInvalid) {
    Base* val = new Op('a');
    Base* val2 = new Op(1);
    Pow* test = new Pow(val, val2);
    EXPECT_EQ(test->evaluate(), 97);
}

TEST(PowTest, PowStringifyWithInvalid) {
    Base* val = new Op(1);
    Base* val2 = new Op('a');
    Pow* test = new Pow(val, val2);
    EXPECT_EQ(test->stringify(), "1.000000**97.000000");
}
#endif
