#ifndef RAND_TEST_H
#define RAND_TEST_H

#include "rand.hpp"
#include "gtest/gtest.h"

TEST(RandTest, RandEvaluate) {
    Rand* test = new Rand();
    EXPECT_EQ(test->evaluate(), test->evaluate());
}


TEST(RandTest, RandStringify) {
    Rand* test = new Rand();
    EXPECT_EQ(test->stringify(), test->stringify());
}

#endif

