#include "gtest/gtest.h"
#include "../header/expression_strategy.hpp"
#include "../header/calculation_strategy.hpp"
#include "../header/graphing_strategy.hpp"

#include <iostream>
#include <string>

using namespace std;

TEST(CalculationValidationTests, SimpleArithmeticValid) {
	ExpressionStrategy* test = new CalculationStrategy();
	string str = "4 + 3 - 5 * 8 / 4";

	EXPECT_EQ(test->inputIsValid(str), 1);
}

TEST(CalculationValidationTests, SimpleArithmeticMissingOperand) {
        ExpressionStrategy* test = new CalculationStrategy();
	string str = "4 + 3 + ";
	
        EXPECT_EQ(test->inputIsValid(str), 0);
}

TEST(CalculationValidationTests, ParenthesisValid) {
        ExpressionStrategy* test = new CalculationStrategy();

        EXPECT_EQ(test->inputIsValid("(4 + 3) / 8 "), 1);
}

TEST(CalculationValidationTests, ParenthesisInvalid) {
        ExpressionStrategy* test = new CalculationStrategy();

        EXPECT_EQ(test->inputIsValid("(4 + 3 / 8 "), 0);
}

TEST(CalculationValidationTests, FactorialValid) {
        ExpressionStrategy* test = new CalculationStrategy();

        EXPECT_EQ(test->inputIsValid("5 + 7!"), 1);
}

TEST(CalculationValidationTests, SineTest) {
        ExpressionStrategy* test = new CalculationStrategy();

        EXPECT_EQ(test->inputIsValid("Sin(5) + 7"), 1);
}


TEST(CalculationValidationTests, FactorialInvalid) {
        ExpressionStrategy* test = new CalculationStrategy();

        EXPECT_EQ(test->inputIsValid("5 + !"), 0);
}

TEST(CalculationValidationTests, EmptyInput) {
        ExpressionStrategy* test = new CalculationStrategy();

        EXPECT_EQ(test->inputIsValid(""), 0);
}

TEST(GraphingValidationTests, SimpleArithmeticValid) {
	ExpressionStrategy* test = new GraphingStrategy();
	string str = "4 + 3 - x * 8 / 4";

	EXPECT_EQ(test->inputIsValid(str), 1);
}

TEST(GraphingValidationTests, SimpleArithmeticMissingOperand) {
        ExpressionStrategy* test = new GraphingStrategy();
	string str = "4 + x + ";
	
        EXPECT_EQ(test->inputIsValid(str), 0);
}

TEST(GraphingValidationTests, ParenthesisValid) {
        ExpressionStrategy* test = new GraphingStrategy();

        EXPECT_EQ(test->inputIsValid("(4 + x) / 8 "), 1);
}

TEST(GraphingValidationTests, ParenthesisInvalid) {
        ExpressionStrategy* test = new GraphingStrategy();

        EXPECT_EQ(test->inputIsValid("(x + 3 / 8 "), 0);
}

TEST(GraphingValidationTests, EmptyInput) {
        ExpressionStrategy* test = new GraphingStrategy();

        EXPECT_EQ(test->inputIsValid(""), 0);
}

TEST(GraphingValidationTests,NoVariable) {
        ExpressionStrategy* test = new GraphingStrategy();

        EXPECT_EQ(test->inputIsValid("1 + 8"), 0);
}

TEST(GraphingValidationTests, MultipleVariables) {
        ExpressionStrategy* test = new GraphingStrategy();

        EXPECT_EQ(test->inputIsValid("1 + X * x - 3"), 0);
}


int main(int argc, char **arv) {
	::testing::InitGoogleTest(&argc, arv);
	return RUN_ALL_TESTS();
}
