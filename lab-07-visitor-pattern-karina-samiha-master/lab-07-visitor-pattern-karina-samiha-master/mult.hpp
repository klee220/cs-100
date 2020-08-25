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
            count->visit_mult();
        }
    private:
        Base* x;
	Base* y;
    };

#endif
