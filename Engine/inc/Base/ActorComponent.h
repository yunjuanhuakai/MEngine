#pragma once

#include "Base/Base.h"

namespace mk {
  class Actor;

  class IActorComponent {
  public:
    virtual ~IActorComponent() {}

    virtual void PostInit() {}
    virtual void Update() {}

    virtual size_t GetId() const = 0;
  protected:
    shared_ptr<Actor> Owner;
  };

}