#ifndef _SIN_TEST_HPP_
#define _SIN_TEST_HPP_

#include "gtest/gtest.h"
#include "sin.hpp"
#include "op.hpp"

TEST(SinTest, SinEvaluateNonZero){
	Sin* test = new Sin(new Op(1.0));
	ASSERT_NEAR(test->evaluate(), 0.84147, 0.00001);
}

TEST(SinTest, SinEvaluateZero){
	Sin* test = new Sin(new Op(0.0));
	ASSERT_NEAR(test->evaluate(), 0.0, 0.00001);
}

TEST(SinTest, SinEvaluateNegative){
	Sin* test = new Sin(new Op(-1.0));
	ASSERT_NEAR(test->evaluate(), -0.84147, 0.00001);
}

TEST(SinTest, SinEvaluateLargerNumber){
	Sin* test = new Sin(new Op(150.0));
	ASSERT_NEAR(test->evaluate(), -0.71488, 0.00001);
}
TEST(SinTest, SinEvaluateDecimal){
	Sin* test = new Sin(new Op(6.5));
	ASSERT_NEAR(test->evaluate(), 0.21512, 0.000001);
}
TEST(SinTest, SinStringifyNonZero){
	Sin* test = new Sin(new Op(10.0));
	EXPECT_EQ(test->stringify(), "sin( 10.000000 )" );
}

#endif


