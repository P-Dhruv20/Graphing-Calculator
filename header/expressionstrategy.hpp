#ifndef _EXPRESSIONSTRATEGY_HPP_
#define _EXPRESSIONSTRATEGY_HPP_

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
