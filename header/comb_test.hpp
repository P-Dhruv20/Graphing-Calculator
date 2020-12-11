#ifndef _COMB_TEST_HPP_
#define _COMB_TEST_HPP_

#include "gtest/gtest.h"
#include "mock_class.hpp"
#include "comb.hpp"
#include "op.hpp"
#include "base.hpp"

TEST(CombTest, CombEvaluateNonZero){
	Comb* test = new Comb(new Op(2), new Op(1));
	EXPECT_EQ(test->evaluateInt(), 2);
}

TEST(CombTest, CombEvaluateZero){
	Comb* test = new Comb(new Op(5), new Op(0));
	EXPECT_EQ(test->evaluateInt(), 1);
}

TEST(CombTest, CombEvaluateNegative){
	Comb* test = new Comb(new Op(-10), new Op(0));
	EXPECT_EQ(test->evaluateInt(), 1);
}

TEST(CombTest, CombEvaluateTwoNegatives){
	Comb* test = new Comb(new Op(-3), new Op(-10));
	EXPECT_EQ(test->evaluateInt(), 1);
}

TEST(CombTest, CombStringifyNonZero){
	Comb* test = new Comb(new Op(10), new Op(5));
	EXPECT_EQ(test->stringifyInt(), "10 C 5" );
}

#endif
