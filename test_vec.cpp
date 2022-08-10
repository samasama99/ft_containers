#include "vector/ft_vector.hpp"
#include <iostream>
// #include <vector>

int main() {
  {
    ft::vector<int> array;
  }
  std::cout << '\n';
  {
    ft::vector<int> array2(10);
  }
  std::cout << '\n';
  {
    try {
      ft::vector<int> array3(-1);
    } catch (std::length_error &e) {
      std::cout << "catching length error\n";
    }
  }
  std::cout << '\n';
  {
    ft::vector<int> x(5);
    x[0] = 1;
    x[1] = 2;
    x[2] = 3;
    x[3] = 4;
    x[4] = 5;
    assert(x[0] == 1);
    assert(x[1] == 2);
    assert(x[2] == 3);
    assert(x[3] == 4);
    assert(x[4] == 5);
  }
  {
    ft::vector<std::string> s(3);
    s[0] = "hello";
    s[1] = "oussama";
    s[2] = "world";
    assert(s[0] == "hello");
    assert(s[1] == "oussama");
    assert(s[2] == "world");
  }
  {
    ft::vector<char> x(5, 'c');
    x[0] = 'x';
    x[1] = 'x';
    x[2] = 'x';
    x[3] = 'x';
    x[4] = 'x';
    assert(x[0] == 'x');
    assert(x[1] == 'x');
    assert(x[2] == 'x');
    assert(x[3] == 'x');
    assert(x[4] == 'x');
  }
  {
    
  }
}
