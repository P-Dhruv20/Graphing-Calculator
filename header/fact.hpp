#ifndef _FACT_HPP_
#define _FACT_HPP_

#include "base.hpp"

class Fact : public Base {
	public:
		Fact(Base* num);
		virtual double evaluate() { };
		virtual int evaluateInt();
		virtual std::string stringify(){ };
		virtual std::string stringifyInt();
	private:
		Base* NumOperand;
};

#endif

