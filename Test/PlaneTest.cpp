#include <gtest/gtest.h>
#include "Math/Plane.h"

using namespace mk;
using namespace mk::math;

template<typename OutStream>
OutStream &operator<<(OutStream &out, Plane const &plane) {
  out << "Plane[" << plane.a << ' ' << plane.b << ' ' << plane.c << ' ' << plane.d << ']';
  return out;
}

TEST(PlaneTest, ZPlane) {
  Plane zPlane{};
  zPlane.Init(vec3(0, 1, 0), vec3(1, 1, 0), vec3(1, 0, 0));
  for (int i = 0; i != 10000; ++i) {
    auto randPoint = ballRand(1.0f);
    if (abs(zPlane.Distance(randPoint)) < 0.001) {
      ASSERT_TRUE(randPoint.z < 0.001) << "error point = " << to_string(randPoint) << ", plane = " << zPlane;
    }
  }
}

TEST(PlaneTest, Random) {
  Plane plane{};
  auto p0 = ballRand(1.0f), p1 = ballRand(1.0f), p2 = ballRand(1.0f);
  int count = 0;
  for (int i = 0; i != 10000; ++i) {
    auto randPoint = ballRand(1.0f);
    plane.Init(p0, p1, p2);
    // 当点在面上的时候，跳过测试
    if (abs(plane.Distance(randPoint)) < 0.001) {
      ++count;
      continue;
    }
    auto isInside = plane.Inside(randPoint);
    plane.Init(p1, p0, p2);
    ASSERT_NE(plane.Inside(randPoint), isInside) << "顺序相反情况下结果一致，plane = " << plane << ", point = " << to_string(randPoint);
    plane.Init(p2, p0, p1);
    ASSERT_EQ(plane.Inside(randPoint), isInside) << "顺序相同的情况下结果不一致, plane = " << plane << ", point = " << to_string(randPoint);
  }
  ASSERT_NE(count, 1000) << "全部都在面上";
}