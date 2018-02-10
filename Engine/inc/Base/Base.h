#pragma once

#define USE_GLM

#include <memory>
#include <optional>
#include <type_traits>

namespace mk {
  template <typename T>
  using arc = std::shared_ptr<T>;

  template <typename T>
  using box = std::unique_ptr<T>;

  template <typename T>
  using weak = std::weak_ptr<T>;

  constexpr double PI = 3.14159265358979323846;

}