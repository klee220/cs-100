#include "gtest/gtest.h"
#include "op.hpp"
#include "base.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "factory.hpp"

#include <iostream>
using namespace std;

int main(int argc, char**argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(FactoryTest, TwoDigitOp) {
  Factory* factory = new Factory(); 
  char* test[] = {"./calculate","15", "+", "13"};

  Base* result = factory->parse(test, 4);
	
  EXPECT_EQ(result->evaluate(), 28);
  EXPECT_EQ(result->stringify(), "15.000000+13.000000");
}

TEST(FactoryTest, Add) {
  Factory* factory = new Factory(); 
  char* test[] = {"./calculate","5", "+", "3"};
 
  Base* result = factory->parse(test, 4);
	
  EXPECT_EQ(result->evaluate(), 8);
  EXPECT_EQ(result->stringify(), "5.000000+3.000000");
}

TEST(FactoryTest, Sub) {
  Factory* factory = new Factory(); 
  char* test[] = {"./calculate","5", "-", "3"};
 
  Base* result = factory->parse(test, 4);
	
  EXPECT_EQ(result->evaluate(), 2);
  EXPECT_EQ(result->stringify(), "5.000000-3.000000");
}

TEST(FactoryTest, Mult) {
  Factory* factory = new Factory(); 
  char* test[] = {"./calculate","5", "*", "3"};

  Base* result = factory->parse(test, 4);
	
  EXPECT_EQ(result->evaluate(), 15);
  EXPECT_EQ(result->stringify(), "5.000000*3.000000");
}

TEST(FactoryTest, Div) {
  Factory* factory = new Factory(); 
  char* test[] = {"./calculate","6", "/", "3"};

  Base* result = factory->parse(test, 4);
	
  EXPECT_EQ(result->evaluate(), 2);
  EXPECT_EQ(result->stringify(), "6.000000/3.000000");
}

TEST(FactoryTest, Pow) {
  Factory* factory = new Factory(); 
  char* test[] = {"./calculate","5", "**", "2"};
 

  Base* result = factory->parse(test, 4);
	
  EXPECT_EQ(result->evaluate(), 25);
  EXPECT_EQ(result->stringify(), "5.000000**2.000000");
}

TEST(FactoryTest, AddSubMult) {
  Factory* factory = new Factory(); 
  char* test[] = {"./calculate","5", "+", "3", "-", "1", "*", "2"};
 
  Base* result = factory->parse(test, 8);
	
  EXPECT_EQ(result->evaluate(), 14);
  EXPECT_EQ(result->stringify(), "5.000000+3.000000-1.000000*2.000000");
}

TEST(FactoryTest, Combo) {
  Factory* factory = new Factory(); 
  char* test[] = {"./calculate","5", "+", "3", "-", "1", "*", "2", "/", "7", "**", "2"};


  Base* result = factory->parse(test, 12);
	
  EXPECT_EQ(result->evaluate(), 4);
  EXPECT_EQ(result->stringify(), "5.000000+3.000000-1.000000*2.000000/7.000000**2.000000");
}

TEST(FactoryTest, Single) {
  Factory* factory = new Factory();
  char* test[2];
  test[0] = "./calculate"; test[1] = "3";
	
  EXPECT_EQ(factory->parse(test, 2)->evaluate(), 3);
}

TEST(FactoryTest, Invalid) {
  Factory* factory = new Factory();
  char* test[3];
  test[0] = "./calculate"; test[1] = "2"; test[2] = "2";
	
  EXPECT_EQ(factory->parse(test, 3), nullptr);
}
