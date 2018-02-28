#include "Render/Scene.h"
#include "Render/ISceneNode.h"
#include "Render/RootNode.h"
#include "Render/LightManager.h"

namespace mk::render {

  Scene::Scene() 
    : Root(new RootNode)
    , LightManagerPtr(new LightManager)
  {}

  void Scene::OnRender() {
    if (this->Camera) {
      // TODO Camera->SetViewTransform(*this);
      // TODO LightManager->CalcLighting(*this);

      if (Root->PreRender(*this)) {
        Root->Render(*this);
        Root->RenderChildren(*this);
        Root->PostRender(*this);
      }
    }
  }

  void Scene::OnRestore() {
    Root->OnRestore(*this);
  }

  void Scene::OnUpdate() {
    Root->OnUpdate(*this);
  }

  bool Scene::Add(shared_ptr<ISceneNode> node) {
    return node ? node->Intall(*this) : false;
  }

  bool Scene::Remove(size_t ActorId) {
    auto node = this->FindByActorId(ActorId);
    return node ? node->Uninstall(*this) : false;
  }

  void Scene::PushMatrix(math::mat4 const & m) {}

  shared_ptr<ISceneNode> Scene::FindByActorId(size_t ActorId) {
    auto iter = this->ActorMap.find(ActorId);
    if (iter != std::end(this->ActorMap)) {
      return iter->second;
    }
    return nullptr;
  }

}