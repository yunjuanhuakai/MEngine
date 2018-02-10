#pragma once

#include "Base/Base.h"
#include "Math/Matrix.h"
#include "SceneNodeProperties.h"

namespace mk::render {
  class Scene;

  using SceneNodePropertiesPtr = box<SceneNodeProperties>;

  class ISceneNode {
  protected:
    using SceneRef = Scene const&;
    using SelfPtr = arc<ISceneNode>;
  public:

    virtual ~ISceneNode() {}

    virtual SceneNodePropertiesPtr const &Get() const = 0;

    // �Ը�SceneNode���б任��toWorldΪ����ռ�任��fromWorldΪ����ռ�任
    virtual void SetTransform(math::mat4 const& toWorld, std::optional<math::mat4> fromWorld = std::nullopt) = 0;

    virtual void OnUpdate(SceneRef scene) = 0;

    virtual void OnRestore(SceneRef scene) = 0;

    virtual void PreRender(SceneRef scene) = 0;

    virtual bool IsVisible(SceneRef scene) = 0;

    virtual void Render(SceneRef scene) = 0;

    virtual void RenderChildren(SceneRef scene) = 0;

    virtual bool AddChild(SelfPtr child) = 0;

    virtual bool RemoveChild(size_t ActorId) = 0;
  };

}
