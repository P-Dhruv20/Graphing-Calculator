#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult : public Base {
    public:
        Mult(Base* left, Base* right);
        virtual double evaluate();
	virtual int evaluateInt(){ };
        virtual std::string stringify();
	virtual std::string stringifyInt(){ };
    private:
        Base* leftOperand;
        Base* rightOperand;
};

#endif
