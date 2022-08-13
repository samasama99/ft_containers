#include "vector/ft_vector.hpp"
#include <iostream>
#include <vector>

int main() {
  {
    ft::vector<int> x;
    x.push_back(1);
    x.push_back(2);
    x.insert(x.end(), 3);
    ft::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.insert(v.end(), 3);
    assert(x[0] == v[0]);
    assert(x[1] == v[1]);
    assert(x[2] == v[2]);
    std::cerr << "pass 1\n";
  }
  {
    ft::vector<int> x;
    x.insert(x.end(), 3);
    ft::vector<int> v;
    v.insert(v.end(), 3);
    assert(x[0] == v[0]);
    std::cerr << "pass 2\n";
  }
  {
    ft::vector<int> x;
    x.insert(x.begin(), 3);
    ft::vector<int> v;
    v.insert(v.begin(), 3);
    assert(x[0] == v[0]);
    std::cerr << "pass 3\n";
  }
  {
    ft::vector<int> x;
    x.push_back(1);
    x.push_back(2);
    x.push_back(4);
    x.insert(x.begin() + 3, 3);
    ft::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.insert(v.begin() + 3, 3);
    assert(x[0] == v[0]);
    assert(x[1] == v[1]);
    assert(x[2] == v[2]);
    assert(x[3] == v[3]);
    std::cerr << "pass 4\n";
  }
}
