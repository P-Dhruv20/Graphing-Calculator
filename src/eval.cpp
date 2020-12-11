#include "../header/eval.hpp"
double eval(queue<Base *> &q){
    Base* hold;
    Operator* oper;
    double result;
    Base* right;
    Base* left;
    Base* top;
    Trig* func;
    double trig_result;
    stack<Base*> s;
    while(!q.empty()){
        hold = q.front();
        q.pop();
        //checking for what type it is ie numbers = 0 operators = 1
        switch(hold->get_type()){
        case 0:
            s.push(hold);
            break;
        case 1:
             right = s.top();
             s.pop();
             left = s.top();
             s.pop();
             oper =static_cast <Operator *>(hold);
             result = oper->evaluating(left,right);
             s.push(new Op(result));
            break;
//        case 2:
//            s.push(new Op(var));
//            break;
        case 3:
            top = s.top();
            s.pop();
            func = static_cast<Trig*>(hold);
            trig_result = func->evaluating(top->get_number());
            s.push(new Op(trig_result));
            break;
        default:
            cout<<"error can't find type to eval in switch statement"<<endl;
            break;
        }
    }
    return s.top()->get_number();

}
queue<Base*> shunting_yard(string input){
    queue<Base*> output;
    stack<Base*> Operator_stack;
    string stringtemp;
    string new_temp;
    int i = 0;
    double temp =0;
    while(i<input.size()){
        //convert string into digits using stringstream
        if(isdigit(input[i])){
            stringtemp = input[i];
            //while the next number is a digit continue copying numbers
            while(isdigit(input[i+1])){
                stringtemp += input[i+1];
                i++;
            }
            stringstream stream(stringtemp);
            stream>>temp;
            output.push(new Op(temp));
        }
        else if(input[i] == '+' || input[i] == '-' || input[i]=='*'
                || input[i]=='/' || input[i] == '^'){
            Operator tempOperator (input[i]);
            if(!Operator_stack.empty()){
                //precedence checker
                while(!Operator_stack.empty() && (Operator_stack.top()->precedence()
                      > tempOperator.precedence() || (Operator_stack.top()->precedence()
                      == tempOperator.precedence() && Operator_stack.top()->associative() == 0))
                      && Operator_stack.top()->get_item() != '('){
                    //take the item from the top and puts it in queue then deletes from the stack
                    output.push(Operator_stack.top());
                    Operator_stack.pop();
                }
            }
            Operator_stack.push(new Operator(input[i]));
        }
        else if(input[i] == '('){
            Operator_stack.push(new Operator(input[i]));
        }
        else if(input[i] == ')'){
            while(Operator_stack.top()->get_item() != '('){
                assert(!Operator_stack.empty());
                output.push(Operator_stack.top());
                Operator_stack.pop();
            }
            Operator_stack.pop();
        }
//        else if((input[i]=='X' || input[i]=='x')){
//            output.push(new Variable('x'));
//        }
        else if(input[i]=='s' || input[i]== 't' || input[i]== 'c'){
            new_temp = input[i];
            while(isalpha(input[i+1])){
                new_temp += input[i+1];
                i++;
            }
            Operator_stack.push(new Trig(new_temp));
        }
        i++;
    }
    while(!Operator_stack.empty()){
        if(Operator_stack.top()->get_item() == '(' || Operator_stack.top()->get_item() == ')'){
            cout<<"Unfinished Parenthesis";
        }
        output.push(Operator_stack.top());
        Operator_stack.pop();
    }
    return output;
}

