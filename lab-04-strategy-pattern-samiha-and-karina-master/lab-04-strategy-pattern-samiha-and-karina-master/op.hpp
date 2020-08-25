#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    public:
        Op(double value) : Base() { 
		num = value;
		str = std::to_string(num);
	 }
        virtual double evaluate() { return num; }
        virtual std::string stringify() { return str; }
    private:
	double num;
	std::string str;
};

#endif //__OP_HPP__
