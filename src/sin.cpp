#include <string>
#include "../header/sin.hpp"
#include "../header/op.hpp"
#include <cmath>

Sin::Sin(Base* deg) {
	this->degree = deg;
}

double Sin::evaluate(){
	return sin(degree->evaluate());
}

std::string Sin::stringify(){
	return "sin( " + degree->stringify() + " )";
}


