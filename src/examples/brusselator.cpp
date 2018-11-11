#include <interval.hpp>
#include <tadiff.h>

#include "brusselator.hpp"

void brusselator()
{
  using namespace fadbad;

  //  Derivatives as polymorph lambdas

  auto x1_prime = [](const auto x1, const auto x2)
  {
    return 1 + (x1 * x1) * x2 - 2.5 * x1;
  };

  auto x2_prime = [](const auto x1, const auto x2)
  {
    return 1.5 * x1 - (x1 * x1) * x2;
  };

  //  using FADBAD++'s template structure...
  T<double> x1, x2;
  x1 = 1.;
  x2 = 1.;

  //  Collecting DAGs
  auto x1_ = x1_prime(x1, x2);
  auto x2_ = x2_prime(x1, x2);
}
