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
                virtual int associative(){};
                virtual int precedence(){};

	private:
		Base* NumOperand;
};

#endif

