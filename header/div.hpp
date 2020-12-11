#ifndef _DIV_HPP_
#define _DIV_HPP_

#include "base.hpp"

class Div : public Base {
    public:
        Div(Base* leftOp, Base* rightOp);

        virtual int evaluateInt(){};
        virtual double evaluate();
        virtual std::string stringify();
        virtual std::string stringifyInt(){ };
        virtual int precedence(){};
        virtual int associative(){};
        virtual double get_number(){};
    private:
        Base* leftOperand;
        Base* rightOperand;
};

#endif
