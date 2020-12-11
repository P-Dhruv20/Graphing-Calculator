#ifndef __GRAPHING_STRATEGY_HPP__
#define __GRAPHING_STRATEGY_HPP__

#include "expressionstrategy.hpp"
#include "animate.hpp"
#include <string>

using namespace std;


class GraphingStrategy : public ExpressionStrategy {
    protected:
        string user_expression;
    public:
        GraphingStrategy() : user_expression("") { };
        virtual void execute();
        virtual void getUserInput();
        virtual int inputIsValid(string);
        void graph();
};

#endif
