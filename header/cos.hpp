#ifndef _COS_HPP_
#define _COS_HPP_

#include "base.hpp"

class Cos : public Base {
	public:
		Cos(Base* deg);
		virtual double evaluate();
		virtual int evaluateInt(){};
		virtual std::string stringify();
		virtual std::string stringifyInt(){};
	private:
		Base* degree;
};

#endif
