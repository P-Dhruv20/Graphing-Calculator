#include "../header/comb.hpp"
#include "../header/op.hpp"
#include <cmath>
#include <string>

Comb::Comb(Base* op1, Base* op1){
	if(op1->evaluateInt() >= 1) {
		this->operand1 = op1;
	}
	else{
		this->operand1 = Op(1);
	}
	if(op2->evaluateInt >= 0 && op2->evaluateInt() <= op1->evaluateInt()){
		this->operand2 = op2;
	}
	else{
	this->operand2 = Op(0);
	}
}

int Comb::evaluateInt(){
	Base* temp;
	temp = Div(Fact(opearand1),Mult(Fact(operand2),Fact(Sub(operand1,operand2))));
	return temp->evaluateInt();
}

std::string Comb::stringifyInt(){
	return operand1->stringifyInt() + " C " + operand2->stringifyInt();
}

