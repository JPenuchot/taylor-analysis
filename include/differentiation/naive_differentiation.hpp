#pragma once

template<typename Ret, typename... Args>
using fun_t_helper = Ret(Args...);

template<typename Ret, typename Arg>
using unary_fun_t_helper = Ret(Arg);

template<typename F, typename D>
inline D derivate(F f, D i, D dt)
{
  return (f(i + dt) - f(i)) / dt;
}

template<unsigned N, typename F, typename D>
inline auto derivate_n(F f, D i, D dt)
{
  if constexpr (N == 0)
    return f(i);
  else
    return derivate ( [&](auto i){ return derivate_n<N - 1>(f, i, dt * D(.9)); }
                    , i
                    , dt
                    );
}

template<typename Ret, typename... Args, typename D>
auto grad(fun_t_helper<Ret, Args...> f, D i, D dt)
{
  static_assert(true, "not implemented");
}
