#ifndef TRIG_HPP
#define TRIG_HPP
#include "base.hpp"
#include <cmath>

class Trig : public Base
{
public:
    Trig(string name);
    virtual double evaluate(){};
    virtual std::string stringify();
    virtual std::string stringifyInt(){};
    virtual int precedence(){};
    virtual int associative(){};
    virtual double get_number(){};
    double evaluating(double result);
private:
    string _name;
};

#endif // TRIG_HPP
