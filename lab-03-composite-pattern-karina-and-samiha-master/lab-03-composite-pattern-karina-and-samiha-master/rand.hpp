#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"

class Rand : public Base {
    public:
        Rand() : Base() {
	    srand (time(NULL));
	    num = rand() % 100;
	    str = std::to_string(num);

	}
        virtual double evaluate() { return num; }
        virtual std::string stringify() { return str; }
    private:
	double num;
	std::string str;
};

#endif //__RAND_HPP__
