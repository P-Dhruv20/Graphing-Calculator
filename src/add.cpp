#include "add.hpp"
#include <string>

Add::Add(Base* leftOp, Base* rightOp):Base(1),leftOperand(leftOp),rightOperand(rightOp){}

double Add::evaluate(){
    return leftOperand->evaluate() + rightOperand->evaluate();
}

std::string Add::stringify(){
    return leftOperand->stringify() + " + " + rightOperand->stringify();
}

