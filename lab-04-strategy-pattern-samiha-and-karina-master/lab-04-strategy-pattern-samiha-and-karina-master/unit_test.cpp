#include "gtest/gtest.h"
#include <iostream>
#include "op.hpp"
#include "add.hpp"
#include "rand.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "bubble_sort.hpp"
#include "selection_sort.hpp"

#include "VectorContainer.hpp"
#include "ListContainer.hpp"

using namespace std;


TEST(VectorContainerTestSet, AddElementTest) {
	Op* seven = new Op(7);
	VectorContainer* test_container = new VectorContainer();

    	test_container->add_element(seven);

    	ASSERT_EQ(test_container->size(), 1);
    	EXPECT_EQ(test_container->at(0)->evaluate(), 7);
}


TEST(VectorContainerTestSet, SwapTest) {
    	Op* seven = new Op(7);
    	Op* three = new Op(3);
    	VectorContainer* test_container = new VectorContainer();

    	test_container->add_element(seven);
    	test_container->add_element(three);
    	test_container->swap(0,1);

    	ASSERT_EQ(test_container->size(), 2);
    	EXPECT_EQ(test_container->at(0)->evaluate(), 3);
    	EXPECT_EQ(test_container->at(1)->evaluate(), 7);
}

TEST(VectorContainerTestSet, PrintandSizeTest) {
	Op* one = new Op(1);
	Op* two = new Op(2);
	Op* three = new Op(3);
	Op* four = new Op(4);
    
	VectorContainer* test_container = new VectorContainer();
    
   	test_container->add_element(one);
	test_container->add_element(two);
	test_container->add_element(three);
	test_container->add_element(four);
	test_container->print();
   	EXPECT_EQ(test_container->size(), 4);
}

TEST(VectorSortTestSet, BubbleSortTest) {
    	Op* seven = new Op(7);
    	Op* four = new Op(4);
    	Mult* TreeA = new Mult(seven, four);

    	Op* three = new Op(3);
    	Op* two = new Op(2);
    	Add* TreeB = new Add(three, two);

    	Op* six = new Op(6);
    	Op* one = new Op(1);
    	Pow* TreeC = new Pow(six, one);

    	VectorContainer* container = new VectorContainer();
    	container->add_element(TreeA);
    	container->add_element(TreeB);
    	container->add_element(TreeC);
	
	container->set_sort_function(new BubbleSort());
	container->sort();


    	ASSERT_EQ(container->size(), 3);
    	EXPECT_EQ(container->at(0)->evaluate(), 5);
    	EXPECT_EQ(container->at(1)->evaluate(), 6);
    	EXPECT_EQ(container->at(2)->evaluate(), 28);
}

TEST(VectorSortTestSet, SelectionSortTest) {
    	Op* seven = new Op(7);
    	Op* four = new Op(4);
    	Mult* TreeA = new Mult(seven, four);

    	Op* three = new Op(3);
    	Op* two = new Op(2);
    	Add* TreeB = new Add(three, two);

    	Op* six = new Op(6);
    	Op* one = new Op(1);
    	Pow* TreeC = new Pow(six, one);

    	VectorContainer* container = new VectorContainer();
    	container->add_element(TreeA);
    	container->add_element(TreeB);
    	container->add_element(TreeC);
	
	container->set_sort_function(new SelectionSort());
	container->sort();


    	ASSERT_EQ(container->size(), 3);
    	EXPECT_EQ(container->at(0)->evaluate(), 5);
    	EXPECT_EQ(container->at(1)->evaluate(), 6);
    	EXPECT_EQ(container->at(2)->evaluate(), 28);
}


TEST(ListContainerTestSet, AddElementTest) {
	Op* seven = new Op(7);
	ListContainer* test_container = new ListContainer();

    	test_container->add_element(seven);

    	ASSERT_EQ(test_container->size(), 1);
    	EXPECT_EQ(test_container->at(0)->evaluate(), 7);
}


TEST(ListContainerTestSet, SwapTest) {
    	Op* seven = new Op(7);
    	Op* three = new Op(3);
    	ListContainer* test_container = new ListContainer();

    	test_container->add_element(seven);
    	test_container->add_element(three);
    	test_container->swap(0,1);

    	ASSERT_EQ(test_container->size(), 2);
    	EXPECT_EQ(test_container->at(0)->evaluate(), 3);
    	EXPECT_EQ(test_container->at(1)->evaluate(), 7);
}

TEST(ListContainerTestSet, PrintandSizeTest) {
	Op* one = new Op(1);
	Op* two = new Op(2);
	Op* three = new Op(3);
	Op* four = new Op(4);
    
	ListContainer* test_container = new ListContainer();
    
   	test_container->add_element(one);
	test_container->add_element(two);
	test_container->add_element(three);
	test_container->add_element(four);
	test_container->print();
   	EXPECT_EQ(test_container->size(), 4);
}

