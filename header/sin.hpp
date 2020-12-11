#ifndef _SIN_HPP_
#define _SIN_HPP_

#include "base.hpp"

class Sin : public Base {
	public:
		Sin(Base* deg);
		virtual double evaluate();
		virtual int evaluateInt(){};
		virtual std::string stringify();
		virtual std::string stringifyInt(){};
		virtual int associative(){};
		virtual int precedence(){};
	private:
		Base* degree;
};

#endif
