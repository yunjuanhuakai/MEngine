#pragma once

#include "Base/Base.h"

#ifdef USE_GLM
#include <glm/glm.hpp>
#include <glm/gtc/random.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#endif // USE_GLM

namespace mk::math {
#ifdef USE_GLM
  using glm::vec2;
  using glm::vec3;
  using glm::vec4;

  using glm::mat2;
  using glm::mat3;
  using glm::mat4;

  using glm::quat;

  using glm::translate;
  using glm::rotate;
  using glm::scale;
  using glm::perspective;
  using glm::normalize;

  using glm::inverse;
  using glm::dot;
  using glm::cross;
  using glm::distance;

  using glm::ballRand;

  using glm::to_string;
  using glm::length;

  inline vec4 position(mat4 const& m) {
    return vec4(m[0][3], m[1][3], m[2][3], 1);
  }
#endif
  namespace global {
    inline vec3 Right{ 1, 0, 0 };
    inline vec3 Up{ 0, 1, 0 };
    inline vec3 Forward{ 0, 0, 1 };

    inline vec4 Right4{ 1, 0, 0, 0 };
    inline vec4 Up4{ 0, 1, 0, 0 };
    inline vec4 Forward4{ 0, 0, 1, 0 };
  }
}