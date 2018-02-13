#include <gtest/gtest.h>
#include "Math/Frustum.h"

using namespace mk;
using namespace mk::math;

int add_(int l, int r) {
  return l + r;
}

TEST(FrustumTest, Init)
{
  EXPECT_EQ(2, add_(2, 0));
  EXPECT_EQ(6, add_(3, 3));
}