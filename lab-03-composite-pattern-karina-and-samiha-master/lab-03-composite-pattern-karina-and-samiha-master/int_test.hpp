#ifndef __INT_TEST_HPP__
#define __INT_TEST_HPP__

#include "gtest/gtest.h"

#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"

TEST(IntegrationTest, EvalExpression) {
    Op* eleven = new Op(11.5);
    Op* thirteen =  new Op(13);
    Op* two = new Op(2);
    Op* three = new Op(3);
    Div* a = new Div(thirteen, two);
    Sub* b = new Sub(eleven, a);
    Pow* test = new Pow(b, three);
    EXPECT_EQ(test->evaluate(), 125);
}

TEST(IntegrationTest, EvalExpressionString) {
    Op* eleven = new Op(11.5);
    Op* thirteen =  new Op(13);
    Op* two = new Op(2);
    Op* three = new Op(3);
    Div* a = new Div(thirteen, two);
    Sub* b = new Sub(eleven, a);
    Pow* test = new Pow(b, three);
    EXPECT_EQ(test->stringify(), "11.500000-13.000000/2.000000**3.000000");
}

TEST(IntegrationTest, EvalExpression2) {
    Op* eleven = new Op(11.5);
    Op* thirteen =  new Op(13);
    Op* two = new Op(2);
    Op* three = new Op(3);
    Add* a = new Add(thirteen, two);
    Sub* b = new Sub(eleven, a);
    Mult* test = new Mult(b, three);
    EXPECT_EQ(test->evaluate(), -10.5);
}

TEST(IntegrationTest, EvalExpression2String) {
    Op* eleven = new Op(11.5);
    Op* thirteen =  new Op(13);
    Op* two = new Op(2);
    Op* three = new Op(3);
    Add* a = new Add(thirteen, two);
    Sub* b = new Sub(eleven, a);
    Mult* test = new Mult(b, three);
    EXPECT_EQ(test->stringify(), "11.500000-13.000000+2.000000*3.000000");
}


#endif //__OP_TEST_HPP__
