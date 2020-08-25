#ifndef TRUNC_TEST_HPP
#define TRUNC_TEST_HPP

#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "Trunc.hpp"


TEST(TruncTest, Truncate3Sub2) {
	Op* val = new Op(3);
  	Op* val2 = new Op(2);
  	Sub* sub = new Sub(val, val2);

  	Trunc* test = new Trunc(sub);

	EXPECT_EQ(test->stringify(), "1.000000");
}


TEST(TruncTest, TruncateRightSide) {
	Op* val = new Op(3);
  	Op* val2 = new Op(2);
 	Op* val3 = new Op(5);

	Mult* mult = new Mult(val2, val3);
	Trunc* trunc = new Trunc(mult);

	Add* test = new Add(val, trunc);

	EXPECT_EQ(test->stringify(), "3.000000+10.000000");
}

TEST(TruncTest, TruncateMultipleOps) {
	Op* val = new Op(6);
	Op* val2 = new Op(2);
	Div* div = new Div(val, val2);

	Op* val3 = new Op(3);
	Op* val4 = new Op(1);
	Pow* pow = new Pow(val3, val4);

	Mult* mult = new Mult (div, pow);

	Trunc* test = new Trunc(mult);

	EXPECT_EQ(test->stringify(), "9.000000");
}

#endif
