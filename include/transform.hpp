#pragma once

#include <utility>
#include <tuple>

template<typename F, std::size_t... I>
void static_unroll_impl(std::integer_sequence<std::size_t, I...>, F&& fun)
{
  ( fun(std::integral_constant<std::size_t, I>{}) , ... );
}

template<std::size_t I, typename F>
void static_unroll(F&& fun)
{
  static_unroll_impl( std::make_integer_sequence<std::size_t, I>{}
                    , std::forward<F>(fun)
                    );
};

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
