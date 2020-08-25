#ifndef FLOOR_TEST_HPP
#define FLOOR_TEST_HPP

#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "floor.hpp"

TEST(FloorTest, FloorOp)
{
    SevenOpMock* seven = new SevenOpMock();
    Floor* test = new Floor(seven);
    EXPECT_EQ(test->evaluate(), 7);   
}

TEST(FloorTest, FloorNegOp)
{
    Op* neg = new Op(-2.5);
    Floor* test = new Floor(neg);
    EXPECT_EQ(test->evaluate(), -3);   
}

TEST(FloorTest, FloorAdd)
{
    OneOpMock* one = new OneOpMock();
    SevenOpMock* seven = new SevenOpMock();
    Add* add = new Add(one, seven);
    Floor* test = new Floor(add);
    EXPECT_EQ(test->evaluate(), 8); 
}

TEST(FloorTest, FloorExpressionR)
{
    OneOpMock* one = new OneOpMock();
    SevenOpMock* seven = new SevenOpMock();
    Add* add = new Add(one, seven);
    Floor* floor = new Floor(add);
    Mult* test = new Mult(one, floor);
    EXPECT_EQ(test->evaluate(), 9.6);
}

TEST(FloorTest, FloorExpressionL)
{
    OneOpMock* one = new OneOpMock();
    SevenOpMock* seven = new SevenOpMock();
    Add* add = new Add(one, seven);
    Floor* floor = new Floor(add);
    Mult* test = new Mult(floor, one);
    EXPECT_EQ(test->evaluate(), 9.6);
}

TEST(FloorTest, FloorNested)
{
    OneOpMock* one = new OneOpMock();
    SevenOpMock* seven = new SevenOpMock();
    Add* add = new Add(one, seven);
    Floor* floor = new Floor(add);
    Mult* mult = new Mult(floor, one);
    Floor* test = new Floor(mult);
    EXPECT_EQ(test->evaluate(), 9);
}

#endif
