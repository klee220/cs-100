#ifndef INT_TEST_HPP
#define INT_TEST_HPP

#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "Trunc.hpp"
#include "Paren.hpp"
#include "ceil.hpp"
#include "floor.hpp"
#include "abs.hpp"


TEST(IntTest, EvaluateTest)
{
    SevenOpMock* seven = new SevenOpMock();
    OneOpMock* one = new OneOpMock();
    NegativeTwoOpMock* two = new NegativeTwoOpMock();
    Ceil* ceil = new Ceil(seven);
    Mult* mult = new Mult(ceil, one);
    Floor* floor = new Floor(mult);
    Add* add = new Add(floor,two);
    Abs* test = new Abs(add);
    EXPECT_EQ(test->evaluate(), 7);
}

TEST(IntTest, StringifyTest)
{
    TwoOpMock* two = new TwoOpMock();
    ThreeOpMock* three = new ThreeOpMock();
    Add* add = new Add(two, three);
    Trunc* trunc =  new Trunc(add);
    Paren* test = new Paren(trunc);
    EXPECT_EQ(test->stringify(), "(5.000000)");
}

TEST(IntTest, CombTest)
{ 
    SevenOpMock* seven = new SevenOpMock();
    OneOpMock* one = new OneOpMock();
    NegativeTwoOpMock* ntwo = new NegativeTwoOpMock();
    TwoOpMock* two = new TwoOpMock();
    ThreeOpMock* three = new ThreeOpMock();
    Sub* sub = new Sub(ntwo, three);
    Abs* abs = new Abs(sub);
    Paren* paren = new Paren(abs);
    Add* add = new Add(seven, paren);
    Mult* mult = new Mult(one, two);
    Trunc* trunc = new Trunc(mult);
    Add* test = new Add(add, trunc);
    EXPECT_EQ(test->evaluate(), 30);
}

#endif
