#pragma once
#include "Plane.h"

namespace mk::math {

  struct Frustum {
    enum Side { NearFlag = 0, FarFlag, TopFlag, RightFlag, BottomFlag, LeftFlag };

    Plane Planes[6];
    vec3 NearClip[4];
    vec3 FarClip[4];
    float Fov, Aspect, Near, Far;

    void Init(float fov, float aspect, float nearClip, float farClip);
    void SetFov(float fov);
    void SetAspect(float aspect);
    void SetNear(float near);
    void SetFar(float far);
    bool Inside(vec3 const & points, float radius) const;

    Plane const& operator[](Side side) const;

  private:
    void InitClip(vec3 out[], vec3 const& right, vec3 const& up, float clip);
    void InitPlanes();
  };

}