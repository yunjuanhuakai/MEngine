#pragma once

#include "Base/Base.h"
#include "Math/Matrix.h"
#include "Material.h"
#include <string>

namespace mk :: render {
  class SceneNode;

  enum class RenderPass {
    Define,
    Static = Define, 
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
    float Radius;
    RenderPass Pass;
    Material _Material;
  public:
    size_t GetActorId() const { return this->ActorId; }

    math::mat4 const& GetToWorld() const {
      return this->ToWorld;
    }

    math::mat4 const& GetFromWorld() const {
      return this->FromWorld;
    }

    std::string const& GetName() const {
      return this->Name;
    }

    RenderPass GetPass() const {
      return this->Pass;
    }

    float const& GetRadius() const {
      return this->Radius;
    }

    Material const& GetMaterial() const {
      return this->_Material;
    }
  };

}
