#ifndef _SUB_HPP_
#define _SUB_HPP_

#include "base.hpp"

class Sub : public Base{
	
	public: 
		Sub(Base* leftOp, Base* righOp);
		virtual double evaluate();
		virtual int evaluateInt(){ };
		virtual std::string stringify();
		virtual std::string stringifyInt(){ };
	private:
		Base* leftOperand;
		Base* rightOperand;
};

#endif
