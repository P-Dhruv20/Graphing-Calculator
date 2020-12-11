#ifndef _POW_TEST_HPP_
#define _POW_TEST_HPP_

#include "gtest/gtest.h"
#include "mock_class.hpp"
#include "pow.hpp"

TEST(PowTest, PowEvaluateNonZero){
	Pow* test = new Pow(new Op(10.0), new Op(10.0));
	EXPECT_EQ(test->evaluate(), 10000000000.0);
}

TEST(PowTest, PowEvaluateZeroBase){
	Pow* test = new Pow(new Op(0.0), new Op(7.5));
	EXPECT_EQ(test->evaluate(), 0.0);
}

TEST(PowTest, PowEvaluateZeroPower){
	Pow* test = new Pow(new Op(7.5), new Op(0.0));
	EXPECT_EQ(test->evaluate(), 1.0);
}

TEST(PowTest, PowEvaluateDecimal){
	Pow* test = new Pow(new Op(5.5), new Op(7.5));
	ASSERT_NEAR(test->evaluate(), 357042.7108, 0.5);
}

TEST(PowTest, PowEvaluateNegativePower){
	Pow* test = new Pow(new Op(10.0), new Op(-3.0));
	EXPECT_EQ(test->evaluate(), 0.001 );
}

TEST(PowTest, PowEvaluateTwoNegatives){
	Pow* test = new Pow(new Op(-10.0), new Op(-3.0));
	EXPECT_EQ(test->evaluate(), -0.001);
}

TEST(PowTest, PowStringifyNonZero){
	Pow* test = new Pow(new Op(5.5), new Op(7.5));
	EXPECT_EQ(test->stringify(), "5.500000 ^ 7.500000");
}

TEST(PowTest, PowStringifyTwoNegatives){
	Pow* test = new Pow(new Op(-3.0), new Op(-10.0));
	EXPECT_EQ(test->stringify(), "-3.000000 ^ -10.000000");
}

TEST(PowTest, PowStringifyNegativeBase){
	Pow* test = new Pow(new Op(-3.0), new Op(7.5));
	EXPECT_EQ(test->stringify(), "-3.000000 ^ 7.500000");
}

TEST(PowTest, PowStringifyNegativePower){
	Pow* test = new Pow(new Op(5.5), new Op(-10.0));
	EXPECT_EQ(test->stringify(), "5.500000 ^ -10.000000");
}

#endif
