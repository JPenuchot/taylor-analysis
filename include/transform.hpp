#pragma once

#include <tuple>

#include "support.hpp"

template<typename Ret, typename... Args>
using fun_t = Ret(Args...);

/**
 * @brief      Transforms a state tuple using a set of transformations.
 *
 * @param[in]  trans  Transformation functions
 * @param[in]  tp     State tuple
 *
 * @tparam     Trans  Type of the transformation container
 * @tparam     Ts     Types of the elements of the state
 *
 * @return     New state
 */
template<typename... Ts, typename... Fs>
std::tuple<Ts...> transform_state
  ( std::tuple<Fs...> trans
  , const std::tuple<Ts...>& tp
  )
{
  static_assert(sizeof...(Fs) == sizeof...(Ts), "Nooooo");
  using namespace std;

  tuple<Ts...> res;

  static_unroll<sizeof...(Ts)>([&](auto I)
  {
    get<I>(res) = get<I>(trans)(tp);
  });

  return res;
}
