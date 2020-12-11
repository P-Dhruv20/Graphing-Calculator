#include "../header/fact.hpp"
#include <cmath>
#include "../header/op.hpp"

Fact::Fact(Base* num) {
	if(num->evaluateInt() >= 0) {
	this->NumOperand = num;
	}
	else{
	this->NumOperand = new Op(1);
	}
}

int Fact::evaluateInt() { 
	return tgamma(NumOperand->evaluateInt() + 1);
}

std::string Fact::stringifyInt() {
	return NumOperand->stringifyInt() + " !";
}

