#ifndef _ADD_TEST_HPP_
#define _ADD_TEST_HPP_

#include "gtest/gtest.h"
#include "mock_class.hpp"
#include "add.hpp"
#include "op.hpp"

TEST(AddTest, AddEvaluateNonZero){
	Add* test = new Add(new Op(7.5), new Op(10.0));
	EXPECT_EQ(test->evaluate(), 17.5);
}

TEST(AddTest, AddEvaluateZero){
	Add* test = new Add(new Op(5.5), new Op(0.0));
	EXPECT_EQ(test->evaluate(),5.5);
}

TEST(AddTest, AddEvaluateDecimal){
	Add* test = new Add(new Op(7.5), new Op(10.0));
	EXPECT_EQ(test->evaluate(), 17.5);
}

TEST(AddTest, AddEvaluateNegative){
	Add* test = new Add(new Op(-10.0), new Op(5.5));
	EXPECT_EQ(test->evaluate(), -4.5);
}

TEST(AddTest, AddEvaluateTwoNegatives){
	Add* test = new Add(new Op(-3.0), new Op(-10.0));
	EXPECT_EQ(test->evaluate(), -13.0);
}

TEST(AddTest, AddStringifyNonZero){
	Add* test = new Add(new Op(5.5), new Op(10.0));
	EXPECT_EQ(test->stringify(), "5.500000 + 10.000000" );
}

TEST(AddTest, AddStringifyTwoNegatives){
	Add* test = new Add(new Op(-3.0), new Op(-10.0));
	EXPECT_EQ(test->stringify(), "-3.000000 + -10.000000");
}

#endif
