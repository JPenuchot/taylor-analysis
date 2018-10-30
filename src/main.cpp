#include <functional>
#include <iostream>
#include <utility>
#include <tuple>

#include <interval.hpp>
#include <transform.hpp>

int main()
{
  using namespace std;

  auto states = make_tuple(1, 1);

  //  Polymorphic lambda : fully type agnostic
  auto trans =
    make_tuple( //  x1
                []( auto x1 , auto x2 )
                {
                  return x1 + x2;
                }

                //  x2
              , []( auto x1 , auto x2 )
                {
                  return x1 + (x2 * x2);
                });

  auto t = transform(trans, make_tuple(1.f, 1));

  return 0;
}
