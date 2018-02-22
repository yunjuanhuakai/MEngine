#pragma once

#include "ISceneNode.h"
#include <vector>

namespace mk::render {
  class SceneNode : public ISceneNode {
  protected:
    using SceneNodeList = std::vector<SelfPtr>;

    SceneNodeList Children;
    SelfPtr Parent;
    SceneNodePropertiesPtr Props;
  public:
    SceneNode(size_t ActorId,
      std::string const &Name,
      RenderPass Pass,
      Color const& Diffuse,
      math::mat4 const &ToWorld,
      std::optional<math::mat4> FromWorld = std::nullopt) {
      this->Props = std::make_unique<SceneNodeProperties>();
      this->Props->ActorId = ActorId;
      this->Props->Name = Name;
      this->Props->Pass = Pass;
      this->SetTransform(ToWorld, FromWorld);
      this->Props->Radius = 0;
      this->Props->_Material.SetDiffuse(Diffuse);
    }

    virtual SceneNodePropertiesPtr const& Get() const override;

    virtual void SetTransform(math::mat4 const& toWorld, std::optional<math::mat4> fromWorld = std::nullopt) override;

    virtual void OnUpdate(SceneRef scene) override;

    virtual void OnRestore(SceneRef scene) override;

    virtual void PreRender(SceneRef scene) override;

    virtual bool IsVisible(SceneRef scene) override;

    virtual void Render(SceneRef scene) override;

    virtual void PostRender(SceneRef scene) override;

    virtual void RenderChildren(SceneRef scene) override;

    virtual bool AddChild(SelfPtr child) override;

    virtual bool RemoveChild(size_t ActorId) override;

    virtual void Transform(math::mat4 *toWorld, math::mat4 *fromWorld) const override;
  };
}