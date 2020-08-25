#ifndef PAREN_TEST_HPP
#define PAREN_TEST_HPP

#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "Paren.hpp"

TEST(ParenTest, Paren3Sub2) {
	Op* val = new Op(3);
  	Op* val2 = new Op(2);
 	Sub* sub = new Sub(val, val2);

 	Paren* test = new Paren(sub);

	EXPECT_EQ(test->stringify(), "(3.000000-2.000000)");
}


TEST(ParenTest, ParenRightSide) {
	Op* val = new Op(3);
  	Op* val2 = new Op(2);
  	Op* val3 = new Op(5);

 	Mult* mult = new Mult(val2, val3);
  	Paren* paren = new Paren(mult);

 	Add* test = new Add(val, paren);

	EXPECT_EQ(test->stringify(), "3.000000+(2.000000*5.000000)");
}

TEST(ParenTest, ParenMultipleOps) {
	Op* val = new Op(6);
	Op* val2 = new Op(2);
  	Div* div = new Div(val, val2);
  	Paren* paren = new Paren(div);

  	Op* val3 = new Op(3);
  	Op* val4 = new Op(1);
  	Pow* pow = new Pow(val3, val4);
  	Paren* paren2 = new Paren(pow);

  	Mult* test = new Mult(paren, paren2);

	EXPECT_EQ(test->stringify(), "(6.000000/2.000000)*(3.000000**1.000000)");
}

#endif
