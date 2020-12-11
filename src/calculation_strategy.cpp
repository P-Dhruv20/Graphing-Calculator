
#include "../header/calculation_strategy.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include<cctype>
#include "../header/eval.hpp"
using namespace std;

void CalculationStrategy::execute() {
    this->getUserInput();
    while(this->inputIsValid(this->user_expression) == 0) {
        cout << "INVALID INPUT" << endl;
        this->getUserInput();
    }

    this->getCalculation();
}

void CalculationStrategy::getUserInput() {
    cout << "Enter your expression: ";
    cin >> this->user_expression;
}

int CalculationStrategy::inputIsValid(string str) {
	for(int i = 0; i < str.size(); i++) {
		str.at(i) = toupper(str.at(i));
	}	
	vector<char> brackets;
	int operand_count = 0;
	int operator_count = 0;
	
	for (unsigned int i = 0; i < str.size(); i++) {
		char c = str.at(i);
		if (!isspace(c)) {
			if (isdigit(c)) {
				operand_count++;
				while((i+1) != str.size() && isdigit(str.at(i+1))) {
					i++;
				}
			}
			else if(c == '+' || c == '-' || c == '*'|| c == '/' || c == '^') {
				operator_count++;
			}
			else if(c == '(' || c == '{' || c == '[') {
				brackets.push_back(c);
			}
			else if(c == ')' || c == '}' || c == ']') {
				char prev = brackets.back();
				
				if ((c == ')' && prev == '(') ||
				    (c == '}' && prev == '{') ||
				    (c == ']' && prev == '[')) {
					brackets.pop_back();
				}
			}
			else if (c == '!') {
				if((i-1) != 0) {
					char prev = str.at(i - 1);
					if(!isdigit(prev) && 
					   !(prev == ')' || prev == ']' || prev == '}')) {
						return 0;
					}
				}
				else {
					return 0;
				}
			}
			else if(!isalpha(c)) {
				return 0;
			}
			else {
				if ((c != 'C') && (c != 'T') && (c != 'S')) {
					return 0;
				}
				else if(c == 'C' && str.find("COS") == string::npos) {
					return 0;
				}
				else if (c == 'T' && str.find("TAN") == string::npos) {
                                        return 0;
				}
				else if (c == 'S' && str.find("SIN") == string::npos) {
                                        return 0;
                                }
				else {
					i+=2;
					if (i < str.size()) {
						if(c == 'C' && str.at(i) != 'S') {
        		                                return 0;
	                	                }
                                		else if (c == 'T' && str.at(i) != 'N') {
                                			return 0;
                                		}
                                		else if (c == 'S' && str.at(i) != 'N') {
                                        		return 0;
                                		}		
					}
					else {
						return 0;
					}
				} 
			}
		}
	}
	
	if (operand_count != (operator_count+1)) {
		return 0;
	}
	else if (brackets.size() != 0) {
		return 0;
	}
	
	return 1;
}

void CalculationStrategy::getCalculation() {
    queue<Base*> hold;
    double results = 0;
    hold = shunting_yard(user_expression);
    results = eval(hold,1);
    cout<<"Results: "<<results<<endl;

}
