#ifndef POW_H
#define POW_H

#include <cmath>
#include "base.hpp"
#include "op.hpp"

class Pow: public Base {
    public: 
	Pow(Base* x, Base* y) {
	    this->x = x;
	    this->y = y;
	}
	virtual double evaluate() { return pow(x->evaluate(), y->evaluate()); }
	virtual std::string stringify() { return x->stringify() + "**" + y->stringify(); }
    private:
	Base* x;
	Base* y;
};


#endif
