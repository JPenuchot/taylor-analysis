#include <iostream>

#include <differentiation.hpp>
//#include <interval.hpp>

//#include "examples/heli.hpp"
//#include "examples/brusselator.hpp"

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

  //auto a = interval{20., 21.};
  //const auto& [l, r] = a;
  //auto b = (2. + interval{l + 1, r + 2}) * 2.;
  //cout << b << '\n';

  using namespace diff;

  //  x n'a aucune valeur, mais son *type* nous intéresse
  auto x = var{};
  auto test = (x + x) * x / x;
}
