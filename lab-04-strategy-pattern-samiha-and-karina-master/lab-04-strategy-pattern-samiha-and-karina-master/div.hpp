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
    private:
        Base* x;
        Base* y;
};

#endif
