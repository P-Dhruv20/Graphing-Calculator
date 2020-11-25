#ifndef __CALCULATION_STRATEGY_HPP__
#define __CALCULATION_STRATEGY_HPP__

#include "expression_strategy.hpp"

#include <string>

using namespace std;

class CalculationStrategy : public ExpressionStrategy {
	protected:
		string user_expression;
	public:
		CalculationStrategy() : user_expression(""){ };
		virtual void execute();
		
		virtual void getUserInput();
		virtual int inputIsValid(string);
		void getCalculation();
};

#endif
