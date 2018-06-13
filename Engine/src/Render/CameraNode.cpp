
#include "Render/CameraNode.h"

namespace mk ::render {


  CameraNode::CameraNode(math::mat4 &t, math::Frustum &frustum)
      : SceneNode(0, "Camera", RenderPass::Define, global::Black, t)
      , _Frustum{frustum}
      , Target{std::make_shared<SceneNode>()}
      , CamOffsetVector{0.0f, 1.0f, -10.0f, 0.0f} {}

  void CameraNode::SetTransform(math::mat4 const &toWorld, glm::mat4 const *fromWorld) {
    SceneNode::SetTransform(toWorld, fromWorld);
  }

  void CameraNode::OnRestore(Scene &scene) {
    // TODO this->_Frustum.SetAspect(wisth / height);
    //
  }

  void CameraNode::Render(Scene &scene) {
    if (this->IsDebug) {
      // TODO this->_Frustum.Render();
    }
  }

  bool CameraNode::IsVisible(Scene &scene) {
    return this->IsActive;
  }

  void CameraNode::SetView(Scene &scene) {
    if (Target) {
      decltype(auto) toWorld = Target->Get()->GetToWorld();
      math::vec4 atWorld = toWorld * this->CamOffsetVector;
      math::vec4 pos = math::position(toWorld) + atWorld;
      auto mat = math::set_position(toWorld, pos);
      this->SetTransform(mat);
    }
  }
}