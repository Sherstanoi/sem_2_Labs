#include "mymath.h"

namespace mymath {
int factorial(int chislo) {
    int result = 1;
  for (int i = chislo; chislo > 0; --chislo) {
    result *= i;
  }
  return result;
}
} // namespace math
