<!-- page_number: true -->

<style>
  strong { color:maroon; }
  em     { color:navy; }
</style>

# Taylor-based Reachability Analysis of Continuous and Hybrid Systems

###### Jules Pénuchot

---

## Analysis of what ?
- continuous systems (set of differential equations)
- hybrid systems (adds conditions to transitions)

---

## What's implemented
- continuous systems *(partially)*
- hybrid systems ? Sadly not

---

## What was done for *hybrid systems*
- proper c++17 interval algebra library [ref au papier dans le sujet]
- draft for a modern differentiation library

---

## Interval algebra library

Base type :

```c++
template<typename T>
struct interval
{
  T l, r;
};
```

---

## Interval algebra library

- operator overloads : `+`, `-`, `*`, `/` and `<<`
- `make_interval` function for C++11-style template deduction
- deduction guide (C++17)

---

## Interval algebra library

usage example :

```cpp
auto a = interval{20., 21.};
const auto& [l, r] = a;
auto b = (2. + interval{l + 1, r + 2}) * 2.;
cout << b << '\n';
```

---

## Differentiation library

Where most of the computing happens

Current libraries are actually **suboptimal**
- Spend most of their time interpreting data structures
- Less actual compute time

---

## Differentiation library

Metaprogramming for an automatic differentiation library


###### ...metaprogramming ?

→ Design and implementation of programs whose inputs and outputs are themselves programs.

---

## Differentiation library : metaprogramming

In C++ : Template metaprogramming

All accross the STL :
- `std::tuple`
- parameter packs
- template structures/functions

Modern C++ generic programming is relying on **types' properties** to generate **specialized code**

---

## Differentiation library : metaprogramming

Use case :

```cpp
auto test = std::tuple("toto", "africa", 42);

std::apply([](const auto&... elmts)
{
  ( ( cout << elmts << ' ' ) , ... );
}, test);
```

- expression is expanded
- function call inlined

→ As performant as writing it by hand, but more **concise** and **generic**

---

## Differentiation library : implementation

- expressions stored **as types**
- then converted into **functions** at **compile time**

Example : from type to function

```cpp
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
```
**Statically** converts an expression type into a function, **without runtime interpretation**

---

## Differentiation library : projections ?

- **no branching** during taylor-model simulations
- benefits from the **compiler's optimizations**

→ As fast as handmade assembly code

---

## Differentiation library : other advantages

- higher abstraction level
- clear and concise API

→ C++ code close to what simulation software offer today
