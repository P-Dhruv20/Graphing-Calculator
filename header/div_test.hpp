#ifndef _DIV_TEST_HPP_
#define _DIV_TEST_HPP_

#include "gtest/gtest.h"
#include "mock_class.hpp"
#include "div.hpp"

TEST(DivTest, DivEvaluateNonZero){
	Div* test = new Div(new  Op(7.5), new Op(10.0));
	EXPECT_EQ(test->evaluate(), 0.75);
}

TEST(DivTest, DivEvaluateZero){
	Div* test = new Div(new Op(5.5), new Op(0.0));
	EXPECT_EQ(test->evaluate(), 5.5);
}

TEST(DivTest, DivEvaluateDecimal){
	Div* test = new Div(new Op(7.5), new Op(5.5));
	ASSERT_NEAR(test->evaluate(), 1.364, 0.001);
}

TEST(DivTest, DivEvaluateNegative){
	Div* test = new Div(new Op(-10.0), new Op(5.5));
	ASSERT_NEAR(test->evaluate(), -1.8182, 0.0001);
}

TEST(DivTest, DivEvaluateTwoNegatives){
	Div* test = new Div(new Op(-3.0), new Op(-10.0));
	EXPECT_EQ(test->evaluate(), 0.3);
}

TEST(DivTest, DivStringifyNonZero){
	Div* test = new Div(new Op(5.5), new Op(7.5));
	EXPECT_EQ(test->stringify(), "5.500000 / 7.500000");
}

TEST(DivTest, DivStringifyTwoNegatives){
	Div* test = new Div(new Op(-3.0), new Op(-10.0));
	EXPECT_EQ(test->stringify(), "-3.000000 / -10.000000");
}

TEST(DivTest, DivStringifyNegative){
	Div* test = new Div(new Op(7.5), new Op(-10.0));
	EXPECT_EQ(test->stringify(), "7.500000 / -10.000000");
}

#endif

