#include "../header/graphing_strategy.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void GraphingStrategy::execute() {
	this->getUserInput();
	while (this->inputIsValid(this->user_expression) == 0) {
		cout << "INVALID INPUT" << endl;
		this->getUserInput();
	}
	
	this->graph();
}

void GraphingStrategy::getUserInput() {
	cout << "Enter your function (with variable x): ";
	cin >> this->user_expression;
}

int GraphingStrategy::inputIsValid(string str) {
	int variable_flag = 0;

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
				else if(c == 'X') {
					operand_count++;
					variable_flag++;
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
	else if (variable_flag != 1) {
		return 0;
	}
	
	return 1;
}

void GraphingStrategy::graph() {
	cout << "TODO: GRAPHING STRATEGY graph()";
}
