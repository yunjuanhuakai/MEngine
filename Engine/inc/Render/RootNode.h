#pragma once

#include <ostream>
#include "Render/SceneNode.h"

namespace mk::render {
  class RootNode : public SceneNode {
  public:
    RootNode();

    virtual void Render(SceneRef scene);

    virtual bool IsVisible(Scene &scene);

    virtual void RenderChildren(Scene &scene);
  };
}