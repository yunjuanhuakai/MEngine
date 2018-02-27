#include "Render/Scene.h"
#include "Render/ISceneNode.h"

namespace mk::render {
  bool Scene::Add(shared_ptr<ISceneNode> node) {
    return node ? node->Intall(*this) : false;
  }

  bool Scene::Remove(size_t ActorId) {
    auto node = this->FindByActorId(ActorId);
    return node ? node->Uninstall(*this) : false;
  }

  shared_ptr<ISceneNode> Scene::FindByActorId(size_t ActorId) {
    auto iter = this->ActorMap.find(ActorId);
    if (iter != std::end(this->ActorMap)) {
      return iter->second;
    }
    return nullptr;
  }

}