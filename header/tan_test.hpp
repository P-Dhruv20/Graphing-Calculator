#ifndef _TAN_TEST_HPP_
#define _TAN_TEST_HPP_

#include "gtest/gtest.h"
#include "tan.hpp"
#include "op.hpp"

TEST(TanTest, TanEvaluateNonZero){
	Tan* test = new Tan(new Op(1.0));
	ASSERT_NEAR(test->evaluate(), 1.55740 , 0.00001);
}

TEST(TanTest, TanEvaluateZero){
	Tan* test = new Tan(new Op(0.0));
	ASSERT_NEAR(test->evaluate(), 0.0, 0.00001);
}

TEST(TanTest, TanEvaluateNegative){
	Tan* test = new Tan(new Op(-1.0));
	ASSERT_NEAR(test->evaluate(), -1.55740 , 0.00001);
}

TEST(TanTest, TanEvaluateLargerNumber){
	Tan* test = new Tan(new Op(145.0));
	ASSERT_NEAR(test->evaluate(), 0.52920 , 0.00001);
}

TEST(TanTest, TanEvaluateDecimal){
	Tan* test = new Tan(new Op(5.86));
	ASSERT_NEAR(test->evaluate(), -0.450398, 0.000001);
}

TEST(TanTest, TanStringifyNonZero){
	Tan* test = new Tan(new Op(10.0));
	EXPECT_EQ(test->stringify(), "tan( 10.000000 )" );
}

#endif


