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

  class Scene {
  protected:
    using SceneActorMap = std::map<size_t, ISceneNode>;

    shared_ptr<ISceneNode> Root;
    shared_ptr<CameraNode> Camera;
    std::stack<math::mat4> MatrixStack;
    SceneActorMap ActorMap;
    // LightMangaer 
    
  public:
    Scene();

    virtual ~Scene() {}

    void OnReader();
    void OnRestore();
    void OnLostDevice();
    void OnUpdate();

    bool Add(size_t ActorId, shared_ptr<ISceneNode> node);
    bool Remove(size_t ActorId);
  };

}