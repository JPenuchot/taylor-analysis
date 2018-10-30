#pragma once

#include <tuple>


/**
 * @brief      Represents an interval
 *
 * @tparam     T     Type of a boundary
 *
 * @note       This type inherits from tuple instead of being an alias to avoid
 * overloading tuple's existing operators.
 */
template<typename T>
class interval : std::tuple<T, T>{};

template<typename T>
interval<T> invert(const interval<T>& i)
{
  using namespace std;
  const auto& [l, r] = i;
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
    return make_tuple(sig_nan, sig_nan);

  return make_tuple(ll, rr);
};

template<typename T>
interval<T> operator + (const interval<T>& a, const interval<T>& b)
{
  using namespace std;
  return make_tuple(get<0>(a) + get<0>(b), get<1>(a) + get<1>(b));
}

template<typename T>
interval<T> operator - (const interval<T>& a, const interval<T>& b)
{
  using namespace std;
  return make_tuple(get<0>(a) - get<1>(b), get<1>(a) - get<0>(b));
}

template<typename T>
interval<T> operator * (const interval<T>& a, const interval<T>& b)
{
  using namespace std;

  const auto& [la, ra] = a;
  const auto& [lb, rb] = b;

  auto v0 = la * lb , v1 = la * rb
     , v2 = ra * lb , v3 = ra * rb;

  return make_tuple( min(v0, v1, v2, v3) , max(v0, v1, v2, v3) );
}

template<typename T>
interval<T> operator / (const interval<T>& a, const interval<T>& b)
{
  using namespace std;
  static_assert(true, "Not yet implemented.");

  const auto& [la, ra] = a;
  const auto& [lb, rb] = b;

  return a * invert(b);
}
