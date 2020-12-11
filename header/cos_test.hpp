#ifndef _COS_TEST_HPP_
#define _COS_TEST_HPP_

#include "gtest/gtest.h"
#include "cos.hpp"
#include "op.hpp"

TEST(CosTest, CosEvaluateNonZero){
	Cos* test = new Cos(new Op(1.0));
	ASSERT_NEAR(test->evaluate(), 0.54030 , 0.00001);
}

TEST(CosTest, CosEvaluateZero){
	Cos* test = new Cos(new Op(0.0));
	ASSERT_NEAR(test->evaluate(), 1.0, 0.00001);
}

TEST(CosTest, CosEvaluateNegative){
	Cos* test = new Cos(new Op(-1.0));
	ASSERT_NEAR(test->evaluate(), 0.54030, 0.00001);
}

TEST(CosTest, CosEvaluateLargerNumber){
	Cos* test = new Cos(new Op(139.0));
	ASSERT_NEAR(test->evaluate(), 0.71796, 0.00001);
}

TEST(CosTest, CosEvaluateDecimal){
	Cos* test = new Cos(new Op(3.23));
	ASSERT_NEAR(test->evaluate(), -0.99609, 0.00001);
}

TEST(CosTest, CosStringifyNonZero){
	Cos* test = new Cos(new Op(10.0));
	EXPECT_EQ(test->stringify(), "cos( 10.000000 )");
}

#endif


