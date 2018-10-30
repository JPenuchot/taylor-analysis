#pragma once

#include <tuple>

#include "support.hpp"

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
template<typename Trans, typename... Ts>
auto transform(Trans trans, std::tuple<Ts...> tp)
{
  using namespace std;

  tuple<Ts...> res;

  static_unroll<sizeof...(Ts)>([&](auto I)
  {
    get<I>(res) = apply(get<I>(trans), tp);
  });

  return res;
}
