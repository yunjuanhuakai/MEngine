#pragma once

#include "Base/Base.h"
#include <vector>

namespace mk {

  class IActorComponent;

  class Actor {
    using ActorComponents = std::vector<shared_ptr<IActorComponent>>;

    size_t _ActorId;
    ActorComponents _ActorComponents;
  public:
    explicit Actor(size_t ActorId)
      : _ActorId(ActorId) {}

    ~Actor();

    void PostInit();
    void Destory();
    void Update();

    inline size_t ActorId() const { return this->_ActorId; }

    template <typename ComponentType>
    weak_ptr<ComponentType> GetComponent(size_t ComponentId) const {
      if (ComponentId >= this->_ActorComponents.size()) {
        return weak<ComponentType>();
      }

      auto sub = std::static_pointer_cast<ComponentType>(
        this->_ActorComponents[ComponentId]);
      return weak<ComponentType>(sub);
    }
  };

}