#include "operator.hpp"
Operator::Operator(Base* leftop, Base* rightop){
    leftoperand=leftop;
    rightoperand=rightop;
}

Operator::Operator(char a):_a(a),Base(1){}

double Operator::evaluating(Base *leftop, Base *rightop){
    double result = 0.0;
    Add* add_test = new Add(leftop,rightop);
    Sub* sub_test = new Sub(leftop,rightop);
    Mult* mult_test = new Mult(leftop,rightop);
    Div* div_test = new Div(leftop,rightop);
    Pow* pow_test = new Pow(leftop,rightop);
    switch (_a) {
        case '+':
            result=add_test->evaluate();
            break;
        case '-':
            result =sub_test->evaluate();
            break;
        case '*':
            result=mult_test->evaluate();
            break;
        case '/':
            result =div_test->evaluate();
            break;
        case '^':
            result=pow_test->evaluate();
            break;
        default:
            break;
    }
    return result;
}
int Operator::precedence(){
    int prec;
    switch(_a){
    case '^':
        prec = 4;
        break;
    case '*':
        prec = 3;
        break;
    case '/':
        prec = 3;
        break;
    case '+':
        prec = 2;
        break;
    case '-':
        prec = 2;
        break;
    default:
        prec = -1;
        break;
    }
    return prec;
}
int Operator::associative(){
    int ass;
    switch(_a){
    case '^':
        ass = 1;
        break;
    case '*':
        ass = 0;
        break;
    case '/':
        ass = 0;
        break;
    case '+':
        ass = 0;
        break;
    case '-':
        ass = 0;
        break;
    default:
        ass=-1;
        break;
    }
    return ass;
}
double Operator::evaluate(){
    return evaluating(leftoperand,rightoperand);
}

