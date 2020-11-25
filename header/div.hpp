#ifndef _DIV_HPP_
#define _DIV_HPP_

#include "base.hpp"

class Div : public Base {
	public:
		Div(Base* leftOp, Base* rightOp);
		virtual double evaluate();
		virtual int evaluateInt(){ };
		virtual std::string stringify();
		virtual std::string stringifyInt(){ };
	private:
		Base* leftOperand;
		Base* rightOperand;
};

#endif
