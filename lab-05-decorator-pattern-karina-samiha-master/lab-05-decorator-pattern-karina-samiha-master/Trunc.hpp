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

};
#endif
