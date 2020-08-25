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
};

#endif
