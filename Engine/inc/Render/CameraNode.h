#include "Base/Base.h"
#include "Render/SceneNode.h"
#include "Math/Frustum.h"

namespace mk ::render {
  class CameraNode : public SceneNode {
  public:
    CameraNode(math::mat4 &t, math::Frustum &frustum);

    virtual void OnRestore(Scene &scene);

    virtual void Render(Scene &scene);

    virtual bool IsVisible(Scene &scene);

    void SetView(Scene &scene);

  private:
    math::Frustum _Frustum;
    bool IsActive = true;
    bool IsDebug = false;
    SelfPtr Target;
    math::vec4 CamOffsetVector;
  };
}