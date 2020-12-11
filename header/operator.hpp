#ifndef OPERATOR_HPP
#define OPERATOR_HPP
#include "base.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "trig.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "pow.hpp"
class Operator: public Base{

public:
    Operator(Base* leftop, Base* rightop);
    Operator(char a);

        virtual int evaluateInt(){};
    virtual double evaluate();
    virtual std::string stringify(){};
    virtual std::string stringifyInt(){};
    double evaluating(Base* leftop, Base* rightop);
    int precedence();
    int associative();
    char get_item() const{return _a;}
private:
    char _a;
    Base* leftoperand;
    Base* rightoperand;
};

#endif // OPERATOR_HPP
