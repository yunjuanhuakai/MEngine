#include "Render/RootNode.h"
#include "Render/Scene.h"
#include "Render/CameraNode.h"
#include "Render/LightManager.h"

namespace mk :: render {

  bool RootNode::PreRender(Scene const &scene) {
    return SceneNode::PreRender(scene);
  }

  void RootNode::Render(Scene const &scene) {
    SceneNode::Render(scene);
  }
}