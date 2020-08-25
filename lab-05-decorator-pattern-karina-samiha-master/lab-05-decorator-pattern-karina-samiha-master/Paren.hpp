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
};

#endif
