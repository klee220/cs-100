#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, OpStringifyNonzero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->stringify(), "8.000000");
}

TEST(OpTest, OpEvaluateZero) {
    Op* test = new Op(0);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, OpStringifyZero) {
    Op* test = new Op(0);
    EXPECT_EQ(test->stringify(), "0.000000");
}

TEST(OpTest, OpEvaluateNegative) {
    Op* test = new Op(-5);
    EXPECT_EQ(test->evaluate(), -5);
}

TEST(OpTest, OpStringifyNegative) {
    Op* test = new Op(-5);
    EXPECT_EQ(test->stringify(), "-5.000000");
}

TEST(OpTest, OpEvaluateInvalid) {
    Op* test = new Op('a');
    EXPECT_EQ(test->evaluate(), 97);
}

TEST(OpTest, OpStringifyInvalid) {
    Op* test = new Op('a');
    EXPECT_EQ(test->stringify(), "97.000000");
}

#endif //__OP_TEST_HPP__
