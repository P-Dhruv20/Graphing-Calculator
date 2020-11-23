#ifndef _COMB_HPP_
#define _COMB_HPP_

#include "base.hpp"

class Comb : public Base {
	public:
		Perm(Base* op1, Base* op2);
		virtual double evaluate(){ };
		virtual int evaluateInt();
		virtual std::string stringify(){ };
		virtual std::string stringifyInt();
	private:
		Base* operand1;
		Base* operand2;
};

#endif

