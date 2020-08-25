#ifndef ADD_H
#define ADD_H

#include "base.hpp"
#include "op.hpp"

class Add: public Base {
   public:
      Add(Base* x, Base* y) {
         this->x = x;
         this->y = y;
      }
      virtual double evaluate() { return x->evaluate() + y->evaluate(); }
      virtual std::string stringify() { return x->stringify() + "+" +  y->stringify(); }

   private:
      Base* x;
      Base* y;
};

#endif
