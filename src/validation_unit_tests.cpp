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

TEST(CalculationValidationTests, FactorialInvalid) {
        ExpressionStrategy* test = new CalculationStrategy();

        EXPECT_EQ(test->inputIsValid("5 + !"), 0);
}

TEST(CalculationValidationTests, EmptyInput) {
        ExpressionStrategy* test = new CalculationStrategy();

        EXPECT_EQ(test->inputIsValid(""), 0);
}


int main(int argc, char **arv) {
	::testing::InitGoogleTest(&argc, arv);
	return RUN_ALL_TESTS();
}
