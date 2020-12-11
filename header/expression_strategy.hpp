#ifndef __EXPRESSION_STRATEGY_HPP__
#define __EXPRESSION_STRATEGY_HPP__

#include <string>

using namespace std;

class ExpressionStrategy {
	protected:
		string user_expression;
	public:
		ExpressionStrategy() : user_expression("") { };
		virtual void execute() = 0;
		
		//Helper functions
		virtual void getUserInput() = 0;
		virtual int inputIsValid(string) = 0;
};
		
#endif
