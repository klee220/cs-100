#ifndef CEIL_TEST_HPP
#define CEIL_TEST_HPP

#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "ceil.hpp"

TEST(CeilTest, CeilOp)
{
    SevenOpMock* seven = new SevenOpMock();
    Ceil* test = new Ceil(seven);
    EXPECT_EQ(test->evaluate(), 8);   
}

TEST(CeilTest, CeilNegOp)
{
    Op* neg = new Op(-2.5);
    Ceil* test = new Ceil(neg);
    EXPECT_EQ(test->evaluate(), -2);   
}

TEST(CeilTest, CeilAdd)
{
    OneOpMock* one = new OneOpMock();
    SevenOpMock* seven = new SevenOpMock();
    Add* add = new Add(one, seven);
    Ceil* test = new Ceil(add);
    EXPECT_EQ(test->evaluate(), 9); 
}

TEST(CeilTest, CeilExpressionR)
{
    OneOpMock* one = new OneOpMock();
    SevenOpMock* seven = new SevenOpMock();
    Add* add = new Add(one, seven);
    Ceil* ceil = new Ceil(add);
    Mult* test = new Mult(one, ceil);
    ASSERT_DOUBLE_EQ(test->evaluate(), 10.8);
    EXPECT_DOUBLE_EQ(test->evaluate(), 10.8);
}

TEST(CeilTest, CeilExpressionL)
{
    OneOpMock* one = new OneOpMock();
    SevenOpMock* seven = new SevenOpMock();
    Add* add = new Add(one, seven);
    Ceil* ceil = new Ceil(add);
    Mult* test = new Mult(ceil, one);
    ASSERT_DOUBLE_EQ(test->evaluate(), 10.8);
    EXPECT_DOUBLE_EQ(test->evaluate(), 10.8);
}

TEST(CeilTest, CeilNested)
{
    OneOpMock* one = new OneOpMock();
    SevenOpMock* seven = new SevenOpMock();
    Add* add = new Add(one, seven);
    Ceil* ceil = new Ceil(add);
    Mult* mult = new Mult(ceil, one);
    Ceil* test = new Ceil(mult);
    EXPECT_EQ(test->evaluate(), 11);
}

#endif
