#ifndef SUB_H
#define SUB_H

#include "base.hpp"
#include "op.hpp"

class Sub: public Base {
    public:
        Sub(Base* a, Base* b) {
            x = a;
            y = b;
        }
        virtual double evaluate() {return x->evaluate() - y->evaluate();}
        virtual std::string stringify() {return x->stringify() + "-" + y->stringify();}
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
            count->visit_sub();
        }
    private:
        Base* x;
        Base* y;
};

#endif
