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
        virtual Base* get_left() { 
            return x; 
        }
        virtual Base* get_right() { 
            return y; 
        }
        virtual Iterator* create_iterator() {
            return new BinaryIterator(this);
        }
        void accept(CountVisitor* count) {
            count->visit_pow();
        }
    private:
	Base* x;
	Base* y;
};


#endif
