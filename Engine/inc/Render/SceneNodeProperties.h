#pragma once

#include "Base/Base.h"
#include "Math/Matrix.h"
#include "Material.h"
#include <string>

namespace mk ::render {
  class SceneNode;

  enum class RenderPass : int {
    Define,
    Static = static_cast<int>(Define),
    Actor,
    Sky,
    NotRendered,
    Last
  };

  struct SceneNodeProperties {
    friend class SceneNode;

  protected:
    size_t ActorId;
    std::string Name;
    math::mat4 ToWorld;
    math::mat4 FromWorld;
    /// TODO 一个SceneNode被简单的描述为一个包围球，这个是后面要做的事情
    float Radius;
    RenderPass Pass;
    Material _Material;
  public:
    size_t GetActorId() const { return this->ActorId; }

    math::mat4 const &GetToWorld() const {
      return this->ToWorld;
    }

    math::mat4 const &GetFromWorld() const {
      return this->FromWorld;
    }

    std::string const &GetName() const {
      return this->Name;
    }

    RenderPass GetPass() const {
      return this->Pass;
    }

    float const &GetRadius() const {
      return this->Radius;
    }

    Material const &GetMaterial() const {
      return this->_Material;
    }
  };

}
