#ifndef DIV_H
#define DIV_H

#include "base.hpp"
#include "op.hpp"

class Div: public Base {
    public:
        Div(Base* a, Base* b): Base(){
            x = a;
            y = b;
        }
        virtual double evaluate() {return x->evaluate() / y->evaluate();}
        virtual std::string stringify() {return x->stringify() + "/" + y->stringify();}
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
            count->visit_div();
        }
    private:
        Base* x;
        Base* y;
};

#endif
