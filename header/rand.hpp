#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"

class Rand : public Base {
    public:
        Rand();
        virtual double evaluate();
	virtual int evaluateInt();
        virtual std::string stringify();
	virtual std::string stringifyInt();
        virtual int associative(){};
        virtual int precedence(){};

    private:
        double value;
	int valueInt;
};

#endif
