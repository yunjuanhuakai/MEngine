#pragma once

#include "Render/SceneNode.h"

namespace mk::render {
  class RootNode : public SceneNode {
  public:
    RootNode();

    virtual ~RootNode() override;

  private:
  };

}