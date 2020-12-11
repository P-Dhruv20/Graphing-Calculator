#include <string>
#include "../header/tan.hpp"
#include "../header/op.hpp"
#include <cmath>

Tan::Tan(Base* deg){
	this->degree = deg;
}

double Tan::evaluate(){
	return tan(degree->evaluate());
}

std::string Tan::stringify(){
	return "tan( " + degree->stringify() + " )";
}


