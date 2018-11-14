#pragma once

#include "differentiation_types.hpp"

namespace diff {

//  BINOP * BINOP

template< arith_op OpA, typename TA1, typename TA2
        , arith_op OpB, typename TB1, typename TB2
        >
auto operator + ( const binop<OpA, TA1, TA2>& op1
                , const binop<OpB, TB1, TB2>& op2
                )
{
  return make_binop<arith_op::add>(op1, op2);
}

template< arith_op OpA, typename TA1, typename TA2
        , arith_op OpB, typename TB1, typename TB2
        >
auto operator - ( const binop<OpA, TA1, TA2>& op1
                , const binop<OpB, TB1, TB2>& op2
                )
{
  return make_binop<arith_op::sub>(op1, op2);
}

template< arith_op OpA, typename TA1, typename TA2
        , arith_op OpB, typename TB1, typename TB2
        >
auto operator * ( const binop<OpA, TA1, TA2>& op1
                , const binop<OpB, TB1, TB2>& op2
                )
{
  return make_binop<arith_op::mul>(op1, op2);
}

template< arith_op OpA, typename TA1, typename TA2
        , arith_op OpB, typename TB1, typename TB2
        >
auto operator / ( const binop<OpA, TA1, TA2>& op1
                , const binop<OpB, TB1, TB2>& op2
                )
{
  return make_binop<arith_op::div>(op1, op2);
}

//  VAR * VAR

auto operator + (const var& t1, const var& t2)
{
  return make_binop<arith_op::add>(t1, t2);
}

auto operator - (const var& t1, const var& t2)
{
  return make_binop<arith_op::sub>(t1, t2);
}

auto operator * (const var& t1, const var& t2)
{
  return make_binop<arith_op::mul>(t1, t2);
}

auto operator / (const var& t1, const var& t2)
{
  return make_binop<arith_op::div>(t1, t2);
}

//  BINOP * VAR / BINOP * VAR

  //  +

template<arith_op op, typename To1, typename To2>
auto operator + (const binop<op, To1, To2>& o, const var& v)
{
  return make_binop<arith_op::add>(o, v);
}

template<arith_op op, typename To1, typename To2>
auto operator + (const var& v, const binop<op, To1, To2>& o)
{
  return make_binop<arith_op::add>(v, o);
}

  //  -

template<arith_op op, typename To1, typename To2>
auto operator - (const binop<op, To1, To2>& o, const var& v)
{
  return make_binop<arith_op::sub>(o, v);
}

template<arith_op op, typename To1, typename To2>
auto operator - (const var& v, const binop<op, To1, To2>& o)
{
  return make_binop<arith_op::sub>(v, o);
}

  //  *

template<arith_op op, typename To1, typename To2>
auto operator * (const binop<op, To1, To2>& o, const var& v)
{
  return make_binop<arith_op::mul>(o, v);
}

template<arith_op op, typename To1, typename To2>
auto operator * (const var& v, const binop<op, To1, To2>& o)
{
  return make_binop<arith_op::mul>(v, o);
}

  //  /

template<arith_op op, typename To1, typename To2>
auto operator / (const binop<op, To1, To2>& o, const var& v)
{
  return make_binop<arith_op::div>(o, v);
}

template<arith_op op, typename To1, typename To2>
auto operator / (const var& v, const binop<op, To1, To2>& o)
{
  return make_binop<arith_op::div>(v, o);
}

} // <-- !namespace diff
