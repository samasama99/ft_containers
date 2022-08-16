#include "is_same.hpp"
#include <iostream>

struct A {
  static const bool value = true;
};

template <typename T, typename U>
struct test {
  typedef typename ft::enable_if<T, typeid(T) == typeid(U)>::value t1;
  typedef U t2;
};

int main() {
  test<int, int>::t1;
}
