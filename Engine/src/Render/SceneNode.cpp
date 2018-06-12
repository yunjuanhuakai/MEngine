#include "Render/SceneNode.h"
#include "Render/Scene.h"
#include "Math/Plane.h"
#include <variant>

namespace mk::render {

  SceneNodePropertiesPtr const &SceneNode::Get() const {
    return this->Props;
  }

  void SceneNode::SetTransform(math::mat4 const &toWorld, const glm::mat4 *fromWorld) {
    auto [a, b, c, d] = math::Plane{};
    this->Props->ToWorld = toWorld;
    if (!fromWorld) {
      this->Props->FromWorld = math::inverse(toWorld);
    } else {
      this->Props->FromWorld = *fromWorld;
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

  bool SceneNode::PreRender(SceneRef scene) {
    scene.PushMatrix(Get()->ToWorld);
    return true;
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
    scene.PushMatrix(Get()->ToWorld);
  }

  void SceneNode::RenderChildren(SceneRef scene) {
    for (auto &node : this->Children) {
      // TODO 也许需要校验初始化渲染的返回值？
      node->PreRender(scene);
      if (node->IsVisible(scene)) {
        // TODO 需要一个渲染通道，但我不认为应该在这里实现与渲染顺序相关的内容，到时候再说
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
    *fromWorld = this->Get()->FromWorld;
  }

  bool SceneNode::Intall(SceneRef scene) {
    // TODO
    return false;
  }

  bool SceneNode::Uninstall(SceneRef scene) {
    // TODO 
    return false;
  }
}