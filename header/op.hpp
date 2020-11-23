#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    public:
        Op(double value);
	Op(int valueInt);
        virtual double evaluate();
        virtual int evaluateInt();
	virtual std::string stringify();
	virtual std::string stringifyInt();
    private:
	double val;
	int valInt;
};

#endif
