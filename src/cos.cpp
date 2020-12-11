#include <string>
#include "../header/cos.hpp"
#include "../header/op.hpp"
#include <cmath>

Cos::Cos(Base* deg) {
	this->degree = deg;
}
	
double Cos::evaluate(){
	return cos(degree->evaluate());
}

std::string Cos::stringify(){
	return "cos( " + degree->stringify() + " )";
}


