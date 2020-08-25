#include "op.hpp"
#include "mult.hpp"
#include "rand.hpp"
#include "pow.hpp"
#include "add.hpp"
#include "bubble_sort.hpp"
#include "sort.hpp"
#include "VectorContainer.hpp"
#include <iostream>	
using namespace std;

int main() {
	cout << "Vector container:" << endl;
	VectorContainer* container = new VectorContainer();
	Op* four = new Op(4);
	Op* two = new Op(2);
	Op* three = new Op(3);

	Add* add = new Add(four, three);
	Mult* mult = new Mult(two, three);

	container->add_element(four);
	container->add_element(two);
	container->add_element(three);
	container->add_element(add);
	container->add_element(mult);
	cout << "Container contains ";
	container->print();
	cout << "Perform swap on index 0 and 1" << endl;
	container->swap(0,1);
	container->print();
	cout << "Container size is : " << container->size() << endl;
	
	cout << "Container before sort: " << endl;	
	container->print();
	
	container->set_sort_function(new BubbleSort());
	container->sort();
	
	cout << "After sorting: " << endl;
	container->print(); 

	cout << "At index 0: " << container->at(0)->evaluate() << endl;
	cout << "At index 1: " << container->at(1)->evaluate() << endl;
	cout << "At index 2: " << container->at(2)->evaluate() << endl;
	cout << "At index 3: " << container->at(3)->evaluate() << endl;
	cout << "At index 4: " << container->at(4)->evaluate() << endl;
	
	return 0;
}
