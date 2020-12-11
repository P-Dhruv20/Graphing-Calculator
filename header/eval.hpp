#ifndef EVAL_HPP
#define EVAL_HPP
#include "op.hpp"
#include "operator.hpp"
#include "base.hpp"
#include <queue>
#include <stack>
#include <sstream>
#include <cassert>
#include "trig.hpp"
using namespace std;

double eval(queue<Base*>&q,double var);
queue<Base *> shunting_yard(string input);

#endif // EVAL_HPP
