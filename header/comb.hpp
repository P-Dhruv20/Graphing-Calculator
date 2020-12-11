#ifndef _COMB_HPP_
#define _COMB_HPP_

#include "base.hpp"

class Comb : public Base {
	public:
		Comb(Base* op1, Base* op2);
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

