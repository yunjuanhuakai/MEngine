#pragma once

#include <ostream>
#include "Render/SceneNode.h"

namespace mk::render {
  class RootNode : public SceneNode {
  public:
    RootNode();

    virtual void Render(Scene const &scene);

    virtual bool PreRender(Scene const &scene);

  private:
  };

}