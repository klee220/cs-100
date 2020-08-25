#ifndef DIV_TEST_HPP
#define DIV_TEST_HPP

#include "gtest/gtest.h"
#include "div.hpp"
#include <iostream>

TEST(DivTest, DivEvaluate) {
    TwoOpMock* two = new TwoOpMock();
    ThreeOpMock* three = new ThreeOpMock();
    Div* test = new Div(three, two);
    EXPECT_EQ(test->evaluate(), 1.5);
}

TEST(DivTest, DivString) {
     TwoOpMock* two = new TwoOpMock();
     ThreeOpMock* three = new ThreeOpMock();
     Div* test = new Div(three, two);
     EXPECT_EQ(test->stringify(), "3/2");
}

TEST(DivTest, DivCommutEval) {
    TwoOpMock* two = new TwoOpMock();
    ThreeOpMock* three = new ThreeOpMock();
    Div* test = new Div(two, three);
    EXPECT_EQ(test->evaluate(), 2.0/3.0);
}

TEST(DivTest, DivCommutString) {
     TwoOpMock* two = new TwoOpMock();
     ThreeOpMock* three = new ThreeOpMock();
     Div* test = new Div(two, three);
     EXPECT_EQ(test->stringify(), "2/3");
}

TEST(DivTest, DivInv) {
    TwoOpMock* two = new TwoOpMock();
    Div* test = new Div(two, two);
    EXPECT_EQ(test->evaluate(), 1);
}

TEST(DivTest, DivInvString) {
     TwoOpMock* two = new TwoOpMock();
     Div* test = new Div(two, two);
     EXPECT_EQ(test->stringify(), "2/2");
}

TEST(DivTest, DivZero) {
    TwoOpMock* two = new TwoOpMock();
    ZeroOpMock* zero = new ZeroOpMock();
    Div* test = new Div(zero, two);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(DivTest, DivZeroString) {
     TwoOpMock* two = new TwoOpMock();
     ZeroOpMock* zero = new ZeroOpMock();
     Div* test = new Div(zero, two);
     EXPECT_EQ(test->stringify(), "0/2");
}

TEST(DivTest, DivOneNeg) {
    TwoOpMock* two = new TwoOpMock();
    NegativeFiveOpMock* five = new NegativeFiveOpMock();
    Div* test = new Div(two, five);
    EXPECT_EQ(test->evaluate(), -2.0/5.0);
}

TEST(DivTest, DivOneNegString) {
     TwoOpMock* two = new TwoOpMock();
     NegativeFiveOpMock* five = new NegativeFiveOpMock();
     Div* test = new Div(two, five);
     EXPECT_EQ(test->stringify(), "2/-5");
}

TEST(DivTest, DivTwoNeg) {
    NegativeTwoOpMock* two = new NegativeTwoOpMock();
    NegativeFiveOpMock* five = new NegativeFiveOpMock();
    Div* test = new Div(two, five);
    EXPECT_EQ(test->evaluate(), 2.0/5.0);
}

TEST(DivTest, DivTwoNegString) {
     NegativeTwoOpMock* two = new NegativeTwoOpMock();
     NegativeFiveOpMock* five = new NegativeFiveOpMock();
     Div* test = new Div(two, five);
     EXPECT_EQ(test->stringify(), "-2/-5");
}

TEST(DivTest, DivDoubs) {
    SevenOpMock* seven = new SevenOpMock();
    OneOpMock* one = new OneOpMock();
    Div* test = new Div(seven, one);
    EXPECT_EQ(test->evaluate(), 6.25);
}

TEST(DivTest, DivDoubString) {
     SevenOpMock* seven = new SevenOpMock();
     OneOpMock* one = new OneOpMock();
     Div* test = new Div(seven, one);
     EXPECT_EQ(test->stringify(), "7.5/1.2");
}

TEST(DivTest, InvalidEval) {
    InvalidAOpMock* a = new InvalidAOpMock();
    InvalidBOpMock* b = new InvalidBOpMock();
    Div* test = new Div(a, b);
    EXPECT_EQ(test->evaluate(), static_cast<double>('a')/static_cast<double>('b'));
}

TEST(DivTest, InvalidString) {
    InvalidAOpMock* a = new InvalidAOpMock();
    InvalidBOpMock* b = new InvalidBOpMock();
    Div* test = new Div(a, b);
    EXPECT_EQ(test->stringify(), "a/b");
}

#endif
