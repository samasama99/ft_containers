#include <vector>
#include <string>
#include <functional>
#include "equal.hpp"
#include "lexicographical_compare.hpp"

int main() {
  {
    std::string s = "aaa";
    std::string s2 = "aab";
    assert(std::lexicographical_compare(s.begin(), s.end(), s2.begin(), s2.end()));
    assert(s < s2);
  }
  {
    std::string s = "aab";
    std::string s2 = "aab";
    assert(!ft::lexicographical_compare(s.begin(), s.end(), s2.begin(), s2.end()));
    assert(!(s < s2));
    assert(s <= s2);
    assert(ft::equal(s.begin(), s.end(), s2.begin()));
  }
  {
    std::string s = "aab";
    std::string s2 = "aaa";
    assert(!ft::lexicographical_compare(s.begin(), s.end(), s2.begin(), s2.end()));
    assert(s > s2);
    assert(!ft::equal(s.begin(), s.end(), s2.begin()));
  }
  {
    std::string s = "aab";
    std::string s2 = "aaa";
    assert(ft::lexicographical_compare(s.begin(), s.end(), s2.begin(), s2.end(), std::greater<char>()));
    assert(!ft::lexicographical_compare(s.begin(), s.end(), s2.begin(), s2.end(), std::less<char>()));
    assert(s > s2);
    assert(!ft::equal(s.begin(), s.end(), s2.begin()));
  }
  {
    std::vector<int> x;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    std::vector<int> y;
    y.push_back(1);
    y.push_back(2);
    y.push_back(3);
    assert(x == y);
    assert(ft::equal(x.begin(), x.end(), y.begin()));
  }
  {
    std::vector<int> x;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    std::vector<int> y;
    y.push_back(1);
    y.push_back(2);
    assert(!(x == y));
    assert(!ft::equal(x.begin(), x.end(), y.begin()));
  }
  {
    std::vector<int> x;
    x.push_back(1);
    x.push_back(2);
    std::vector<int> y;
    y.push_back(1);
    y.push_back(2);
    y.push_back(3);
    assert(x != y);
    assert(ft::equal(x.begin(), x.end(), y.begin()));
  }
  {
    std::vector<int> x;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    std::vector<int> y;
    y.push_back(1);
    y.push_back(3);
    y.push_back(3);
    assert(x != y);
    assert(!ft::equal(x.begin(), x.end(), y.begin()));
    std::cout << "testing lexicographical_compare :: pass\n";
    std::cout << "testing equal :: pass\n";
  }
}
