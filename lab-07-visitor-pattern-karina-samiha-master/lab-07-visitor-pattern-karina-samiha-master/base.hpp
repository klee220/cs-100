#ifndef __BASE_HPP__
#define __BASE_HPP__

#include "iterator.hpp"
#include <string>
#include "visitor.hpp"

class Iterator;

class Base {
    public:
        /* Constructors */
        Base() { };

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;
	virtual Iterator* create_iterator() = 0;
	virtual Base* get_left() = 0;
	virtual Base* get_right() = 0; 
	virtual void accept(CountVisitor*) = 0;  
};

#endif //__BASE_HPP__
