#ifndef __SHUNTING_YARD_TEST_HPP_
#define __SHUNTING_YARD_TEST_HPP_
#include "gtest/gtest.h"
#include "eval.hpp"

TEST(shuntingyard, longexpression){
	queue<Base*>hold;
	string input = "8+5/5*10-2^3";
	double val = 0;
	hold = shunting_yard(input);
	val = eval(hold,1);
	EXPECT_EQ(val,10);
}
TEST(shuntingyard, longexpression2){
	queue<Base*>hold;
        string input = "9/3+2^4-2*4";
        double val = 0;
        hold = shunting_yard(input);
        val = eval(hold,1);
        EXPECT_EQ(val,11);
}
TEST(shuntingyard, longexpression3){
	queue<Base*> hold;
	string input = "3+4/9*2-4^6+8/2+(4-9*(2+8))";
	double val = 0;
	hold = shunting_yard(input);
	val = eval(hold,1);
	EXPECT_NEAR(val,-4174.11112,.00001);
	
}
TEST(shuntingyard, parentheses_tests){
        queue<Base*>hold;
        string input = "9*4+(4*(3+2))";
        double val = 0;
        hold = shunting_yard(input);
        val = eval(hold,1);
        EXPECT_EQ(val,56);
}

TEST(shuntingyard, parentheses_test2){
        queue<Base*>hold;
        string input = "(3+4)/(2*3)+4*(8/2)";
        double val = 0;
        hold = shunting_yard(input);
        val = eval(hold,1);
	double results = val;
        EXPECT_EQ(val,results);
}
TEST(shuntingyard, parentheses_test3){
	queue<Base*> hold;
	string input = "(3+(4-2*(5+1)))";
	double val = 0;
	hold =shunting_yard(input);
	val = eval(hold,1);
	EXPECT_EQ(val,-5);
}
TEST(shuntingyard, parentheses_test4){
	queue<Base*> hold;
	string input = "(3+4*(2-5/(2^2)+(4-(2+1))))";
	double val = 0;
	hold = shunting_yard(input);
	val = eval(hold,1);
	EXPECT_EQ(val,10);
}
TEST(shuntingyard, parentheses_test5){
        queue<Base*> hold;
        string input = "(3+4*(2-5/(2^2)+(4-(2+1))))+9*(4+2)^2";
        double val = 0;
        hold = shunting_yard(input);
        val = eval(hold,1);
        EXPECT_EQ(val,334);
}

TEST(shuntingyard, trigandExpression){
        queue<Base*>hold;
        string input = "sin(1+2)";
        double val = 0;
        hold = shunting_yard(input);
        val = eval(hold,1);
        double results = val;
        EXPECT_EQ(val,results);
}
TEST(shuntingyard, trigandExpression2){
        queue<Base*>hold;
        string input = "sin(cos(tan(2)))";
        double val = 0;
        hold = shunting_yard(input);
        val = eval(hold,1);
        EXPECT_NEAR(val,-0.54496,.00001);
}
TEST(shuntingyard, trigandExpression3){
	queue<Base*> hold;
	string input = "1/cos(1)";
	double val = 0;
	hold = shunting_yard(input);
	val = eval(hold,1);
	EXPECT_NEAR(val,1.85082,.00001);
}
#endif
