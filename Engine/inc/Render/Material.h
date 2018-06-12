#pragma once

#include "Math/Matrix.h"

namespace mk::render {
  using Color = math::vec4;
  namespace global {
    inline Color White{1, 1, 1, 1};
    inline Color Black{0, 0, 0, 1};
    inline Color Cyan{0, 1, 1, 1};
    inline Color Red{1, 0, 0, 1};
    inline Color Green{0, 1, 0, 1};
    inline Color Blue{0, 0, 1, 1};
    inline Color Yellow{1, 1, 0, 1};
    inline Color Gray40{0.4, 0.4, 0.4, 1};
    inline Color Gray25{0.25, 0.25, 0.25, 1};
    inline Color Gray65{0.65, 0.65, 0.65, 1};
    inline Color Transparent{1, 1, 1, 0};
  }

  struct Material {
  private:
    Color Diffuse;
    Color Ambient;
    Color Specular;
    Color Emissive;
    float Power;
  public:
    Material() :
        Diffuse(global::White),
        Ambient(Color(0.1, 0.1, 0.1, 1)),
        Specular(global::White),
        Emissive(global::Black) {}

    void SetDiffuse(Color const &Diffuse) {
      this->Diffuse = Diffuse;
    }

    void SetAmbient(Color const &Ambient) {
      this->Ambient = Ambient;
    }

    void SetSpecular(Color const &Specular, float Power) {
      this->Specular = Specular;
      this->Power = Power;
    }

    void SetEmissive(Color const &Emissive) {
      this->Emissive = Emissive;
    }

    Color const &GetDiffuse() const {
      return this->Diffuse;
    }

    Color const &GetAmbient() const {
      return this->Ambient;
    }

    Color const &GetSpecular() const {
      return this->Specular;
    }

    Color const &GetEmissive() const {
      return this->Emissive;
    }

    float GetPower() const {
      return this->Power;
    }
  };

}