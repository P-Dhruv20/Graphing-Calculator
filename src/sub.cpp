#include "../header/sub.hpp"
#include <string>

Sub::Sub(Base* leftOp, Base* rightOp):Base(1),leftOperand(leftOp),rightOperand(rightOp){}
double Sub::evaluate(){
    return leftOperand->evaluate() - rightOperand->evaluate();
}
std::string Sub::stringify(){
    return leftOperand->stringify() + " - " + rightOperand->stringify();
}

