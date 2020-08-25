#include "gtest/gtest.h"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "decorator.hpp"
#include "Trunc.hpp"
#include "abs.hpp"
#include "floor.hpp"
#include "ceil.hpp"
#include "Paren.hpp"
#include "visitor.hpp"
#include "iterator.hpp"

int main(int argc, char **argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

TEST(NullIteratorTest, OpIteratorTest) {
	Op* val = new Op(8);

	Iterator* test = val->create_iterator();

	EXPECT_EQ(test->current(), nullptr);
	EXPECT_EQ(test->is_done(), true);
}

TEST(BinaryIteratorTest, MultIteratorTest) {
	Op* val = new Op(2);
	Op* val2 = new Op(4);
	Mult* mult = new Mult(val, val2);

	Iterator* test = mult->create_iterator();

	EXPECT_EQ(test->current(), val);

	test->next();
  	EXPECT_EQ(test->current(), val2);

	EXPECT_EQ(test->is_done(), false);

	test->first();
	EXPECT_EQ(test->current(), val);

	test->next();
	test->next();
	EXPECT_EQ(test->is_done(), true);	
}	

TEST(UnaryIteratorTest, ParenIteratorTest) {
	Op* val = new Op(1);
	Op* val2 = new Op(2);
	Add* add = new Add(val, val2);
	Decorator* paren = new Paren(add);

	Iterator* test = paren->create_iterator();
	EXPECT_EQ(test->current(), add);

	test->next();
	EXPECT_EQ(test->current(), nullptr);
	
	test->first();
	EXPECT_EQ(test->current(), add);

	EXPECT_EQ(test->is_done(), false);
	
	test->next();
	EXPECT_EQ(test->is_done(), true);
}

TEST(UnaryIteratorTest, CeilIteratorTest) {
	Op* val = new Op(1.2);
	Op* val2 = new Op(2.3);
	Add* add = new Add(val, val2);
	Decorator* ceil = new Ceil(add);

	Iterator* test = ceil->create_iterator();
	EXPECT_EQ(test->current(), add);

	test->next();
	EXPECT_EQ(test->current(), nullptr);
	
	test->first();
	EXPECT_EQ(test->current(), add);

	EXPECT_EQ(test->is_done(), false);
	
	test->next();
	EXPECT_EQ(test->is_done(), true);
}

TEST(PreorderIteratorTest, PreorderTraversalTest) {
	Op* val = new Op(8);
	Op* val2 = new Op(2);
  	Op* val3 = new Op(1);

	Div* div = new Div(val, val2);
	Pow* pow = new Pow(div, val3);
	Sub* sub = new Sub(pow, val2);
	Abs* abs = new Abs(sub); //dummy root node
	Iterator* test = new PreorderIterator(abs); 
	
	test->first();
	EXPECT_EQ(test->current(), sub);
  
	EXPECT_EQ(test->is_done(), false);

	test->next();
	EXPECT_EQ(test->current(), pow);

	test->next();
	test->next();
	test->next();

	EXPECT_EQ(test->is_done(), false);
	
  	test->next();
	test->next();
	test->next();

	EXPECT_EQ(test->is_done(), true);	
}

TEST(CountVisitorTest, CompositeAcceptTest) {
  	Op* val = new Op(4);
  	Op* val2 = new Op(2); 
  	Op* val3 = new Op(1);
  	Op* val4 = new Op(5);
  	Op* val5 = new Op(10); 

  	Add* add = new Add(val4, val5);
  	Sub* sub = new Sub(add, val3);
  	Mult* mult = new Mult(sub, val5);
  	Div* div = new Div(mult, val2);
  	Pow* pow = new Pow(div, val);
  	Rand* rand = new Rand();
  	Add* add1 = new Add(pow, rand);

  	Abs* abs = new Abs(add1);
	
  	CountVisitor* count_test = new CountVisitor();
	Iterator* test = new PreorderIterator(abs);
	
  	test->first();
	
  	while (!test->is_done()) {
		test->current()->accept(count_test);
		test->next();
	}

	EXPECT_EQ(count_test->add_count(), 2);
	EXPECT_EQ(count_test->sub_count(), 1);
	EXPECT_EQ(count_test->mult_count(), 1);
	EXPECT_EQ(count_test->div_count(), 1);
	EXPECT_EQ(count_test->pow_count(), 1);
	EXPECT_EQ(count_test->rand_count(), 1);
	EXPECT_EQ(count_test->op_count(), 6); 
}

TEST(CountVisitorTest, OneNodeTest){
  	Op* val = new Op(10); 
  	Abs* abs = new Abs(val); 	

	CountVisitor* count_test = new CountVisitor();
  	Iterator* test = new PreorderIterator(abs);

	test->first();
	
  	while (!test->is_done()) {
		test->current()->accept(count_test);
		test->next();
	}	

	EXPECT_EQ(count_test->op_count(), 1);
	EXPECT_EQ(count_test->sub_count(), 0);
	EXPECT_EQ(count_test->mult_count(), 0);
	EXPECT_EQ(count_test->div_count(), 0);
	EXPECT_EQ(count_test->pow_count(), 0);
	EXPECT_EQ(count_test->rand_count(), 0);
	EXPECT_EQ(count_test->add_count(), 0);
	EXPECT_EQ(count_test->ceil_count(), 0);
	EXPECT_EQ(count_test->floor_count(), 0);
	EXPECT_EQ(count_test->abs_count(), 0);
	EXPECT_EQ(count_test->paren_count(), 0);
	EXPECT_EQ(count_test->trunc_count(), 0);
}


TEST(CountVisitorTest, VisitTest){
  	CountVisitor* count_test = new CountVisitor();
  	count_test->visit_add();
  	count_test->visit_add();
  	count_test->visit_add();
  	count_test->visit_sub();
  	count_test->visit_mult();
  	count_test->visit_mult();
  	count_test->visit_div();
  	count_test->visit_pow();
  	count_test->visit_rand();
  	count_test->visit_op();
  	count_test->visit_ceil();
  	count_test->visit_floor();
  	count_test->visit_floor();
  	count_test->visit_abs();
  	count_test->visit_trunc();
  	count_test->visit_paren();
  	count_test->visit_trunc();
 	EXPECT_EQ(count_test->add_count(), 3);
	EXPECT_EQ(count_test->sub_count(), 1);
	EXPECT_EQ(count_test->mult_count(), 2);
	EXPECT_EQ(count_test->div_count(), 1);
	EXPECT_EQ(count_test->pow_count(), 1);
	EXPECT_EQ(count_test->rand_count(), 1);
	EXPECT_EQ(count_test->op_count(), 1);
  	EXPECT_EQ(count_test->ceil_count(), 1);
	EXPECT_EQ(count_test->floor_count(), 2);
	EXPECT_EQ(count_test->abs_count(), 1);
	EXPECT_EQ(count_test->paren_count(), 1);
	EXPECT_EQ(count_test->trunc_count(), 2);
}

TEST(VisitorCountTest3, DecoratorAcceptTest) {
	Op* val = new Op(-1.5);
	Op* val2 = new Op(5);
	Mult* mult = new Mult(val, val2);
	Abs* abs = new Abs(mult);
	Floor* floor = new Floor(abs);
  	Op* val3 = new Op(2.2);
  	Add* add = new Add(floor, val3);
  	Ceil* ceil = new Ceil(add);
	Trunc* trunc = new Trunc(ceil);
	Paren* paren = new Paren(trunc);
	Paren* paren1 = new Paren(paren);

	CountVisitor* count_test = new CountVisitor();
	Iterator* test = new PreorderIterator(paren1);

  	test->first();
  	while (!test->is_done()) {
		test->current()->accept(count_test);
		test->next();
	}

  	EXPECT_EQ(count_test->add_count(), 1);
	EXPECT_EQ(count_test->op_count(), 3);
	EXPECT_EQ(count_test->mult_count(), 1);
 	EXPECT_EQ(count_test->ceil_count(), 1);
	EXPECT_EQ(count_test->floor_count(), 1);
	EXPECT_EQ(count_test->abs_count(), 1);
	EXPECT_EQ(count_test->paren_count(), 1);
	EXPECT_EQ(count_test->trunc_count(), 1);
}
