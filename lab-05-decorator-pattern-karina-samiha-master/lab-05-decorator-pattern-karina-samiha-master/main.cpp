#include <iostream>
#include "op.hpp"
#include "ceil.hpp"


using namespace std;

int main(){
    SevenOpMock* s = new SevenOpMock();
    Ceil* ceil = new Ceil(s);
    std::cout << ceil->evaluate();
    return 0;
}
