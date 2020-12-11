#include "gtest/gtest.h"
#include "header/op_test.hpp"
#include "header/rand_test.hpp"
#include "header/mult_test.hpp"
#include "header/div_test.hpp"
#include "header/pow_test.hpp"
#include "header/add_test.hpp"
#include "header/sub_test.hpp"
#include "header/sin_test.hpp"
#include "header/cos_test.hpp"
#include "header/tan_test.hpp"
#include "header/shunting_yard_test.hpp"
#include "header/validation_unit_tests.hpp"
TEST(MultTest, MultEvaluateWithSubclass) {
    Add* add = new Add(new Op(3.0), new Op(7.0));
    Sub* sub = new Sub(new Op(5.0), new Op(1.0));
    Mult* test = new Mult(add, sub);

    EXPECT_EQ(test->evaluate(), 40.0);
}

TEST(DivTest, DivEvaluateWithSubclass) {
    Add* add = new Add(new Op(3.0), new Op(7.0));
    Sub* sub = new Sub(new Op(10.0), new Op(5.0));
    Div* test = new Div(add, sub);

    EXPECT_EQ(test->evaluate(), 2.0);
}

TEST(SubTest, SubEvaluateWithSubclass) {
    Mult* mult = new Mult(new Op(2.0), new Op(5.0));
    Div* div = new Div(new Op(10.0), new Op(2.0));
    Sub* test = new Sub(mult, div);

    EXPECT_EQ(test->evaluate(), 5.0);
}

TEST(PowTest, PowEvaluateWithSubclass) {
    Add* add = new Add(new Op(1.0), new Op(4.0));
    Sub* sub = new Sub(new Op(5.0), new Op(3.0));
    Pow* test = new Pow(add, sub);

    EXPECT_EQ(test->evaluate(), 25.0);
}

TEST(AddTest, AddEvaluateWithSubclass) {
    Mult* mult = new Mult(new Op(2.0), new Op(5.0));
    Div* div = new Div(new Op(10.0), new Op(2.0));
    Add* test = new Add(mult, div);

    EXPECT_EQ(test->evaluate(), 15.0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