TEST(ListSortTestSet, BubbleSortTest) {
    	Op* seven = new Op(7);
    	Op* four = new Op(4);
    	Mult* TreeA = new Mult(seven, four);

    	Op* three = new Op(3);
    	Op* two = new Op(2);
    	Add* TreeB = new Add(three, two);

    	Op* six = new Op(6);
    	Op* one = new Op(1);
    	Pow* TreeC = new Pow(six, one);

    	ListContainer* container = new ListContainer();
    	container->add_element(TreeA);
    	container->add_element(TreeB);
    	container->add_element(TreeC);
	
	container->set_sort_function(new BubbleSort());
	container->sort();


    	ASSERT_EQ(container->size(), 3);
    	EXPECT_EQ(container->at(0)->evaluate(), 5);
    	EXPECT_EQ(container->at(1)->evaluate(), 6);
    	EXPECT_EQ(container->at(2)->evaluate(), 28);
}

TEST(ListSortTestSet, SelectionSortTest) {
    	Op* seven = new Op(7);
    	Op* four = new Op(4);
    	Mult* TreeA = new Mult(seven, four);

    	Op* three = new Op(3);
    	Op* two = new Op(2);
    	Add* TreeB = new Add(three, two);

    	Op* six = new Op(6);
    	Op* one = new Op(1);
    	Pow* TreeC = new Pow(six, one);

    	ListContainer* container = new ListContainer();
    	container->add_element(TreeA);
    	container->add_element(TreeB);
    	container->add_element(TreeC);
	
	container->set_sort_function(new SelectionSort());
	container->sort();


    	ASSERT_EQ(container->size(), 3);
    	EXPECT_EQ(container->at(0)->evaluate(), 5);
    	EXPECT_EQ(container->at(1)->evaluate(), 6);
    	EXPECT_EQ(container->at(2)->evaluate(), 28);
}

TEST(VectorSortTestSet, SelectionSortTest2) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);

    container->set_sort_function(new SelectionSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 28);
}

TEST(VectorSortTestSet, BubbleSortTest2) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);

    container->set_sort_function(new BubbleSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 28);
}

TEST(VectorContainerTestSet, AtTest) {
    Op* seven = new Op(7);
    Op* three = new Op(3);
    Op* one = new Op(1);

    VectorContainer* test_container = new VectorContainer();

    test_container->add_element(seven);
    test_container->add_element(three);
    test_container->add_element(one);

    ASSERT_EQ(test_container->size(), 3);
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
    EXPECT_EQ(test_container->at(1)->evaluate(), 3);
    EXPECT_EQ(test_container->at(2)->evaluate(), 1);

}

TEST(ListContainerTestSet, AtTest) {
    Op* seven = new Op(7);
    Op* three = new Op(3);
    Op* one = new Op(1);

    ListContainer* test_container = new ListContainer();

    test_container->add_element(seven);
    test_container->add_element(three);
    test_container->add_element(one);

    ASSERT_EQ(test_container->size(), 3);
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
    EXPECT_EQ(test_container->at(1)->evaluate(), 3);
    EXPECT_EQ(test_container->at(2)->evaluate(), 1);

}

TEST(ListSortTestSet, BubbleSortTest1) {
    Op* eight = new Op(8);
    Op* four = new Op(4);
    Div* TreeA = new Div(eight, four);

    Op* three = new Op(3);
    Pow* TreeB = new Pow(TreeA, three);

    ListContainer* container = new ListContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);

    container->set_sort_function(new BubbleSort());
    container->sort();

    ASSERT_EQ(container->size(), 2);
    EXPECT_EQ(container->at(0)->evaluate(), 2);
    EXPECT_EQ(container->at(1)->evaluate(), 8);
}

TEST(VectorSortTestSet, BubbleSortTest3) {
    Op* eight = new Op(8);
    Op* four = new Op(4);
    Div* TreeA = new Div(eight, four);

    Op* three = new Op(3);
    Pow* TreeB = new Pow(TreeA, three);

    VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);

    container->set_sort_function(new BubbleSort());
    container->sort();

    ASSERT_EQ(container->size(), 2);
    EXPECT_EQ(container->at(0)->evaluate(), 2);
    EXPECT_EQ(container->at(1)->evaluate(), 8);
}

TEST(ListContainerTest, SizeTest) {
	ListContainer* container = new ListContainer();
	Op* one = new Op(1);
	Op* two = new Op(2); 	
	container->add_element(one);
	container->add_element(two);
	 
	EXPECT_EQ(container->size(), 2);
}

TEST(VectorContainerTest, SizeTest) {
	VectorContainer* container = new VectorContainer();
	Op* one = new Op(1);
	Op* two = new Op(2); 	
	container->add_element(one);
	container->add_element(two);
	 
	EXPECT_EQ(container->size(), 2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

