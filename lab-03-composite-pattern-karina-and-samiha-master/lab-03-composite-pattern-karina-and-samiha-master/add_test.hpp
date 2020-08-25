#ifndef ADD_TEST_H
#define ADD_TEST_H

#include "gtest/gtest.h"
#include "add.hpp"

TEST(AddTest, AddEvaluateNonZero){
    Op* two = new Op(2);
    Op* three = new Op(3);
    Add* test = new Add(two, three);
    EXPECT_EQ(test->evaluate(), 5);
}

TEST(AddTest, AddStringifyNonZero){
    Op* two = new Op(2);
    Op* three = new Op(3);
    Add* test = new Add(two, three);
    EXPECT_EQ(test->stringify(), "2.000000+3.000000");
}

TEST(AddTest, AddEvaluate5Add0){
    Op* val = new Op(5);
    Op* val2 = new Op(0);
    Add* test = new Add(val, val2);
    EXPECT_EQ(test->evaluate(), 5);
}

TEST(AddTest, AddStringify5Add0){
    Op* val = new Op(5);
    Op* val2 = new Op(0);
    Add* test = new Add(val, val2);
    EXPECT_EQ(test->stringify(), "5.000000+0.000000");
}

TEST(AddTest, AddEvaluateNeg3Add2){
    Op* val = new Op(-3);
    Op* val2 = new Op(2);
    Add* test = new Add(val, val2);
    EXPECT_EQ(test->evaluate(), -1);
}

TEST(AddTest, AddStringifyNeg3Add2){
    Op* val = new Op(-3);
    Op* val2 = new Op(2);
    Add* test = new Add(val, val2);
    EXPECT_EQ(test->stringify(), "-3.000000+2.000000");
}

TEST(AddTest, AddEvaluateWithInvalidValues) {
    Base* val = new Op('a');
    Base* val2 = new Op('b');
    Add* add = new Add(val, val2);
    EXPECT_EQ(add->evaluate(), 195);
}

TEST(AddTest, AddStringifyWithInvalidValues) {
    Base* val = new Op('a');
    Base* val2 = new Op('b');
    Add* add = new Add(val, val2);
    EXPECT_EQ(add->stringify(), "97.000000+98.000000");
}
	
#endif
