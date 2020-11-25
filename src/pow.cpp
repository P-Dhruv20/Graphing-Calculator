#include "../header/pow.hpp"
#include <cmath>
#include <string>

Pow::Pow(Base* baseOp, Base* powerOp){
	this->baseOperand = baseOp;
	this->powerOperand = powerOp;
}

double Pow::evaluate(){
	return pow(baseOperand->evaluate(),powerOperand->evaluate());
}

std::string Pow::stringify(){
	return baseOperand->stringify() + " ^ " + powerOperand->stringify();
}

