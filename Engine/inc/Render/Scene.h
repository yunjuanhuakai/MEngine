#pragma once

#include "Base/Base.h"
#include "Math/Matrix.h"
#include <stack>
#include <map>

namespace mk::render {
  class ISceneNode;
  class CameraNode;
  class SkyNode;
  class LightNode;
  class LightManager;

  class MatrixStack {
  private:
    std::stack<math::mat4> Stack;
  public:
  };

  class Scene {
  protected:
    friend class ISceneNode;

    using SceneActorMap = std::map<size_t, shared_ptr<ISceneNode>>;

    unique_ptr<ISceneNode> Root;
    shared_ptr<CameraNode> Camera;
    std::stack<math::mat4> MatrixStack;
    SceneActorMap ActorMap;
    unique_ptr<LightManager> LightManagerPtr;
    
  public:
    Scene();

    virtual ~Scene();

    void OnRender();
    void OnRestore();
    void OnLostDevice();
    void OnUpdate();

    bool Add(shared_ptr<ISceneNode> node);
    bool Remove(size_t ActorId);

    void PushMatrix(math::mat4 const& m);
    void PopMatrix();

    std::optional<math::mat4> GetToWorld() const;

    LightManager& GetLightManager();
    ISceneNode& GetRoot();

    shared_ptr<CameraNode> const GetCamera() const;
    void SetCamera(shared_ptr<CameraNode> Camera);

  private:

    shared_ptr<ISceneNode> FindByActorId(size_t ActorId);
  };

}