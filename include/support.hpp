#pragma once

#include <utility>

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

template<typename... Ts>
auto const_tie(const Ts&... tps)
{
  return std::tuple<const Ts&...>{tps ...};
}
