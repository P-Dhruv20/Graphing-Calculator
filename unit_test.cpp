#include "gtest/gtest.h"
#include <iostream>
#include "src/base.cpp"
#include "src/sub.cpp"
#include "src/add.cpp"
#include "src/eval.cpp"
#include "src/mult.cpp"
#include "src/div.cpp"
#include "src/op.cpp"
#include "src/trig.cpp"
#include "src/pow.cpp"
#include "src/operator.cpp"
#include "src/rand.cpp"
#include <queue>
#include "shunting_yard_test.h"
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
