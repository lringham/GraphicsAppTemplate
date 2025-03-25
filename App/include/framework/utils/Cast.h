#pragma once

#include <utility>

namespace framework {

template <class O, class I>
constexpr auto as(I &&value) -> O {
  return static_cast<O>(std::forward<I>(value));
}
}  // namespace framework
