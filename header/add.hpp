#ifndef _ADD_HPP_
#define _ADD_HPP_

#include "base.hpp"

class Add : public Base {
	public: 
		Add(Base* leftOp, Base* rightOp);
		virtual double evaluate();
		virtual int evaluateInt(){ };
		virtual std::string stringify();
		virtual std::string stringifyInt(){ };
	private:
		Base* leftOperand;
		Base* rightOperand;
};

#endif
