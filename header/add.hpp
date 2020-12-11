#ifndef _ADD_HPP_
#define _ADD_HPP_

#include "base.hpp"
#include <cmath>
class Add : public Base {
    public:
        Add(Base* leftOp, Base* rightOp);
        virtual double evaluate();
        virtual int evaluateInt(){};
        virtual std::string stringify();
        virtual std::string stringifyInt(){};
        virtual int precedence(){};
        virtual int associative(){};
        virtual double get_number(){};
    private:
        Base* leftOperand;
        Base* rightOperand;
};

#endif
