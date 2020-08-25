#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include <vector>
#include <queue>
#include <iostream>

class Factory{
public:
    Factory() {};
    Base* parse(char** input, int length)
    {
       std::queue<Op*> operand;
       Op* x;
       std::queue<std::string> operatr;
       Base* y;
       bool subsop = false;
       bool subsopr = false;
       
       //checks the the first value in expression is operand
       if(isOperator(input[1]))
       {
           //std::cout << "Invalid expression" << std::endl;
           return 0;
       }

       //separate into 2 queues- operands(Op class) and operatr(string)
       for(int i= 1; i < length; i++)
       {
           // if not valid operator put in operand
           if(!isOperator(input[i]))
           {
               /*if(!validOp(input[i]))
               {
                   std::cout << "Invalid expression" << std::endl;
                   return 0;
               }*/
               //check that previous value wasnt an operand
               if(subsop == true)
               {
                   std::cout << "Invalid expression" << std::endl;
                   return 0;
               }
               //set subsop( subsequent opereand) as true and subsopr( operator) as false
               subsop = true;
               subsopr = false;  
               
               //push operand into operand queue
               x = new Op(std::stod(input[i]));
               operand.push(x);
               
           }
           
           //operators
           else
           {
               //check that previous value wasnt an operation
               if(subsopr == true)
               {
                   std::cout << "Invalid expression" << std::endl;
                   return 0;
               }
               //set subsopr to true and subsop to false
               subsopr = true;
               subsop = false;
               
               //pushes appropriate string
               operatr.push(input[i]);
           }
       }
       
       //checks that expressions have correct number of ops and operands
       if (operand.size() != operatr.size()+1)
       {
           std::cout << "Invalid expression" << std::endl;
           return 0;
       }
       
       //created first node
       y = operand.front();
       y->stringify();
       operand.pop();

       //while we have operands and operators build tree
       while(!operand.empty() && !operatr.empty())
       {
           
           //creates new node from old node and next operand based on operator
           y = createOperator(operatr.front(), y, operand.front());
           operand.pop();
           operatr.pop();
           
       }
       
       //return tree
       return y;
    }

private:
    // creates nodes from other nodes
    Base* createOperator(std::string op, Base* left, Base* right)
    {
        Base* x;
        if(op == "+")
        {
            x = new Add(left, right);
        }
        if(op == "-")
        {
            x = new Sub(left, right);   
        }
        if(op == "*")
        {
            x = new Mult(left, right);
        }
        if(op == "/")
        {
            x = new Div(left, right);
        }
        if(op == "**")
        {
            x = new Pow(left, right);
        }
        return x;
    }
    bool isOperator(std::string x)
    {
        if(x == "+")
        {
            return true;
        }
        else if(x == "-")
        {
            return true;
        }
        else if(x == "*")
        {
            return true;
        }
        else if(x == "/")
        {
            return true;
        }
        else if(x == "**")
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // checks operands are valid
    bool validOp(char* x)
    {
        int i = 0;
        char num;
        bool hasDec = false;
        while (num != '\0')
        {
            num = x[i];

            std::cout << "char " << num;
            if( num != '1' ||num != '2' ||num != '3' ||num != '4' || num != '5' ||num != '6' ||num != '7' ||num != '8' ||num != '9' ||num != '0' 
||num != '.' ||num != '-' ) 
            {
                std::cout<< " not a num or . - " << num;
                return false;
            }
            
            if( num == '-' && i != 0)
            {
                std::cout << " dash in mid";
                return false;
            }
            
            if(num == '.')
            {
                if(!hasDec)
                {
                    hasDec = true;
                }
                else
                {
                    std::cout << " more than one ."; 
                    return false;
                }
            }
           
            i++;
        }
        return true;
    }
};

#endif
