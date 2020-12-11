#ifndef _PERM_TEST_HPP_
#define _PERM_TEST_HPP_

#include "gtest/gtest.h"
#include "../header/mock_class.hpp"
#include "../header/perm.hpp"
#include "../header/op.hpp"

TEST(PermTest, PermEvaluateNonZero){
	Perm* test = new Perm(new Op(2), new Op(1));
	EXPECT_EQ(test->evaluateInt(), 2);
}

TEST(PermTest, PermEvaluateZeroOp2){
	Perm* test = new Perm(new Op(5), new Op(0));
	EXPECT_EQ(test->evaluateInt(), 1);
}

TEST(PermTest, PermEvaluateNegative){
	Perm* test = new Perm(new Op(-10), new Op(0));
	EXPECT_EQ(test->evaluateInt(), 1);
}

TEST(PermTest, PermEvaluateTwoNegatives){
	Perm* test = new Perm(new Op(-3), new Op(-10));
	EXPECT_EQ(test->evaluateInt(), 1);
}

TEST(PermTest, PermEvaluateZeroOp1){
	Perm* test = new Perm(new Op(0), new Op(0));
	EXPECT_EQ(test->evaluateInt(), 1);
}

TEST(PermTest, PermEvaluateGreaterOp2){
	Perm* test = new Perm(new Op(10), new Op(15));
	EXPECT_EQ(test->evaluateInt(), 1);
}

TEST(PermTest, PermStringifyNonZero){
	Perm* test = new Perm(new Op(10), new Op(5));
	EXPECT_EQ(test->stringifyInt(), "10 P 5" );
}

#endif

