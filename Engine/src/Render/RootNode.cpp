#include "Render/RootNode.h"
#include "Render/Scene.h"
#include "Render/CameraNode.h"
#include "Render/LightManager.h"

namespace mk ::render {

  RootNode::RootNode()
      : SceneNode(0, "Root", RenderPass::Define, global::Transparent, math::mat4())
      , staticGroup{0, "StaticGroup", RenderPass::Static, global::White, math::mat4()}
      , actorGroup{0, "ActorGroup", RenderPass::Actor, global::White, math::mat4()}
      , skyGroup{0, "SkyGroup", RenderPass::Sky, global::White, math::mat4()}
      , invisibleGroup{0, "InvisibleGroup", RenderPass::NotRendered, global::White, math::mat4()} {
  }

  void RootNode::Render(Scene &scene) {
    SceneNode::Render(scene);
  }

  bool RootNode::IsVisible(Scene &scene) {
    return true;
  }

  void RootNode::RenderChildren(Scene &scene) {
    staticGroup.RenderChildren(scene);
    actorGroup.RenderChildren(scene);
    skyGroup.RenderChildren(scene);
    invisibleGroup.RenderChildren(scene);
  }

  bool RootNode::AddChild(ISceneNode::SelfPtr child) {
    switch (child.->Get()->GetPass()) {
      case RenderPass::Define:
        return staticGroup.AddChild(child);
      case RenderPass::Actor:
        return actorGroup.AddChild(child);
      case RenderPass::Sky:
        return skyGroup.AddChild(child);
      case RenderPass::NotRendered:
        invisibleGroup.AddChild(child);
      default:
        assert("add error node to RootNode");
        return false;
    }
  }
}