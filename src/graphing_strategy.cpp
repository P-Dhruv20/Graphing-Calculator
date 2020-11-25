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
	int valid = 1;
	
	for (unsigned int i = 0; i < str.size(); i++) {
		
	}
	
	if (variable_flag != 1) {
		valid = 0;
	}
	
	return valid;
}

void GraphingStrategy::graph() {
	cout << "TODO: GRAPHING STRATEGY graph()";
}
