#include "helper.hpp"
#include <iostream>
#include <memory>
#include <vector>
#include <exception>
// template <typename T> class A {
// public:
//   typedef T number;
//   // typedef int num;

// public:
//   int x;
//   A(int x) : x(x) {}
//   // explicit A(int x) : x(x) {}
// };

// template <class T, class Type = A<T>> class B {
//   typedef typename A<T>::number Num;
//   typedef T myType;
//   B();
// };

// // template <typename T> class vector {};
// // template <class T> class vector {};

// // int f(A a) { return a.x; }
// int f(std::vector<int> a) { return a.size(); }

// int main() {
//   std::vector<char> vecChar{'a', 'b'};
//   std::vector<int> vecInt{1, 2};
//   std::vector<double> vecDouble{1.1, 12.2, 0.5};
//   std::size_t test1{vecChar.size()};
//   std::size_t test2{vecInt.size()};
//   std::size_t test3{vecDouble.size()};
//   std::cout << test1 << ' ' << sizeof(test1) << ' '
//             << sizeof(std::vector<char>::size_type) << '\n';
//   std::cout << test2 << ' ' << sizeof(test2) << ' '
//             << sizeof(std::vector<int>::size_type) << '\n';
//   std::cout << test3 << ' ' << sizeof(test3) << ' '
//             << sizeof(std::vector<double>::size_type) << '\n';
//   // std::cout << f(A(5)) << '\n';
//   // std::cout << f(5) << '\n';
//   // std::cout << f(5) << '\n';
//   return 0;
// }
// vector() : _size(0) , alloc(alloc_type()), .....
// class A {
//   public:
//   int x;
//   A() {std::cout << "here con" << '\n';};
//   ~A() {std::cout << "here des" << '\n';};
// };
// int main() {
//     // std::length_error e;
//   // std::allocator<A> alloc;
//   // std::vector<int> t(4611686018427387903 - 1);
//   // std::cout << t.max_size() << '\n';
//   // int x = int(5);
//   // std::vector<int> vec1;
//   // std::vector<int> vec2(alloc);
//   // std::vector<int> vec3(std::allocator<int>{});
//   // vector instance of the allocator
//   // I guess it's trying to cast it and use the fill one but in that pros he finds that it's not a simple type!

//   // vec1.push_back(5);
//   // vec2.push_back(1);
//   // vec3.push_back(1);
//   // A *x = alloc.allocate(sizeof(A));
//   // alloc.destroy(x);
//   // alloc.deallocate(x, sizeof(A));
//   // x  = NULL;
//   // std::cout << x[0] << '\n';
//   // std::cout << x[1] << '\n';
//   // alloc.address();
//   // system("leaks a.out");
//   std::vector<int> tab;
//   std::cout << tab.capacity() << '\n';
//   tab.push_back(1);
//   std::cout << tab.capacity() << '\n';
//   tab.push_back(1);
//   std::cout << tab.capacity() << '\n';
//   tab.push_back(1);
//   std::cout << tab.capacity() << '\n';
//   tab.push_back(1);
//   std::cout << tab.capacity() << '\n';
//   tab.push_back(1);
//   std::cout << tab.capacity() << '\n';
//   tab.push_back(1);
//   std::cout << tab.capacity() << '\n';
//   tab.push_back(1);
//   std::cout << tab.capacity() << '\n';
//   tab.push_back(1);
//   std::cout << tab.capacity() << '\n';
//   tab.push_back(1);
//   std::cout << tab.capacity() << '\n';
//   tab.push_back(1);
//   std::cout << tab.capacity() << '\n';

//   std::vector<int> tab2(10);
//   std::cout << tab2.capacity() << '\n';
//   tab2.push_back(1);
//   std::cout << tab2.capacity() << '\n';
//   tab2.push_back(1);
//   tab2.push_back(1);
//   tab2.push_back(1);
//   tab2.push_back(1);
//   tab2.push_back(1);
//   tab2.push_back(1);
//   tab2.push_back(1);
//   tab2.push_back(1);
//   tab2.push_back(1);
//   tab2.push_back(1);
//   std::cout << tab2.capacity() << '\n';

//   return 0;
// }


int main() {
  std::vector<int> arr(5, 99);
  std::cout << arr[0] << '\n';
  std::cout << arr[1] << '\n';
  std::cout << arr[2] << '\n';
  std::cout << arr[3] << '\n';
  std::cout << arr[4] << '\n';
}
