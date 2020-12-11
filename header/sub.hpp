#ifndef _SUB_HPP_
#define _SUB_HPP_

#include "base.hpp"

class Sub : public Base{

    public:
        Sub(Base* leftOp, Base* righOp);

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
