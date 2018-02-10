#pragma once

#include "Matrix.h"

namespace mk::math {

  struct Plane {
    float a, b, c, d;

    Plane() = default;

    void Init(vec3 const& p0, vec3 const& p1, vec3 const& p2);

    bool Inside(vec3 const& ponit, float radius = 0.0f) const;

  };

}
