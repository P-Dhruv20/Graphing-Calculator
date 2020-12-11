#ifndef _FACT_TEST_HPP_
#define _FACT_TEST_HPP_

#include "gtest/gtest.h"
#include "fact.hpp"
#include "op.hpp"

TEST(FactTest, FactEvaluateNonZero){
	Fact* test = new Fact(new Op(3));
	EXPECT_EQ(test->evaluateInt(), 6);
}

TEST(FactTest, FactEvaluateZero){
	Fact* test = new Fact(new Op(0));
	EXPECT_EQ(test->evaluateInt(), 1);
}

TEST(FactTest, FactEvaluateNegative){
	Fact* test = new Fact(new Op(-10));
	EXPECT_EQ(test->evaluateInt(), 1);
}

TEST(FactTest, FactEvaluateLargeNumber){
	Fact* test = new Fact(new Op(9));
	EXPECT_EQ(test->evaluateInt(), 362880);
}

TEST(FactTest, FactStringifyNonZero){
	Fact* test = new Fact(new Op(25));
	EXPECT_EQ(test->stringifyInt(), "25 !" );
}

#endif


