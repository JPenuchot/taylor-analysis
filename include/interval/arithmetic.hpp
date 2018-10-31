#pragma once

#include "interval_type.hpp"

/*
 *  1.  MONOPS
 */

template<typename T>
inline interval<T> invert(const interval<T>& i)
{
  using namespace std;
  const auto& [l, r] = as_const_ref_tuple(i);
  T ll , rr;

  constexpr auto inf = numeric_limits<T>::infinity();

  if(l < 0 && r >= 0)
    ll = - inf;
  else
    ll = min(1 / l, 1 / r);

  if(r > 0 && l <= 0)
    rr = inf;
  else
    rr = max(1 / l, 1 / r);

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
  const auto& [la, ra] = as_const_ref_tuple(a);
  const auto& [lb, rb] = as_const_ref_tuple(b);
  return make_interval(la + lb, ra + rb);
}

template<typename T>
inline interval<T> operator - (const interval<T>& a, const interval<T>& b)
{
  const auto& [la, ra] = as_const_ref_tuple(a);
  const auto& [lb, rb] = as_const_ref_tuple(b);
  return make_interval(la - rb, ra - lb);
}

template<typename T>
inline interval<T> operator * (const interval<T>& a, const interval<T>& b)
{
  using namespace std;
  const auto& [la, ra] = as_const_ref_tuple(a);
  const auto& [lb, rb] = as_const_ref_tuple(b);

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
inline interval<T> operator + (const interval<T>& i, const T& n)
{
  const auto& [l, r] = as_const_ref_tuple(i);
  return make_interval(l + n, r + n);
}

template<typename T>
inline interval<T> operator - (const interval<T>& i, const T& n)
{
  const auto& [l, r] = as_const_ref_tuple(i);
  return make_interval(l - n, r - n);
}

template<typename T>
inline interval<T> operator * (const interval<T>& i, const T& n)
{
  const auto& [l, r] = as_const_ref_tuple(i);
  return make_interval(l * n, r * n);
}

template<typename T>
inline interval<T> operator / (const interval<T>& i, const T& n)
{
  const auto& [l, r] = as_const_ref_tuple(i);
  return i * (T(1) / n);
}

/*
 *  2.2.  numeric * interval
 */


template<typename T>
inline interval<T> operator + (const T& n, const interval<T>& i)
{
  const auto& [l, r] = as_const_ref_tuple(i);
  return make_interval(l + n, r + n);
}

template<typename T>
inline interval<T> operator - (const T& n, const interval<T>& i)
{
  const auto& [l, r] = as_const_ref_tuple(i);
  return make_interval(l - n, r - n);
}

template<typename T>
inline interval<T> operator * (const T& n, const interval<T>& i)
{
  const auto& [l, r] = as_const_ref_tuple(i);
  return make_interval(l * n, r * n);
}

template<typename T>
inline interval<T> operator / (const T& n, const interval<T>& i)
{
  return make_interval(n, n) / i;
}

/*
 *  3. TERNOPS... WAIT WHAT..?
 */
