#include "Render/SceneNode.h"

namespace mk::render {
  SceneNodePropertiesPtr const& SceneNode::Get() const {
    return this->Props;
  }

  void SceneNode::SetTransform(math::mat4 const& toWorld, std::optional<math::mat4> fromWorld) {
    this->Props->ToWorld = toWorld;
    if (!fromWorld) {
      this->Props->FromWorld = math::inverse(toWorld);
    } else {
      this->Props->FromWorld = fromWorld.value();
    }
  }

  void SceneNode::OnUpdate(SceneRef scene) {
    for (auto &child : this->Children) {
      child->OnUpdate(scene);
    }
  }

  void SceneNode::OnRestore(SceneRef scene) {
    for (auto &child : this->Children) {
      child->OnRestore(scene);
    }
  }

  void SceneNode::PreRender(SceneRef scene) {
    // TODO scene.PushAndSetMatrix(this->Props->ToWorld);
  }

  // 包围球的可见性即是否在摄像机的视锥之内
  bool SceneNode::IsVisible(SceneRef scene) {
    math::mat4 toWorld, fromWorld;
    // TODO scene->GetCamera()->Get()->Transform(&toWorld, &fromWorld);

    auto pos = math::position(this->Get()->ToWorld);
    pos = fromWorld * pos;

    // TODO decltype(auto) frustum = scene->GetCamera()->GetFrustum();
    // TODO return frustum.Inside(pos, this->Get()->Radius)
    return false;
  }

  void SceneNode::Render(SceneRef scene) {}

  void SceneNode::PostRender(SceneRef scene) {
  }

  void SceneNode::RenderChildren(SceneRef scene) {
    for (auto &node : this->Children) {
      // TODO 也许需要校验初始化渲染的返回值？
      node->PreRender(scene);
      if (node->IsVisible(scene)) {
        // 这里GCC说需要一个特殊的透明渲染通道，暂时不理解意义，先不给
        node->Render(scene);
        node->RenderChildren(scene);
      }
      node->PostRender(scene);
    }
  }

  // TODO 依旧是包围球的问题
  bool SceneNode::AddChild(SelfPtr child) {
    Children.push_back(child);
    auto childPos = math::position(child->Get()->ToWorld);
    auto dir = childPos - math::position(this->Get()->ToWorld);
    auto newRadius = math::length(dir) + child->Get()->Radius;
    if (newRadius > this->Get()->Radius) {
      this->Props->Radius = newRadius;
    }
    return false;
  }

  bool SceneNode::RemoveChild(size_t ActorId) {
    return false;
  }

  void SceneNode::Transform(math::mat4 *toWorld, math::mat4 *fromWorld) const {
    *toWorld = this->Get()->ToWorld;
  }
}