#include <string>
#include "../header/op.hpp"

Op::Op(double value):Base(0),val(value){}


double Op::evaluate() {
    return this->val;
}

std::string Op::stringify() {
    return std::to_string(this->val);
}


