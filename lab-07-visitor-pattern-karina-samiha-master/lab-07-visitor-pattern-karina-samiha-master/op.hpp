#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    public:
        Op(double value) : Base() { 
		num = value;
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
            count->visit_op();
        }
    private:
	double num;
	std::string str;
};

class TwoOpMock: public Base {
    public:
        TwoOpMock() {};
        virtual double evaluate() {return 2;}
        virtual std::string stringify() {return "2";}
};

class ThreeOpMock: public Base {
    public:
        ThreeOpMock() {};
        virtual double evaluate() {return 3;}
        virtual std::string stringify() {return "3";}
};

class ZeroOpMock: public Base {
    public:
        ZeroOpMock() {};
        virtual double evaluate() {return 0;}
        virtual std::string stringify() {return "0";}
};

class NegativeTwoOpMock: public Base {
    public:
        NegativeTwoOpMock() {};
        virtual double evaluate() {return -2;}
        virtual std::string stringify() {return "-2";}
};


class NegativeFiveOpMock: public Base {
    public:
        NegativeFiveOpMock() {};
        virtual double evaluate() {return -5;}
        virtual std::string stringify() {return "-5";}
};


class DoubTwoOpMock: public Base {
    public:
        DoubTwoOpMock() {};
        virtual double evaluate() {return 2.0;}
        virtual std::string stringify() {return "2.0";}
};


class SevenOpMock: public Base {
    public:
        SevenOpMock() {};
        virtual double evaluate() {return 7.5;}
        virtual std::string stringify() {return "7.5";}
};


class OneOpMock: public Base {
    public:
        OneOpMock() {};
        virtual double evaluate() {return 1.2;}
        virtual std::string stringify() {return "1.2";}
};

class InvalidAOpMock: public Base {
    public:
        InvalidAOpMock() {};
        virtual double evaluate() {return 'a';}
        virtual std::string stringify() {return "a";}
};

class InvalidBOpMock: public Base {
    public:
        InvalidBOpMock() {};
        virtual double evaluate() {return 'b';}
        virtual std::string stringify() {return "b";}
};

#endif //__OP_HPP__
