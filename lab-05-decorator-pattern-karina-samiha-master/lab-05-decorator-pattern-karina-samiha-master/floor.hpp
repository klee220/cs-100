#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "floor.hpp"

class Floor: public Decorator{
    public:
        Floor(Base* base): Decorator(base) {};
        virtual double evaluate(){
            return floor(base_->evaluate());
        }
        virtual std::string stringify() {};
};

#endif
