#include "Math/Plane.h"

namespace mk::math {

  void Plane::Init(vec3 const& p0, vec3 const& p1, vec3 const& p2) {
    auto e2 = normalize(p2 - p0);
    auto e1 = normalize(p1 - p0);

    auto normal = normalize(cross(e1, e2));
    this->a = normal.x;
    this->b = normal.y;
    this->c = normal.z;
    this->d = -dot(normal, p0);
  }

  bool Plane::Inside(vec3 const& ponit, float radius) const {
    auto distance = this->Distance(ponit);
    return distance >= -radius; 
  }

  float Plane::Distance(vec3 const & point) const {
    return dot(vec3(a, b, c), point) + this->d;
  }

}