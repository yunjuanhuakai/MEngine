#pragma once

#include "Base/Base.h"
#include "Math/Matrix.h"
#include "SceneNodeProperties.h"

namespace mk::render {
  class Scene;

  using SceneNodePropertiesPtr = unique_ptr<SceneNodeProperties>;

  class ISceneNode : public enable_shared_from_this<ISceneNode> {
  protected:
    using SceneRef = Scene const&;
    using SelfPtr = shared_ptr<ISceneNode>;
  public:
    virtual ~ISceneNode() {}

    virtual SceneNodePropertiesPtr const &Get() const = 0;

    // 对该SceneNode进行变换，toWorld为世界空间变换，fromWorld为对象空间变换
    virtual void SetTransform(math::mat4 const& toWorld, std::optional<math::mat4> fromWorld = std::nullopt) = 0;

    virtual void Transform(math::mat4 *toWorld, math::mat4 *fromWorld) const = 0;

    virtual void OnUpdate(SceneRef scene) = 0;

    virtual void OnRestore(SceneRef scene) = 0;

    virtual bool PreRender(SceneRef scene) = 0;

    virtual bool IsVisible(SceneRef scene) = 0;

    virtual void Render(SceneRef scene) = 0;

    virtual void RenderChildren(SceneRef scene) = 0;

    virtual void PostRender(SceneRef scene) = 0;

    virtual bool AddChild(SelfPtr child) = 0;

    virtual bool RemoveChild(size_t ActorId) = 0;

    // 将该节点注册到对应场景图
    virtual bool Intall(SceneRef scene) = 0;

    // 将该节点从对应场景图删除
    virtual bool Uninstall(SceneRef scene) = 0;
  };

}
