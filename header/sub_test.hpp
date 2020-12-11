#ifndef _SUB_TEST_HPP_
#define _SUB_TEST_HPP_

#include "gtest/gtest.h"
#include "mock_class.hpp"
#include "sub.hpp"

TEST(SubTest, SubEvaluateNonZero){
	Sub* test = new Sub(new Op(7.5), new Op(5.5));
	EXPECT_EQ(test->evaluate(), 2.0);
}

TEST(SubTest, SubEvaluateZero){
	Sub* test = new Sub(new Op(7.5), new Op(0.0));
	EXPECT_EQ(test->evaluate(), 7.5);
}

TEST(SubTest, SubEvaluateDecimal){
	Sub* test = new Sub(new Op(7.5), new Op(10.0));
	EXPECT_EQ(test->evaluate(), -2.5);
}

TEST(SubTest, SubEvaluateNegative){
	Sub* test = new Sub(new Op(5.5), new Op(-3.0));
	EXPECT_EQ(test->evaluate(), 8.5);
}

TEST(SubTest, SubEvaluatenTwoNegatives){
	Sub* test = new Sub(new Op(-10.0), new Op(-3.0));
	EXPECT_EQ(test->evaluate(), -7.0);
}

TEST(SubTest, SubStringifyNonZero){
	Sub* test = new Sub(new Op(10.0), new Op(5.5));
	EXPECT_EQ(test->stringify(), "10.000000 - 5.500000");
}
TEST(SubTest, SubStringifyTwoNEegatives){
	Sub* test = new Sub(new Op(-3.0), new Op(-10.0));
	EXPECT_EQ(test->stringify(), "-3.000000 - -10.000000");
}

#endif
