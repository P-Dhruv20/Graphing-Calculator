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

TEST(CalculationValidationTests, SimpleArithmeticMissingOperator) {
        ExpressionStrategy* test = new CalculationStrategy();
        string str = "4 +  + ";

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

TEST(CalculationValidationTests, SineCosineTestValid) {
        ExpressionStrategy* test = new CalculationStrategy();

        EXPECT_EQ(test->inputIsValid("Sin(5)*Cos(4/5) + 7"), 1);
}

TEST(CalculationValidationTests, SineCosineTestInvalid) {
        ExpressionStrategy* test = new CalculationStrategy();

        EXPECT_EQ(test->inputIsValid("Sin(5)*os(4/5) + 7"), 0);
}


TEST(CalculationValidationTests, AllTrigTestValid) {
        ExpressionStrategy* test = new CalculationStrategy();

        EXPECT_EQ(test->inputIsValid("Sin(5)*Cos(4/5) + 7"), 1);
}


TEST(CalculationValidationTests, SineTestInvalid) {
        ExpressionStrategy* test = new CalculationStrategy();

        EXPECT_EQ(test->inputIsValid("Sn(5) + 7"), 0);
}

TEST(CalculationValidationTests, MultipleSineTestInvalid) {
        ExpressionStrategy* test = new CalculationStrategy();

        EXPECT_EQ(test->inputIsValid("Sn(5) +Sin(4)/ 7"), 0);
}

TEST(CalculationValidationTests, CosineTest) {
        ExpressionStrategy* test = new CalculationStrategy();

        EXPECT_EQ(test->inputIsValid("Cos(5) + 7"), 1);
}

TEST(CalculationValidationTests, CosineTestInvalid) {
        ExpressionStrategy* test = new CalculationStrategy();

        EXPECT_EQ(test->inputIsValid("Cs(5) + 7"), 0);
}

TEST(CalculationValidationTests, MultipleCosineTestInvalid) {
        ExpressionStrategy* test = new CalculationStrategy();

        EXPECT_EQ(test->inputIsValid("Cs(5) + 7 - Cos(34)"), 0);
}

TEST(CalculationValidationTests, TangentTest) {
        ExpressionStrategy* test = new CalculationStrategy();

        EXPECT_EQ(test->inputIsValid("Tan(10)"), 1);
}

TEST(CalculationValidationTests, TangentTestInvalid) {
        ExpressionStrategy* test = new CalculationStrategy();

        EXPECT_EQ(test->inputIsValid("Ta(10)"), 0);
}

TEST(CalculationValidationTests, MultipleTangentTestInvalid) {
        ExpressionStrategy* test = new CalculationStrategy();

        EXPECT_EQ(test->inputIsValid("Tan(24) - Ta(10)"), 0);
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

TEST(GraphingValidationTests, TrigValid) {
        ExpressionStrategy* test = new GraphingStrategy();

        EXPECT_EQ(test->inputIsValid("Sin(x) * Cos(48) - 3"), 1);
}

TEST(GraphingValidationTests, TrigInvalid) {
        ExpressionStrategy* test = new GraphingStrategy();

        EXPECT_EQ(test->inputIsValid("Sin() * Cos(48) - 3"), 0);
}

TEST(GraphingValidationTests, NonArithmeticInput) {
        ExpressionStrategy* test = new GraphingStrategy();

        EXPECT_EQ(test->inputIsValid("Hello world!"), 0);
}

TEST(CalculationValidationTests, NonArithmeticInput) {
        ExpressionStrategy* test = new CalculationStrategy();

        EXPECT_EQ(test->inputIsValid("Hello world!"), 0);
}

TEST(CalculationValidationTests, SingleOperandValid) {
        ExpressionStrategy* test = new CalculationStrategy();

        EXPECT_EQ(test->inputIsValid("12"), 1);
}

TEST(GraphingValidationTests, SingleOperandInvalid) {
        ExpressionStrategy* test = new GraphingStrategy();

        EXPECT_EQ(test->inputIsValid("12"), 0);
}

TEST(GraphingValidationTests, SingleVariable) {
        ExpressionStrategy* test = new GraphingStrategy();

        EXPECT_EQ(test->inputIsValid("x"), 1);
}

TEST(GraphingValidationTests, TangentTest) {
        ExpressionStrategy* test = new GraphingStrategy();

        EXPECT_EQ(test->inputIsValid("Tan(x)"), 1);
}

TEST(GraphingValidationTests, TangentTestInvalid) {
        ExpressionStrategy* test = new GraphingStrategy();

        EXPECT_EQ(test->inputIsValid("Ta(x)"), 0);
}

TEST(GraphingValidationTests, MultipleTangentTestInvalid) {
        ExpressionStrategy* test = new GraphingStrategy();

        EXPECT_EQ(test->inputIsValid("Tan(x) - Ta(10)"), 0);
}

TEST(GraphingValidationTests, CosineTest) {
        ExpressionStrategy* test = new GraphingStrategy();

        EXPECT_EQ(test->inputIsValid("Cos(x)"), 1);
}

TEST(GraphingValidationTests, CosineTestInvalid) {
        ExpressionStrategy* test = new GraphingStrategy();

        EXPECT_EQ(test->inputIsValid("Co(x)"), 0);
}

TEST(GraphingValidationTests, MultipleCosineTestInvalid) {
        ExpressionStrategy* test = new GraphingStrategy();

        EXPECT_EQ(test->inputIsValid("Cos(x) - Cs(10)"), 0);
}

TEST(GraphingValidationTests, SineTest) {
        ExpressionStrategy* test = new GraphingStrategy();

        EXPECT_EQ(test->inputIsValid("Sin(x)"), 1);
}

TEST(GraphingValidationTests, SineTestInvalid) {
        ExpressionStrategy* test = new GraphingStrategy();

        EXPECT_EQ(test->inputIsValid("Si(x)"), 0);
}

TEST(GraphingValidationTests, MultipleSineTestInvalid) {
        ExpressionStrategy* test = new GraphingStrategy();

        EXPECT_EQ(test->inputIsValid("Sin(x) - Sn(10)"), 0);
}

int main(int argc, char **arv) {
	::testing::InitGoogleTest(&argc, arv);
	return RUN_ALL_TESTS();
}
