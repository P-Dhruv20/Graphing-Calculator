#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include "gtest/gtest.h"
#include "rand.hpp"

TEST(RandTest, RandEvaluateBelowHundred) {
    Rand* test = new Rand();
    EXPECT_LT(test->evaluate(), 100);
}

TEST(RandTest, RandEvaluateIsPositive) {
    Rand* test = new Rand();
    EXPECT_LT(-1, test->evaluate());
}

TEST(RandTest, RandStringify) {
    Rand* test = new Rand();
    EXPECT_EQ(typeid(std::string), typeid(test->stringify()));
}

#endif
