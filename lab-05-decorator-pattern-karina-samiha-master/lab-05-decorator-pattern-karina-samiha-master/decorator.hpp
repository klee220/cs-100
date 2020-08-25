#ifndef DECORATOR_HPP
#define DECORATOR_HPP

#include <iostream>
#include <math.h>
#include "base.hpp"

class Decorator : public Base {
	public:
		Decorator(Base* base) {
                    base_ = base;}	
		virtual double evaluate(){
			std::cout << "decorator evaluate"; 
			return base_->evaluate(); }
		virtual std::string stringify(){
			return base_->stringify();}
	protected:
		Base* base_;
};
#endif
