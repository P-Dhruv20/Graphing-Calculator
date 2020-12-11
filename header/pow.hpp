#ifndef _POW_HPP_
#define _POW_HPP_

#include "base.hpp"
#include <cmath>

class Pow : public Base{
    public:
        Pow(Base* baseOp,Base* powerOp);

        virtual int evaluateInt(){};
        virtual double evaluate();
        virtual std::string stringify();
        virtual std::string stringifyInt(){ };
        virtual int precedence(){};
        virtual int associative(){};
        virtual double get_number(){};
    private:
        Base* baseOperand;
        Base* powerOperand;
};

#endif
