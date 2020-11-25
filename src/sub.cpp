#include "../header/sub.hpp"
#include <string>

Sub::Sub(Base* leftOp, Base* rightOp){
	this->leftOperand = leftOp;
	this->rightOperand = rightOp;
}
double Sub::evaluate(){
	return leftOperand->evaluate() - rightOperand->evaluate();
}
std::string Sub::stringify(){
	return leftOperand->stringify() + " - " + rightOperand->stringify();
}
