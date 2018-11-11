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
  return binop<op, T1, T2>{make_tuple(t1, t2)};
}

} // <-- !namespace diff
