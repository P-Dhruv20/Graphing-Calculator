#include <string>
#include "mult.hpp"

Mult::Mult(Base* left, Base* right):Base(1),leftOperand(left),rightOperand(right){}

double Mult::evaluate() {
    return leftOperand->evaluate() * rightOperand->evaluate();
}

std::string Mult::stringify() {
    return leftOperand->stringify() + " * " + rightOperand->stringify();
}
