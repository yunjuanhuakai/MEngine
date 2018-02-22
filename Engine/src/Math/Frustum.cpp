#include "Math/Frustum.h"

namespace mk::math {

  void Frustum::Init(float fov, float aspect, float nearClip, float farClip) {
    this->Fov = fov;
    this->Aspect = aspect;
    this->Near = nearClip;
    this->Far = farClip;

    auto tenFovOver2 = tanf(Fov / 2);
    auto nearRight = (Near * tenFovOver2) * Aspect * global::Right;
    auto farRight = (Near * tenFovOver2) * Aspect * global::Right;
    auto nearUp = (Near * tenFovOver2) * Aspect * global::Up;
    auto farUp = (Near * tenFovOver2) * Aspect * global::Up;

    InitClip(this->NearClip, nearRight, nearUp, Near);
    InitClip(this->FarClip, farRight, farUp, Far);

    InitPlanes();
  }

  void Frustum::SetFov(float fov) {
    this->Fov = fov;
    this->Init(Fov, Aspect, Near, Far);
  }

  void Frustum::SetAspect(float aspect) {
    this->Aspect = aspect;
    this->Init(Fov, Aspect, Near, Far);
  }

  void Frustum::SetNear(float near) {
    this->Near = near;
    this->Init(Fov, Aspect, Near, Far);
  }

  void Frustum::SetFar(float far) {
    this->Far = far;
    this->Init(Fov, Aspect, Near, Far);
  }

  bool Frustum::Inside(vec3 const& points, float radius) const {
    for (auto const &plane : this->Planes) {
      if (!plane.Inside(points, radius)) {
        return false;
      }
    }
    return true;
  }

  Plane const& Frustum::operator[](Side side) const {
    return this->Planes[side];
  }

  void Frustum::InitClip(vec3 out[4], vec3 const& right, vec3 const& up, float clip) {
    out[0] = (clip * global::Forward) - right + up;
    out[1] = (clip * global::Forward) + right + up;
    out[2] = (clip * global::Forward) + right - up;
    out[3] = (clip * global::Forward) - right - up;
  }

  void Frustum::InitPlanes() {
    vec3 origin{ 0, 0, 0 };
    this->Planes[NearFlag].Init(this->NearClip[2], this->NearClip[1], this->NearClip[0]);
    this->Planes[FarFlag].Init(this->FarClip[0], this->FarClip[1], this->FarClip[2]);
    this->Planes[RightFlag].Init(this->FarClip[2], this->FarClip[1], origin);
    this->Planes[TopFlag].Init(this->FarClip[1], this->FarClip[0], origin);
    this->Planes[LeftFlag].Init(this->FarClip[0], this->FarClip[3], origin);
    this->Planes[BottomFlag].Init(this->FarClip[3], this->FarClip[2], origin);
  }

}