#ifndef ABS_HPP
#define ABS_HPP

#include "decorator.hpp"

class Abs: public Decorator {
    public:
        Abs(Base* base):Decorator(base) {};
        virtual double evaluate() {
        	return abs(base_->evaluate());}
        virtual std::string stringify() {};
	virtual Iterator* create_iterator(){ 
		return new UnaryIterator(this);
	}
	virtual Base* get_left(){
		return base_;
	}
	virtual Base* get_right(){
		return nullptr;
	}
        void accept(CountVisitor* count) {
                count->visit_abs();
        }
};

#endif
