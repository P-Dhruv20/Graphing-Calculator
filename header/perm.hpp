#ifndef _PERM_HPP_
#define _PERM_HPP_

#include "base.hpp"

class Perm : public Base {
	public:
		Perm(Base* op1, Base* op2);
		virtual double evaluate(){ };
		virtual int evaluateInt();
		virtual std::string stringify(){ };
		virtual std::string stringifyInt();
                virtual int associative(){};
                virtual int precedence(){};

	private:
		Base* operand1;
		Base* operand2;
};

#endif

