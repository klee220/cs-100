#ifndef ABS_TEST_HPP
#define ABS_TEST_HPP

#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "abs.hpp"

TEST(AbsTest, AbsOp)
{
    SevenOpMock* seven = new SevenOpMock();
    Abs* test = new Abs(seven);
    EXPECT_EQ(test->evaluate(), 7.5);   
}

TEST(AbsTest, AbsNegOp)
{
    Op* neg = new Op(-2.5);
    Abs* test = new Abs(neg);
    EXPECT_EQ(test->evaluate(), 2.5);   
}

TEST(AbsTest, AbsAdd)
{
    OneOpMock* one = new OneOpMock();
    NegativeFiveOpMock* five = new NegativeFiveOpMock();
    Add* add = new Add(one, five);
    Abs* test = new Abs(add);
    EXPECT_EQ(test->evaluate(), 3.8); 
}

TEST(AbsTest, AbsExpressionR)
{
    OneOpMock* one = new OneOpMock();
    NegativeFiveOpMock* five = new NegativeFiveOpMock();
    Add* add = new Add(one, five);
    Abs* abs = new Abs(add);
    Mult* test = new Mult(one, abs);
    EXPECT_EQ(test->evaluate(), 4.56);
}

TEST(AbsTest, AbsExpressionL)
{
    OneOpMock* one = new OneOpMock();
    NegativeFiveOpMock* five = new NegativeFiveOpMock();
    Add* add = new Add(one, five);
    Abs* abs = new Abs(add);
    Mult* test = new Mult(abs, five);
    EXPECT_EQ(test->evaluate(), -19);
}

TEST(AbsTest, AbsNested)
{
    OneOpMock* one = new OneOpMock();
    NegativeFiveOpMock* five = new NegativeFiveOpMock();
    Add* add = new Add(one, five);
    Abs* ceil = new Abs(add);
    Mult* mult = new Mult(ceil, five);
    Abs* test = new Abs(mult);
    EXPECT_EQ(test->evaluate(), 19);
}

#endif
