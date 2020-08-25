#ifndef CEIL_HPP
#define CEIL_HPP

#include <iostream>
#include "decorator.hpp"

class Ceil : public Decorator {
    public:
        Ceil(Base* base): Decorator(base) {};
        virtual double evaluate(){
            return ceil(base_->evaluate());
        }
        virtual std::string stringify() {};
        virtual Iterator* create_iterator() { 
       	    return new UnaryIterator(this);
        }
        virtual Base* get_left() { 
            return base_;
        }
        virtual Base* get_right() {
            return nullptr; 
        }
	void accept(CountVisitor* count){
	    count->visit_ceil();
	}
};

#endif
