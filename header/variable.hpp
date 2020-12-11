#ifndef VARIABLE_HPP
#define VARIABLE_HPP
#include "base.hpp"

class Variable: public Base{
public:
    Variable(char name);
    virtual double evaluate(){};
    virtual int evaluateInt(){};
    virtual std::string stringify(){};
    virtual std::string stringifyInt(){ };
    virtual int precedence(){};
    virtual int associative(){};
    virtual double get_number(){};
private:
    char _name;
};

#endif // VARIABLE_HPP
