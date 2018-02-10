#include "Render/SceneNode.h"
#include <algorithm>

namespace mk::render {
  SceneNodePropertiesPtr const& SceneNode::Get() const {
    return this->Props;
  }

  void SceneNode::SetTransform(math::mat4 const & toWorld, std::optional<math::mat4> fromWorld) {
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

  bool SceneNode::IsVisible(SceneRef scene) {
    math::mat4 toWorld, fromWorld;
    // TODO scene->GetCamera()->Get()->Transform(&toWorld, &fromWorld);
    this->Get()->ToWorld;
    return false;
  }

  void SceneNode::Render(SceneRef scene) {}
  void SceneNode::RenderChildren(SceneRef scene) {}
  bool SceneNode::AddChild(SelfPtr child) {
    return false;
  }
  bool SceneNode::RemoveChild(size_t ActorId) {
    return false;
  }
}