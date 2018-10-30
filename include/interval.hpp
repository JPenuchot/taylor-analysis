/**
 * Implementation of algebra on intervals
 */

#pragma once

#include <ostream>
#include <tuple>

#include "support.hpp"

/**
 * @brief      Polymorphic type for intervals.
 *
 * @tparam     T     Type of a boundary
 *
 * @note       This type inherits from tuple instead of being an alias to avoid
 * overloading std::tuple's existing operators across client code.
 */
template<typename T>
struct interval
{
  T l, r;
};

template<typename T>
interval<T> make_interval(const T& a, const T& b)
{
  return interval<T>{a, b};
}

template<typename T>
interval<T> make_interval(const std::tuple<T, T> tp)
{
  return interval<T>{ std::get<0>(tp), std::get<1>(tp) };
}

template<typename T>
std::tuple<T&, T&> as_ref_tuple(interval<T>& i)
{
  return std::tie(i.l, i.r);
}

template<typename T>
std::tuple<T, T> as_val_tuple(const interval<T>& i)
{
  return std::tuple(i.l, i.r);
}

template<typename T>
std::tuple<const T&, const T&> as_ref_tuple(const interval<T>& i)
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
  const auto& [l, r] = as_ref_tuple(i);
  os << '(' << l << "; " << r << ')';
  return os;
}

/*
 *  1.  MONOPS
 */

template<typename T>
interval<T> invert(const interval<T>& i)
{
  using namespace std;
  const auto& [l, r] = as_ref_tuple(i);
  T ll , rr;

  const auto inf      = numeric_limits<T>::infinity();
  const auto sig_nan  = numeric_limits<T>::signaling_NaN();

  if(l < 0 && r >= 0)
    ll = - inf;
  else
    ll = min(1 / l, 1 / r);

  if(r > 0 && l <= 0)
    rr = inf;
  else
    rr = max(1 / l, 1 / r);

  if(l == 0 && r == 0)
    return make_interval(sig_nan, sig_nan);

  return make_interval(ll, rr);
};

/*
 *  2.  BINOPS
 */


/*
 *  2.1.  interval * interval
 */

template<typename T>
inline interval<T> operator + (const interval<T>& a, const interval<T>& b)
{
  const auto& [la, ra] = as_ref_tuple(a);
  const auto& [lb, rb] = as_ref_tuple(b);
  return make_interval(la + lb, ra + rb);
}

template<typename T>
inline interval<T> operator - (const interval<T>& a, const interval<T>& b)
{
  const auto& [la, ra] = as_ref_tuple(a);
  const auto& [lb, rb] = as_ref_tuple(b);
  return make_interval(la - rb, ra - lb);
}

template<typename T>
inline interval<T> operator * (const interval<T>& a, const interval<T>& b)
{
  using namespace std;
  const auto& [la, ra] = as_ref_tuple(a);
  const auto& [lb, rb] = as_ref_tuple(b);

  auto v0 = la * lb , v1 = la * rb
     , v2 = ra * lb , v3 = ra * rb;

  return make_interval( min(v0, min(v1, min(v2, v3)))
                      , max(v0, max(v1, max(v2, v3)))
                      );
}

template<typename T>
inline interval<T> operator / (const interval<T>& a, const interval<T>& b)
{
  return a * invert(b);
}

/*
 *  2.2.  interval * numeric
 */

template<typename T>
inline interval<T> operator + (const interval<T>& a, const T& b)
{
  const auto& [la, ra] = as_ref_tuple(a);
  return make_interval(la + b, ra + b);
}

template<typename T>
inline interval<T> operator - (const interval<T>& a, const T& b)
{

}

template<typename T>
inline interval<T> operator * (const interval<T>& a, const T& b)
{

}

template<typename T>
inline interval<T> operator / (const interval<T>& a, const T& b)
{

}

/*
 *  2.2.  numeric * interval
 */



