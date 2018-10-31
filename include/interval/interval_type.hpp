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
inline interval<T> make_interval(const T& a, const T& b)
{
  return interval<T>{a, b};
}

template<typename T>
inline interval<T> make_interval(const std::tuple<T, T> tp)
{
  return interval<T>{ std::get<0>(tp), std::get<1>(tp) };
}

template<typename T>
inline std::tuple<T&, T&> as_ref_tuple(interval<T>& i)
{
  return std::tie(i.l, i.r);
}

template<typename T>
inline std::tuple<T, T> as_val_tuple(const interval<T>& i)
{
  return std::tuple(i.l, i.r);
}

template<typename T>
inline std::tuple<const T&, const T&> as_const_ref_tuple(const interval<T>& i)
{
  return const_tie(i.l, i.r);
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
  const auto& [l, r] = as_const_ref_tuple(i);
  os << '(' << l << ", " << r << ')';
  return os;
}
