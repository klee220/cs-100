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
            count->visit_floor();
        }
};

#endif
