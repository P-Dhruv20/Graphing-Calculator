#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult : public Base {
    public:
        Mult(Base* left, Base* right);

        virtual int evaluateInt(){};
        virtual double evaluate();
        virtual std::string stringify();
        virtual std::string stringifyInt(){ };
        virtual int precedence(){};
        virtual int associative(){};
        virtual double get_number(){};
    private:
        int _type;
        Base* leftOperand;
        Base* rightOperand;
};

#endif
