#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "mock_class.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8.0);
    EXPECT_EQ(test->evaluate(), 8.0);
}

TEST(OpTest, OpEvaluateZero) {
    Op* test = new Op(0.0);
    EXPECT_EQ(test->evaluate(), 0.0);
}

TEST(OpTest, OpEvauluateDecimal) {
    Op* test = new Op(2.4);
    EXPECT_EQ(test->evaluate(), 2.4);
}

TEST(OpTest, OpEvaluateNegative) {
    Op* test = new Op(-3.5);
    EXPECT_EQ(test->evaluate(), -3.5);
}

TEST(OpTest, OpStringifyNonZero) {
    Op* test = new Op(8.0);
    EXPECT_EQ(test->stringify(), "8.000000");    
}

TEST(OpTest, OpStringifyZero) {
    Op* test = new Op(0.0);
    EXPECT_EQ(test->stringify(), "0.000000");
}

TEST(OpTest, OpStringifyDecimal) {
    Op* test = new Op(2.5);
    EXPECT_EQ(test->stringify(), "2.500000");
}

TEST(OpTest, OpStringifyNegative) {
    Op* test = new Op(-3.2);
    EXPECT_EQ(test->stringify(), "-3.200000");
}

#endif 
