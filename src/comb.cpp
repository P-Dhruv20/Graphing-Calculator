#include "../header/comb.hpp"
#include "../header/op.hpp"
#include <cmath>
#include <string>

Comb::Comb(Base* op1, Base* op2) {
	if(op1->evaluateInt() >= 1) {
		this->operand1 = op1;
	}
	else{
	this->operand1 = new Op(1);
	}
	if(op2->evaluateInt() >= 0 && op2->evaluateInt() <= op1->evaluateInt()){
		this->operand2 = op2;
	}
	else{
	this->operand2 = new Op(0);
	}
}

int Comb::evaluateInt(){
	return ((tgamma(operand1->evaluateInt()+1))/((tgamma(operand2->evaluateInt()+1))*(tgamma(operand1->evaluateInt()-operand2->evaluateInt()+1))));
}

std::string Comb::stringifyInt(){
	return operand1->stringifyInt() + " C " + operand2->stringifyInt();
}

