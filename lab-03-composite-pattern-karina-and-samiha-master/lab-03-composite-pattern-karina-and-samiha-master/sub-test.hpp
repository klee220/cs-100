#ifndef SUB-TEST_HPP
#define SUB-TEST_HPP

#include "gtest/gtest.h"
#include "sub.hpp"

TEST(SubTest, SubEvaluate) {
    TwoOpMock* two = new TwoOpMock();
    ThreeOpMock* three = new ThreeOpMock();
    Sub* test = new Sub(three, two);
    EXPECT_EQ(test->evaluate(), 1);
}

TEST(SubTest, SubString) {
     TwoOpMock* two = new TwoOpMock();
     ThreeOpMock* three = new ThreeOpMock();
     Sub* test = new Sub(three, two);
     EXPECT_EQ(test->stringify(), "3-2");
}

TEST(SubTest, SubCommutEval) {
    TwoOpMock* two = new TwoOpMock();
    ThreeOpMock* three = new ThreeOpMock();
    Sub* test = new Sub(two, three);
    EXPECT_EQ(test->evaluate(), -1);
}

TEST(SubTest, SubCommutString) {
     TwoOpMock* two = new TwoOpMock();
     ThreeOpMock* three = new ThreeOpMock();
     Sub* test = new Sub(two, three);
     EXPECT_EQ(test->stringify(), "2-3");
}

TEST(SubTest, SubInv) {
    TwoOpMock* two = new TwoOpMock();
    Sub* test = new Sub(two, two);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(SubTest, SubInvString) {
     TwoOpMock* two = new TwoOpMock();
     Sub* test = new Sub(two, two);
     EXPECT_EQ(test->stringify(), "2-2");
}

TEST(SubTest, SubZero) {
    TwoOpMock* two = new TwoOpMock();
    ZeroOpMock* zero = new ZeroOpMock();
    Sub* test = new Sub(two, zero);
    EXPECT_EQ(test->evaluate(), 2);
}

TEST(SubTest, SubZeroString) {
     TwoOpMock* two = new TwoOpMock();
     ZeroOpMock* zero = new ZeroOpMock();
     Sub* test = new Sub(two, zero);
     EXPECT_EQ(test->stringify(), "2-0");
}

TEST(SubTest, SubNeg) {
    NegativeTwoOpMock* two = new NegativeTwoOpMock();
    NegativeFiveOpMock* five = new NegativeFiveOpMock();
    Sub* test = new Sub(two, five);
    EXPECT_EQ(test->evaluate(), 3);
}

TEST(SubTest, SubNegString) {
     NegativeTwoOpMock* two = new NegativeTwoOpMock();
     NegativeFiveOpMock* five = new NegativeFiveOpMock();
     Sub* test = new Sub(two, five);
     EXPECT_EQ(test->stringify(), "-2--5");
}

TEST(SubTest, SubIntAsDoub) {
    DoubTwoOpMock* two = new DoubTwoOpMock();
    NegativeFiveOpMock* five = new NegativeFiveOpMock();
    Sub* test = new Sub(two, five);
    EXPECT_EQ(test->evaluate(), 7);
}

TEST(SubTest, SubIntAsDoubString) {
     DoubTwoOpMock* two = new DoubTwoOpMock();
     NegativeFiveOpMock* five = new NegativeFiveOpMock();
     Sub* test = new Sub(two, five);
     EXPECT_EQ(test->stringify(), "2.0--5");
}

TEST(SubTest, SubDoubs) {
    SevenOpMock* seven = new SevenOpMock();
    OneOpMock* one = new OneOpMock();
    Sub* test = new Sub(seven, one);
    EXPECT_EQ(test->evaluate(), 6.3);
}

TEST(SubTest, SubDoubsString) {
     SevenOpMock* seven = new DoubTwoOpMock();
     OneOpMock* one = new OneOpMock();
     Sub* test = new Sub(seven, one);
     EXPECT_EQ(test->stringify(), "7.5-1.2");
}


