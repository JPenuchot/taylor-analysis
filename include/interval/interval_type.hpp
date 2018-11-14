#pragma once

#include <ostream>
#include <tuple>

#include "support.hpp"

/**
 * @brief      Basic polymorphic type for intervals
 *
 * @tparam     T     Type of the bounds
 */
template<typename T>
struct interval
{
  T l, r;
};

template<typename T>
interval(const T&, const T&) -> interval<T>;

template<typename T>
inline interval<T> make_interval(const std::tuple<T, T> tp)
{
  return interval<T>{ std::get<0>(tp), std::get<1>(tp) };
}

/**
 * @brief      Output stream << operator for printing.
 *
 * @param      os    The output stream
 * @param[in]  i     The interval
 *
 * @tparam     T     Type of the interval's bounds
 *
 * @return     Reference to the modified output stream.
 */
template<typename T>
std::ostream& operator << (std::ostream& os, const interval<T>& i)
{
  const auto& [l, r] = i;
  os << '(' << l << ", " << r << ')';
  return os;
}
