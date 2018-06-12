#include "Render/RootNode.h"
#include "Render/Scene.h"
#include "Render/CameraNode.h"
#include "Render/LightManager.h"

namespace mk ::render {

  RootNode::RootNode()
      : SceneNode(0, "Root", RenderPass::Define, global::Transparent, math::mat4()) {
    Children.reserve(4);

    auto staticGroup = std::make_shared<SceneNode>(
        0, "StaticGroup", RenderPass::Static, global::White, math::mat4());
    Children.push_back(staticGroup);

    auto actorGroup = std::make_shared<SceneNode>(
        0, "ActorGroup", RenderPass::Actor, global::White, math::mat4());
    Children.push_back(actorGroup);

    auto skyGroup = std::make_shared<SceneNode>(
        0, "SkyGroup", RenderPass::Sky, global::White, math::mat4());
    Children.push_back(skyGroup);

    auto invisibleGroup = std::make_shared<SceneNode>(
        0, "InvisibleGroup", RenderPass::NotRendered, global::White, math::mat4());
    Children.push_back(invisibleGroup);
  }

  void RootNode::Render(SceneRef scene) {
    SceneNode::Render(scene);
  }

  bool RootNode::IsVisible(Scene &scene) {
    return SceneNode::IsVisible(scene);
  }

  void RootNode::RenderChildren(Scene &scene) {
    for (auto node : Children) {

    }
  }
}