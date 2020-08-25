#include "gtest/gtest.h"
#include "Trunc_test.hpp"
#include "Paren_test.hpp"
#include "ceil_test.hpp"
#include "floor_test.hpp"
#include "abs_test.hpp"
#include "int_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
