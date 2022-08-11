#include <iostream>
#include <vector>

using std::cout;

int main() {
  {
    std::vector<int> array;
    cout << "vector() default constructor :: pass\n";
  }
  {
    std::vector<int> array2(10);
    cout << "vector(n) reserve constructor :: pass\n";
  }
  {
    try {
      std::vector<int> array3(-1);
    } catch (std::length_error &e) {
      std::cout << "catching length error :: pass\n";
    }
  }
  {
    std::vector<int> x(5);
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
    std::vector<std::string> s(3);
    s[0] = "hello";
    s[1] = "oussama";
    s[2] = "world";
    assert(s[0] == "hello");
    assert(s[1] == "oussama");
    assert(s[2] == "world");
    std::cout << "testing [] overloading 2 :: pass\n";
  }
  {
    std::vector<char> x(5, 'c');
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
    std::vector<char> x(5, 'c');
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
    std::vector<char> x(5, 'c');
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
    std::vector<char> x;
    assert(x.capacity() == 0);
    x.reserve(5);
    assert(x.capacity() == 5);
  }
  {
    std::vector<char> x(5, 'c');
    assert(x.capacity() == 5);
    x.reserve(10);
    assert(x.capacity() == 10);
  }
  {
    std::vector<char> x(5, 'c');
    assert(x.capacity() == 5);
    x.reserve(2);
    assert(x.capacity() == 5);
    std::cout << "testing reserve() method :: pass\n";
  }
  {
    std::vector<char> x(5, 'c');
    std::vector<char> y(5, 'c');
    std::vector<char> z(5, 'c');
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
    std::vector<int> x;
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
    std::vector<int> test;
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
    std::vector<int> vec1;
    vec1.push_back(5);
    std::vector<int> vec2;
    vec1.swap(vec2);
    assert(vec2.at(0) == 5);
    assert(vec2.capacity() == 1);
    assert(vec2.size() == 1);
    assert(vec1.capacity() == 0);
    assert(vec1.size() == 0);
  }
  {
    std::vector<int> vec1;
    vec1.push_back(5);
    std::vector<int> vec2;
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
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    assert(vec.capacity() == 4 && vec.size() == 3);
    vec.clear();
    assert(vec.capacity() == 4 && vec.size() == 0);
    std::cout << "testing clear() method :: pass\n";
  }
  {
    std::vector<int> vec;
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
    std::vector<int> x;
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
    std::vector<int> x;
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
    std::vector<int> x;
    x.push_back(10);
    x.push_back(10);
    x.assign(0, 0);
    assert(x.capacity() == 2 && x.size() == 0);
    std::cout << "testing assign() method :: pass\n";
  } 


  std::cerr << "all passed\n";
  system("leaks a.out");
  return 0;
}
