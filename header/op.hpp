#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <iostream>
#include <string>
class Op : public Base {
    public:
           Op(double value);

        virtual int evaluateInt(){};
           virtual double evaluate();
           virtual std::string stringify();
           virtual std::string stringifyInt(){};
           virtual int precedence(){};
           virtual int associative(){};
           double get_number(){
               return val;
           }
    private:
          double val;
          int valInt;
};

#endif
