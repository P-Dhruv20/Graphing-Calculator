#ifndef _POW_HPP_
#define _POW_HPP_

#include "base.hpp"
#include <cmath>

class Pow : public Base{
	public:
		Pow(Base* baseOp,Base* powerOp);
		virtual double evaluate();
		virtual int evaluateInt(){ };
		virtual std::string stringify();
		virtual std::string stringifyInt(){ };
	private:
		Base* baseOperand;
		Base* powerOperand;
};

#endif
