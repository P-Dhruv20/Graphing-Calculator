#include <string>
#include "../header/mult.hpp"

Mult::Mult(Base* left, Base* right) {
    this->leftOperand = left;
    this->rightOperand = right;
}

double Mult::evaluate() {
    return leftOperand->evaluate() * rightOperand->evaluate();
}

std::string Mult::stringify() {
    return leftOperand->stringify() + " * " + rightOperand->stringify();
}
