#include <iostream>

//#include <differentiation.hpp>
#include <interval.hpp>

//#include "examples/heli.hpp"
#include "examples/brusselator.hpp"

using namespace std;

int main()
{
  //auto square = [](auto x)
  //{
  //  return x * x;
  //};


  //const auto x = 10;
  //auto test = diff::make_var();

  //brusselator();

  //  Using make_interval allows simple declaration using type inference
auto a = make_interval(20., 21.);

//  as_const_ref_tuple returns a const ref tuple to the interval's bounds,
//  allowing us to do structured binding on intervals easily.
const auto& [l, r] = as_const_ref_tuple(a);

//  Simple algebra
a = 2. + make_interval(l + 1, l + 2);

//  Operator << has been overloaded too, making intervals easy to print
cout << a << '\n';
}
