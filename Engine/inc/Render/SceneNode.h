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
              Color const &Diffuse,
              math::mat4 const &ToWorld,
              math::mat4 const *FromWorld = nullptr) {
      this->Props = std::make_unique<SceneNodeProperties>();
      this->Props->ActorId = ActorId;
      this->Props->Name = Name;
      this->Props->Pass = Pass;
      this->SetTransform(ToWorld, FromWorld);
      this->Props->Radius = 0;
      this->Props->_Material.SetDiffuse(Diffuse);
    }

    SceneNodePropertiesPtr const &Get() const override;

    void SetTransform(math::mat4 const &toWorld, math::mat4 const *fromWorld = nullptr) override;

    void OnUpdate(SceneRef scene) override;

    void OnRestore(SceneRef scene) override;

    bool PreRender(SceneRef scene) override;

    bool IsVisible(SceneRef scene) override;

    void Render(SceneRef scene) override;

    void PostRender(SceneRef scene) override;

    void RenderChildren(SceneRef scene) override;

    bool AddChild(SelfPtr child) override;

    bool RemoveChild(size_t ActorId) override;

    void Transform(math::mat4 *toWorld, math::mat4 *fromWorld) const override;

    bool Intall(SceneRef scene) override;

    bool Uninstall(SceneRef scene) override;
  };
}