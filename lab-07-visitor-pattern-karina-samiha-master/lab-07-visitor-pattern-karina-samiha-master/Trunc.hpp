#ifndef TRUNC_HPP
#define TRUNC_HPP
#include "decorator.hpp"

class Trunc : public Decorator{
	public:
		Trunc(Base* num):Decorator(num) {};
		virtual double evaluate() {};	
		virtual std::string stringify(){
			return std::to_string(base_->evaluate());
		}

       	 	virtual Iterator* create_iterator() { 
            		return new UnaryIterator(this);
        	}
        	virtual Base* get_left() { 
            		return base_;
        	}
        	virtual Base* get_right() {
            		return nullptr; 
        	}
        	void accept(CountVisitor* count) {
            		count->visit_trunc();
        	}
};
#endif
