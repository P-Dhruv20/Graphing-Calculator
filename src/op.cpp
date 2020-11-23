#include <string>
#include "../header/op.hpp"

Op::Op(double value) {
    this->val = value;
}

Op::Op(int valueInt) {
	this->valInt = valueInt;
}

double Op::evaluate() {
    return this->val;
}

int Op::evaluateInt() {
	return this->valInt;
}

std::string Op::stringify() {
    return std::to_string(this->val);
}

std::string Op::stringifyInt() {
	return std::to_string(this->valInt);
}
