#pragma once

#include <tuple>
#include <functional>

namespace diff {

//  Arithmetic operations
enum arith_op { add, sub, mul, div };

struct var {};

template<typename T>
struct constant { T v; };

template<arith_op, typename... Ts>
struct op
{
  std::tuple<Ts...> ts;
};

template<arith_op Op, typename T1, typename T2>
using binop = op<Op, T1, T2>;

//  Functional constructors

auto make_var()
{
  return var{};
}

template<typename T>
auto make_constant(const T& v)
{
  return constant(v);
};

template <arith_op op, typename T1, typename T2>
auto make_binop(T1 t1, T2 t2)
{
  return binop<op, T1, T2>{std::make_tuple(t1, t2)};
}

template<typename T1, typename T2>
auto to_func(const binop<arith_op::add, T1, T2>& op)
{
  return [=](const auto& x)
  {
    auto f1 = to_func(std::get<0>(op.ts));
    auto f2 = to_func(std::get<1>(op.ts));
    return f1(x) + f2(x);
  };
}

} // <-- !namespace diff
