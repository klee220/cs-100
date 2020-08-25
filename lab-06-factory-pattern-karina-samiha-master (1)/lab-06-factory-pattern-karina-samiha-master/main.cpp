#include "factory.hpp"
#include <iostream>
using namespace std;

int main (int argc, char** argv){
  
  Factory* factory = new Factory();

  Base* result = factory->parse(argv, argc);

  cout << "String: " << result->stringify() << endl;
  cout << "Value: " << result->evaluate() << endl;

  return 0;
}
