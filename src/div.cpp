#include "../header/div.hpp"
#include "../header/op.hpp"
#include <string>

Div::Div(Base* leftOp, Base* rightOp){
    this->leftOperand = leftOp;
    if(rightOp->evaluate() != 0.0){
        this->rightOperand = rightOp;
    }
    else{
         this->rightOperand = new Op(1.0);
    }
}

double Div::evaluate(){
    return leftOperand->evaluate() / rightOperand->evaluate();
}

std::string Div::stringify(){
    return leftOperand->stringify() + " / " + rightOperand->stringify();
}

