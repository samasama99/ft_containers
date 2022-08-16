#include "is_integral.hpp"
#include "is_same.hpp"
#include <assert.h>
#include <cassert>

int main() {
  {
    bool test = ft::is_same<int, int>::value;
    assert(test);
  }
  {
    bool test = ft::is_same<int, double>::value;
    assert(test == false);
    std::cout << "is_same :: pass\n";
  }
  {
    assert(ft::is_integral<int>::value);
    assert(ft::is_integral<char>::value);
    assert(ft::is_integral<unsigned long>::value);
    assert(ft::is_integral<std::string>::value == false);
    assert(ft::is_integral<double>::value == false);
    assert(ft::is_integral<float>::value == false);
    std::cout << "is_integral :: pass\n";
  }
}
