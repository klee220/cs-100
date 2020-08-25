#ifndef MULT_H
#define MULT_H

#include "op.hpp"
#include "base.hpp"

class Mult : public Base {
    public:
        Mult(Base* x, Base* y) : Base() { 
		this->x = x; 
		this->y = y;
	}
        virtual double evaluate() { return (x->evaluate() * y->evaluate()); }
        virtual std::string stringify() { return x->stringify()  + "*" + y->stringify(); }
    private:
        Base* x;
	Base* y;
    };

#endif
