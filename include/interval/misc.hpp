#pragma once

#include "interval_type.hpp"

template<typename T>
bool is_in(const interval<T>& i, const T& x)
{
  const auto& [l, r] = i;
  return l <= x && x <= r;
}
