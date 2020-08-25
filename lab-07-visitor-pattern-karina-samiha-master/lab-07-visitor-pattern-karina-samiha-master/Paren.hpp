#ifndef PAREN_HPP
#define PAREN_HPP

#include "decorator.hpp"

class Paren : public Decorator {
	public:
		Paren (Base* num) : Decorator(num) {};
		virtual double evaluate(){ }
		virtual std::string stringify(){
			std::string par = "(" + base_->stringify() + ")";
			return par;
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
            		count->visit_paren();
        	}
};

#endif
