#include "vector/ft_vector.hpp"
#include <iostream>
#include <list>
#include <string>
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
  // {
  //   ft::vector<std::string> s(3);
  //   s[0] = "hello";
  //   s[1] = "oussama";
  //   s[2] = "world";
  //   assert(s[0] == "hello");
  //   assert(s[1] == "oussama");
  //   assert(s[2] == "world");
  //   std::cout << "testing [] overloading 2 :: pass\n";
  // }
  {
    ft::vector<char> x(5, 'c');
    x[0] = 'x';
    x[1] = 'x';
    x[2] = 'x';
    x[3] = 'x';
    assert(x[0] == 'x');
    assert(x[1] == 'x');
    assert(x[2] == 'x');
    assert(x[3] == 'x');
    assert(x[4] == 'c');
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
  {
    ft::vector<int> test;
    test.push_back(4);
    test.push_back(4);
    assert(test.capacity() == 2);
    assert(test.size() == 2);
    test.pop_back();
    assert(test.capacity() == 2);
    assert(test.size() == 1);
    test.pop_back();
    assert(test.capacity() == 2);
    assert(test.size() == 0);
    // infinite loop ??
    // test.pop_back();
    // assert(test.capacity() == 2);
    // assert(test.size() == 18446744073709551615ul);
    std::cout << "testing pop_back() method :: pass\n";
  }
  {
    ft::vector<int> vec1;
    vec1.push_back(5);
    ft::vector<int> vec2;
    vec1.swap(vec2);
    assert(vec2.at(0) == 5);
    assert(vec2.capacity() == 1);
    assert(vec2.size() == 1);
    assert(vec1.capacity() == 0);
    assert(vec1.size() == 0);
  }
  {
    ft::vector<int> vec1;
    vec1.push_back(5);
    ft::vector<int> vec2;
    vec2.push_back(10);
    vec2.push_back(20);
    vec2.push_back(30);
    vec1.swap(vec2);
    assert(vec2.capacity() == 1);
    assert(vec2.size() == 1);
    assert(vec1.capacity() == 4);
    assert(vec1.size() == 3);
    assert(vec2.at(0) == 5);
    assert(vec1.at(0) == 10);
    assert(vec1.at(1) == 20);
    assert(vec1.at(2) == 30);
    std::cout << "testing swap() method :: pass\n";
  }
  {
    ft::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    assert(vec.capacity() == 4 && vec.size() == 3);
    vec.clear();
    assert(vec.capacity() == 4 && vec.size() == 0);
    std::cout << "testing clear() method :: pass\n";
  }
  {
    ft::vector<int> vec;
    std::allocator<int> alloc = vec.get_allocator();
    int *arr = alloc.allocate(4);
    arr[0] = 10;
    arr[1] = 15;
    arr[2] = 20;
    arr[3] = 25;
    assert(arr[0] == 10);
    assert(arr[1] == 15);
    assert(arr[2] == 20);
    assert(arr[3] == 25);
    alloc.deallocate(arr, 4);
    std::cout << "testing get_allocator() method :: pass\n";
  }
  {
    ft::vector<int> x;
    x.push_back(10);
    x.push_back(10);
    x.assign(5, 20);
    assert(x.capacity() == 5);
    assert(x.at(0) == 20);
    assert(x.at(2) == 20);
    assert(x.at(1) == 20);
    assert(x.at(3) == 20);
    assert(x.at(4) == 20);
  }
  {
    ft::vector<int> x;
    x.push_back(10);
    x.push_back(10);
    x.push_back(10);
    x.push_back(10);
    x.push_back(10);
    x.push_back(10);
    x.push_back(10);
    x.push_back(10);
    x.push_back(10);
    x.assign(5, 20);
    assert(x.capacity() == 16 && x.size() == 5);
    assert(x.at(0) == 20);
    assert(x.at(2) == 20);
    assert(x.at(1) == 20);
    assert(x.at(3) == 20);
    assert(x.at(4) == 20);
  }
  {
    ft::vector<int> x;
    x.push_back(10);
    x.push_back(10);
    x.assign(0, 0);
    assert(x.capacity() == 2 && x.size() == 0);
    std::cout << "testing assign() method :: pass\n";
  }

  {
    ft::vector<int> x;
    x.push_back(10);
    x.push_back(10);
    x.resize(1, 5);
    assert(x.capacity() == 2 && x.size() == 1);
    assert(x.at(0) == 10);
  }
  {
    ft::vector<int> x;
    x.push_back(10);
    x.push_back(10);
    assert(x.capacity() == 2 && x.size() == 2);
    x.resize(4, 5);
    assert(x.capacity() == 4 && x.size() == 4);
    assert(x.at(0) == 10 && x.at(1) == 10);
    assert(x.at(2) == 5 && x.at(3) == 5);
  }
  {
    ft::vector<int> x;
    x.push_back(10);
    x.push_back(10);
    x.push_back(10);
    x.push_back(10);
    x.push_back(10);
    assert(x.capacity() == 8 && x.size() == 5);
    x.resize(6, 5);
    assert(x.capacity() == 8 && x.size() == 6);
    assert(x.at(0) == 10 && x.at(1) == 10);
    assert(x.at(2) == 10 && x.at(3) == 10);
    assert(x.at(4) == 10 && x.at(5) == 5);
    std::cout << "testing resize() method :: pass\n";
  }
  {
    ft::vector<char> a;
    ft::vector<int> b;
    ft::vector<std::string> c;
    assert(a.max_size() == std::allocator<char>().max_size());
    assert(b.max_size() == std::allocator<int>().max_size());
    assert(c.max_size() == std::allocator<std::string>().max_size());
    std::cout << "testing max_size() method :: pass\n";
  }
  {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    ft::vector<int> vec2(vec.begin(), vec.end());
    assert(vec[0] == vec2[0]);
    assert(vec[1] == vec2[1]);
    assert(vec[2] == vec2[2]);
  }
  {
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    ft::vector<int> vec2(lst.begin(), lst.end());
    assert(lst.back() == vec2[2]);
    lst.pop_back();
    assert(lst.back() == vec2[1]);
    lst.pop_back();
    assert(lst.back() == vec2[0]);
    std::cout << "testing range constructor :: pass\n";
  }
  {
    ft::vector<int> vec;
    vec.push_back(5);
    vec.push_back(6);
    ft::vector<int>::iterator b = vec.begin();
    ft::vector<int>::iterator e = vec.end();

    assert(vec[0] == *b);
    assert(vec[1] == *(b + 1));
    assert(vec[0] == b[0]);
    assert(vec[1] == b[1]);

    assert(vec[1] == *(e - 1));
    assert(vec[0] == *(e - 2));
    std::cout << "testing end() begin() :: pass\n";
  }
  {
    ft::vector<int> x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    ft::vector<int>::iterator b = x.begin();
    ft::vector<int>::iterator e = x.end();
    for (int i = 0; i < x.size(); ++i) {
      assert(b[i] == x[i]);
    }
    int index = 0;
    for (ft::vector<int>::iterator i = b; i < e; ++i) {
      assert(x[index] == *i);
      index++;
    }
    int rindex = x.size();
    for (ft::vector<int>::iterator i = e; e != i; --i) {
      rindex--;
      assert(x[rindex] == *i);
    }

    ft::vector<int>::iterator b2 = x.begin();
    ft::vector<int>::iterator e2 = x.end();
    b2 += 2;
    assert(b2 == b + 2 && *b2 == b[2]);
    e2 -= 2;
    assert(e2 == e - 2 && *e2 == *(e - 2));
    b2 -= 1;
    assert(b2 == b + 1 && *b2 == b[1]);
    std::cout << "testing operator+= overloading in vectorIterator :: pass\n";
    std::cout << "testing operator-= overloading in vectorIterator :: pass\n";
    std::cout << "testing operator[] overloading in vectorIterator :: pass\n";
    std::cout << "testing operator== overloading in vectorIterator :: pass\n";
    std::cout << "testing operator< overloading in vectorIterator :: pass\n";
    std::cout
        << "testing operator++ pre overloading in vectorIterator :: pass\n";
    std::cout
        << "testing operator-- pre overloading in vectorIterator :: pass\n";
    std::cout
        << "testing operator- pre overloading in vectorIterator :: pass\n";
    std::cout
        << "testing operator+ pre overloading in vectorIterator :: pass\n";
    assert(*(b++) == x[0]);
    assert(*b == x[1]);
    assert(*(b--) == x[1]);
    assert(*b == x[0]);
    std::cout
        << "testing operator++ post overloading in vectorIterator :: pass\n";
    std::cout
        << "testing operator-- post overloading in vectorIterator :: pass\n";
  }
  {
    std::vector<std::string> vec;
    vec.push_back("hello");
    vec.push_back("hello");
    vec.push_back("hello");
    ft::vector<std::string> vec2(vec.begin(), vec.end());
    assert(vec[0] == vec2[0]);
    assert(vec[1] == vec2[1]);
    assert(vec[2] == vec2[2]);
  }
  {
    std::list<std::string> lst;
    lst.push_back("bye");
    lst.push_back("bye");
    lst.push_back("bye");
    ft::vector<std::string> vec2(lst.begin(), lst.end());
    assert(lst.back() == vec2[2]);
    lst.pop_back();
    assert(lst.back() == vec2[1]);
    lst.pop_back();
    assert(lst.back() == vec2[0]);
  }
  {
    ft::vector<std::string> vec;
    vec.push_back("test");
    vec.push_back("test");
    ft::vector<std::string>::iterator b = vec.begin();
    ft::vector<std::string>::iterator e = vec.end();

    assert(vec[0] == *b);
    assert(vec[1] == *(b + 1));
    assert(vec[0] == b[0]);
    assert(vec[1] == b[1]);

    assert(vec[1] == *(e - 1));
    assert(vec[0] == *(e - 2));
  }
  {
    ft::vector<std::string> x;
    x.push_back("what??");
    x.push_back("what??");
    x.push_back("what??");
    x.push_back("what??");
    ft::vector<std::string>::iterator b = x.begin();
    ft::vector<std::string>::iterator e = x.end();
    for (int i = 0; i < x.size(); ++i) {
      assert(b[i] == x[i]);
    }
    int index = 0;
    for (ft::vector<std::string>::iterator i = b; i < e; ++i) {
      assert(x[index] == *i);
      index++;
    }
    int rindex = x.size();
    for (ft::vector<std::string>::iterator i = e; e != i; --i) {
      rindex--;
      assert(x[rindex] == *i);
    }
    assert(*(b++) == x[0]);
    assert(*b == x[1]);
    assert(*(b--) == x[1]);
    assert(*b == x[0]);
    std::cout << "the same iterator tests with std:string :: pass\n";
  }
  // {
  //   ft::vector<int> vec;
  //   vec.push_back(5);
  //   vec.push_back(6);
  //   ft::vector<int>::const_iterator b = vec.begin();
  //   ft::vector<int>::const_iterator e = vec.end();

  //   assert(vec[0] == *b);
  //   assert(vec[1] == *(b + 1));
  //   assert(vec[0] == b[0]);
  //   assert(vec[1] == b[1]);

  //   assert(vec[1] == *(e - 1));
  //   assert(vec[0] == *(e - 2));
  // }
  // {
  //   ft::vector<int> x;
  //   x.push_back(0);
  //   x.push_back(1);
  //   x.push_back(2);
  //   x.push_back(3);
  //   ft::vector<int>::const_iterator b = x.begin();
  //   ft::vector<int>::const_iterator e = x.end();
  //   for (int i = 0; i < x.size(); ++i) {
  //     assert(b[i] == x[i]);
  //   }
  //   int index = 0;
  //   for (ft::vector<int>::const_iterator i = b; i < e; ++i) {
  //     assert(x[index] == *i);
  //     index++;
  //   }
  //   int rindex = x.size();
  //   for (ft::vector<int>::const_iterator i = e; e != i; --i) {
  //     rindex--;
  //     assert(x[rindex] == *i);
  //   }

  //   ft::vector<int>::const_iterator b2 = x.begin();
  //   ft::vector<int>::const_iterator e2 = x.end();
  //   b2 += 2;
  //   assert(b2 == b + 2 && *b2 == b[2]);
  //   e2 -= 2;
  //   assert(e2 == e - 2 && *e2 == *(e - 2));
  //   b2 -= 1;
  //   assert(b2 == b + 1 && *b2 == b[1]);
  //   assert(*(b++) == x[0]);
  //   assert(*b == x[1]);
  //   assert(*(b--) == x[1]);
  //   assert(*b == x[0]);
  //   std::cout << "the same iterator tests with const_iterator :: pass\n";
  // }
  {
    ft::vector<int> x;
    x.push_back(10);
    x.push_back(10);
    ft::vector<int> c;
    c.assign(x.begin(), x.end());
    assert(c.size() == 2 && c.capacity() == 2);
    assert(c.at(0) == 10 && c.at(1) == 10);
  }
  {
    std::vector<std::string> vec;
    vec.push_back("hello");
    vec.push_back("hello");
    vec.push_back("hello");
    ft::vector<std::string> vec2;
    vec2.assign(vec.begin(), vec.end());
    assert(vec2.capacity() == 3 && vec2.size() == 3);
    assert(vec[0] == vec2[0]);
    assert(vec[1] == vec2[1]);
    assert(vec[2] == vec2[2]);
  }
  {
    std::list<std::string> lst;
    lst.push_back("bye");
    lst.push_back("bye");
    lst.push_back("bye");
    ft::vector<std::string> vec2;
    vec2.assign(lst.begin(), lst.end());
    assert(vec2.capacity() == 3 && vec2.size() == 3);
    assert(lst.back() == vec2[2]);
    lst.pop_back();
    assert(lst.back() == vec2[1]);
    lst.pop_back();
    assert(lst.back() == vec2[0]);
    std::cout << "testing assign() template :: pass\n";
  }

  std::cerr << "all passed\n";
  system("leaks a.out");
}
