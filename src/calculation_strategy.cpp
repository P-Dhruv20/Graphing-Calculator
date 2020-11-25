#include "../header/calculation_strategy.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include<cctype>

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
	//int valid = 1;
	
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
				if(i == 0 || (i+1) == str.size()) {
                	                return 0;
                                }
				else if(c =='C' || c == 'P') {
					if(!isdigit(str.at(i-1)) || !isdigit(str.at(i+1))) {
						return 0;	
					}
					else if (c == 'C' && str.find("COS") == string::npos) {
						return 0;
					}
				}
				else if(c == 'T') {
					if (c == 'T' && str.find("TAN") == string::npos) {
                                                return 0;
                                        }
				}
				else if(c == 'S') {
                                        if (c == 'S' && str.find("SIN") == string::npos) {
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
	cout << "TODO: CALCULATION STRATEGY getCalculation()"<< endl;
	cout << "Call Shunting-yard alg for calculation, parameters being user_expression" << endl;
	cout << "Make sure to include alg header file" << endl;	
}
