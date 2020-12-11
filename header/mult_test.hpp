#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"
#include "mock_class.hpp"
#include "mult.hpp"

TEST(MultTest, MultEvaluateNonZero) {
    Mult* test = new Mult(new Op(7.5), new Op(10.0));
    EXPECT_EQ(test->evaluate(), 75);
}

TEST(MultTest, MultEvaluateZero) {
    Mult* test = new Mult(new Op(5.5), new Op(0.0));
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(MultTest, MultEvaluateDecimal) {
    Mult* test = new Mult(new Op(7.5), new Op(5.5));
    EXPECT_EQ(test->evaluate(), 41.25);
}

TEST(MultTest, MultEvaluateNegative) {
    Mult* test = new Mult(new Op(-3.0), new Op(5.5));
    EXPECT_EQ(test->evaluate(), -16.5);
}

TEST(MultTest, MultEvaluateTwoNegatives) {
    Mult* test = new Mult(new Op(-3.0), new Op(-10.0));
    EXPECT_EQ(test->evaluate(), 30);
}

TEST(MultTest, MultStringifyNonZero) {
    Mult* test = new Mult(new Op(5.5), new Op(7.5));
    EXPECT_EQ(test->stringify(), "5.500000 * 7.500000");
}

TEST(MultTest, MultStringifyZero) {
    Mult* test = new Mult(new Op(0.0), new Op(7.5));
    EXPECT_EQ(test->stringify(), "0.000000 * 7.500000");
}

TEST(MultTest, MultStringifyTwoNegatives) {
    Mult* test = new Mult(new Op(-10.0), new Op(-3.0));
    EXPECT_EQ(test->stringify(), "-10.000000 * -3.000000");
}

TEST(MultTest, MultStringifyNegative) {
    Mult* test = new Mult(new Op(-10.0), new Op(7.5));
    EXPECT_EQ(test->stringify(), "-10.000000 * 7.500000");
}

#endif
