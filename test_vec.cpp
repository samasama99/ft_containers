#include "vector/ft_vector.hpp"
#include <iostream>
#include <vector>

using std::cout;

int main() {
  {
    ft::vector<int> array;
    cout << "vector() default constructor :: pass\n";
  }
  {
    ft::vector<int> array2(10);
    cout << "vector(n) reserve constructor :: pass\n";
  }
  {
    try {
      ft::vector<int> array3(-1);
    } catch (std::length_error &e) {
      std::cout << "catching length error :: pass\n";
    }
  }
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
    std::cout << "testing [] overloading 1 :: pass\n";
  }
  {
    ft::vector<std::string> s(3);
    s[0] = "hello";
    s[1] = "oussama";
    s[2] = "world";
    assert(s[0] == "hello");
    assert(s[1] == "oussama");
    assert(s[2] == "world");
    std::cout << "testing [] overloading 2 :: pass\n";
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
    std::cout << "testing [] overloading 3 :: pass\n";
  }
  {
    ft::vector<char> x(5, 'c');
    x[0] = 'x';
    x[1] = 'x';
    x.at(2) = 'y';
    x.at(3) = 'y';
    x.at(4) = 'y';
    assert(x.at(0) == 'x');
    assert(x.at(1) == 'x');
    assert(x.at(2) == 'y');
    assert(x.at(3) == 'y');
    assert(x.at(4) == 'y');
    std::cout << "testing at() method:: pass\n";
    try {
      char c = x.at(10);
    } catch (std::out_of_range &e) {
      std::cout << "testing at() method throwing error :: pass\n";
    }
  }
  {
    ft::vector<char> x(5, 'c');
    x[0] = 'x';
    x[1] = 'x';
    x.at(2) = 'y';
    x.at(3) = 'y';
    x.at(4) = 'y';
    assert(x.front() == 'x');
    assert(x.back() == 'y');
    std::cout << "testing front() method throwing error :: pass\n";
    std::cout << "testing back() method throwing error :: pass\n";
  }
  {
    ft::vector<char> x;
    assert(x.capacity() == 0);
    x.reserve(5);
    assert(x.capacity() == 5);
  }
  {
    ft::vector<char> x(5, 'c');
    assert(x.capacity() == 5);
    x.reserve(10);
    assert(x.capacity() == 10);
  }
  {
    ft::vector<char> x(5, 'c');
    assert(x.capacity() == 5);
    x.reserve(2);
    assert(x.capacity() == 5);
    std::cout << "testing reserve() method :: pass\n";
  }
  {
    ft::vector<char> x(5, 'c');
    ft::vector<char> y(5, 'c');
    ft::vector<char> z(5, 'c');
    assert(y.at(0) == 'c');
    assert(y.at(1) == 'c');
    assert(y.at(2) == 'c');
    assert(y.at(3) == 'c');
    assert(y.at(4) == 'c');
    assert(z.at(0) == 'c');
    assert(z.at(1) == 'c');
    assert(z.at(2) == 'c');
    assert(z.at(3) == 'c');
    assert(z.at(4) == 'c');
    y = z = x; 
    assert(x.capacity() == y.capacity() && y.capacity() == z.capacity());
    assert(x.size() == y.size() && y.size() == z.size());
    std::cout << "testing assignment overloading :: pass\n";
    std::cout << "testing assignment chaining :: pass\n";
  }
  {
    ft::vector<int> x;
    assert(x.size() == 0);
    assert(x.capacity() == 0);
    x.push_back(1);
    assert(x.at(0) == 1);
    assert(x[0] == 1);
    assert(x.size() == 1);
    assert(x.capacity() == 1);
    x.push_back(2);
    assert(x.at(1) == 2);
    assert(x[1] == 2);
    assert(x.size() == 2);
    assert(x.capacity() == 2);
    x.push_back(4);
    assert(x.at(2) == 4);
    assert(x[2] == 4);
    assert(x.size() == 3);
    assert(x.capacity() == 4);
     x.push_back(5);
    assert(x.at(3) == 5);
    assert(x[3] == 5);
    assert(x.size() == 4);
    assert(x.capacity() == 4);
     x.push_back(6);
    assert(x.at(4) == 6);
    assert(x[4] == 6);
    assert(x.size() == 5);
    assert(x.capacity() == 8);
     x.push_back(8);
    assert(x.at(5) == 8);
    assert(x[5] == 8);
    assert(x.size() == 6);
    assert(x.capacity() == 8); 
    std::cout << "testing push_back() method :: pass\n";
  }
}
