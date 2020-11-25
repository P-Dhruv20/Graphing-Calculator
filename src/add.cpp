#include "../header/add.hpp"
#include <string>

Add::Add(Base* leftOp, Base* rightOp){
	this->leftOperand = leftOp;
	this->rightOperand = rightOp;
}

double Add::evaluate(){
	return leftOperand->evaluate() + rightOperand->evaluate();
}

std::string Add::stringify(){
	return leftOperand->stringify() + " + " + rightOperand->stringify();
}
