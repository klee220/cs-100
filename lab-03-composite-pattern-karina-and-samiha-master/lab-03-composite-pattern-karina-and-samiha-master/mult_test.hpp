#ifndef MULT_TEST_H
#define MULT_TEST_H

#include "gtest/gtest.h"
#include "mult.hpp"
#include "pow.hpp"
#include "add.hpp"

TEST(MultTest, MultEvaluateNonZero){
    Base* five = new Op(5);
    Base* four = new Op(4);
    Mult* test = new Mult(five, four);
    EXPECT_EQ(test->evaluate(), 20);
}

TEST(MultTest, MultStringifyNonZero){
    Base* five = new Op(5);
    Base* four = new Op(4);
    Mult* test = new Mult(five, four);
    EXPECT_EQ(test->stringify(), "5.000000*4.000000");
}

TEST(MultTest, MultEvaluate5Mult0){
    Op* val = new Op(5);
    Op* val2 = new Op(0);
    Mult* test = new Mult(val, val2);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(MultTest, MultStringify5Mult0){
    Op* val = new Op(5);
    Op* val2 = new Op(0);
    Mult* test = new Mult(val, val2);
    EXPECT_EQ(test->stringify(), "5.000000*0.000000");
}

TEST(MultTest, MultEvaluateNeg2Mult2){
    Op* val = new Op(-2);
    Op* val2 = new Op(2);
    Mult* test = new Mult(val, val2);
    EXPECT_EQ(test->evaluate(), -4);
}

TEST(MultTest, MultStringifyNeg2Mult2){
    Op* val = new Op(-2);
    Op* val2 = new Op(2);
    Mult* test = new Mult(val, val2);
    EXPECT_EQ(test->stringify(), "-2.000000*2.000000");
}

TEST(MultTest, MultEvaluateWithInvalid) {
    Base* val = new Op(1);
    Base* val2 = new Op('a');
    Base* test = new Mult(val, val2);
    EXPECT_EQ(test->evaluate(), 97);
}

TEST(MultTest, MultStringifyWithInvalid) {
    Base* val = new Op(1);
    Base* val2 = new Op('a');
    Base* test = new Mult(val, val2);
    EXPECT_EQ(test->stringify(), "1.000000*97.000000");
}

TEST(MultTest, MultEvaluateWithAddandPow) {
    Base* val = new Op(4);
    Base* val2 = new Op(3);
    Base* val3 = new Op(2);
    Base* val4 = new Op(2);
    Pow* pow = new Pow(val3, val4);
    Add* add = new Add(pow, val);
    Mult* test = new Mult(add, val2);
    EXPECT_EQ(test->evaluate(), 24);
}

TEST(MultTest, MultStringifyWithAddandPow) {
    Base* val = new Op(4);
    Base* val2 = new Op(3);
    Base* val3 = new Op(2);
    Base* val4 = new Op(2);
    Pow* pow = new Pow(val3, val4);
    Add* add = new Add(pow, val);
    Mult* test = new Mult(add, val2);
    EXPECT_EQ(test->stringify(), "2.000000**2.000000+4.000000*3.000000");
}

#endif
