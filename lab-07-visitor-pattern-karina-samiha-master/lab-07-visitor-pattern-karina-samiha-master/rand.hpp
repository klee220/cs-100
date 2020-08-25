#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"

class Rand : public Base {
    public:
        Rand() : Base() {
	    srand (time(NULL));
	    num = rand() % 100;
	    str = std::to_string(num);

	}
        virtual double evaluate() { return num; }
        virtual std::string stringify() { return str; }
        virtual Base* get_left() { 
            return nullptr; 
        }
        virtual Base* get_right() { 
            return nullptr; 
        }
        virtual Iterator* create_iterator() {
            return new NullIterator(this);
        }
        void accept(CountVisitor* count) {
            count->visit_rand();
        }
    private:
	double num;
	std::string str;
};

#endif //__RAND_HPP__
