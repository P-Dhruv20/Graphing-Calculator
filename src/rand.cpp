#include <string>
#include "../header/rand.hpp"

Rand::Rand() {
	this->value = std::rand() % 100;
	this->valueInt = std::rand() % 100;
}

double Rand::evaluate() {
    return this->value;
}

int Rand::evaluateInt() {
	return this->valueInt;
}

std::string Rand::stringify() {
    return std::to_string(this->value);
}

std::string Rand::stringifyInt() {
	return std::to_string(this->valueInt);
}

