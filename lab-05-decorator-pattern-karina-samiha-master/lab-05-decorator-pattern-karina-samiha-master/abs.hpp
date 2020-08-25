#ifndef ABS_HPP
#define ABS_HPP

#include "decorator.hpp"

class Abs: public Decorator {
    public:
        Abs(Base* base):Decorator(base) {};
        virtual double evaluate() {
            return abs(base_->evaluate());}
        virtual std::string stringify() {};
};

#endif
