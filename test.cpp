// #include "helper.hpp"
#include <exception>
#include <iostream>
#include <memory>
#include <vector>
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
//   // I guess it's trying to cast it and use the fill one but in that pros he
//   finds that it's not a simple type!

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

// int main() {
//   // std::vector<int> arr(50);
//   // std::cout << arr[0] << '\n';
//   // std::cout << arr[1] << '\n';
//   // std::cout << arr[2] << '\n';
//   // std::cout << arr[3] << '\n';
//   // std::cout << arr[4] << '\n';
//   // // std::vector<int> t;
//   // // std::cout << t.empty() << '\n';
//   // // t.reserve(5);
//   // // std::cout << t.empty() << '\n';
//   // // t.push_back(1);
//   // // std::cout << t.empty() << '\n';
//   // // t.pop_back();
//   // // std::cout << t.empty() << '\n';
//   // std::cout << arr.at(0) << '\n';
//   // std::cout << arr.at(10) << '\n';

//   // std::vector<int> arr2;
//   // arr2.push_back(5);
//   // arr2.push_back(2);
//   // std::cout << arr2.front() << '\n';
//   // std::cout << arr2.back() << '\n';

//   // arr2.push_back(1);
//   // arr2.push_back(1);
//   // arr2.push_back(1);
//   // arr2.push_back(1);
//   // arr2.push_back(1);
//   // std::cout << arr2.at(0) << " " << arr2.capacity() << '\n';
//   // std::cout << arr2.at(6) << " " << arr2.capacity() << '\n';

//   std::allocator<int> st;
//   int *arr = st.allocate(sizeof(int) * 5);
//   std::cout << arr[0] << '\n';
//   std::cout << arr[1] << '\n';
//   std::cout << arr[2] << '\n';
//   std::cout << arr[3] << '\n';
//   std::cout << arr[4] << '\n';

// }

// struct A {
//   static int id;
//   int x;
//   A() : x(id) {
//     id++;
//     std::cerr << "const" << std::endl;
//   }
//   ~A() { std::cerr << "dest" << std::endl; }
//   A(const A &src) { std::cerr << "copy" << std::endl; }
// };
// int A::id = 0;

// int main() {
//   // std::allocator<A> st;
//   // A *arr = st.allocate(sizeof(A) * 5);
//   // st.destroy(arr);
//   // st.destroy(arr + 1);
//   // st.destroy(arr + 2);
//   // st.destroy(arr + 3);
//   // st.destroy(arr + 4);
//   A y; // dest
//   std::vector<A> x;
//   x.push_back(y); // dest
//   x.push_back(y); // dest
//   std::vector<A> test;
//   test.push_back(y); // dest
//   test.push_back(y); // dest
//   test = x;
//   // std::vector<A> test;
//   // test.push_back(y); // dest
//   // test.push_back(y); // dest
//   // std::cerr  << "before assi" << std::endl;
//   // // test = x;
//   // std::cerr  << "after assi" << std::endl;
//   // std::cerr << "before" << std::endl;
//   std::cerr << "end\n";
// }

// int main() {
//   std::vector<A> x;
//   x.push_back(A());
//   x.push_back(A());
//   x.push_back(A());
//   // std::cerr << x.size() << ' ' << x.capacity() << '\n';
//   std::cerr << "pop\n";
//   x.pop_back();
//   std::cerr << "out\n";
// }

// int main() {
//   std::vector<int> x;
//   x.push_back(1);
//   x.push_back(1);
//   x.push_back(1);
//   std::cout << x.capacity() << ' ' << x.size() << '\n';
//   std::cout << "before resize\n";
//   std::cout << x.capacity() << ' ' << x.size() << '\n';
//   x.resize(0, 0);
//   std::cout << "after resize\n";
//   std::cout << x.capacity() << ' ' << x.size() << '\n';
// //
// }

// int main() {
//   std::string str {"hello"};
//   std::string str2 = "";
//   memcpy(&str2, &str, sizeof(std::string));
//   std::cout << str << '\n';
//   std::cout << str2 << '\n';
//   memset(&str2, 0, sizeof(std::string));
//   std::cout << str2 << '\n';
//   memset(&str2, (char)1, sizeof(std::string));
//   std::cout << str2 << '\n';
// }
#include <array>
#include <deque>
#include <list>
#include <set>
using namespace std;
int main() {
  // {
  //   array<int, 2> x = {1, 2};
  //   auto b = x.begin();
  //   auto e = x.end();
  //   if (b > e) {
  //     cout << "hello\n";
  //   };
  // }
  // {
  //   deque<int> x{1, 2};
  //   auto b = x.begin();
  //   auto e = x.end();
  //   if (b > e) {
  //     cout << "hello\n";
  //   };
  // }
  // {
  //   list<int> x{1, 2};
  //   auto b = x.begin();
  //   auto e = x.end();
  //   // if (b > e) {cout << "hello\n";};
  // }
  {
    // set<int, std::greater<int>> x;
    // x.insert(1);
    // x.insert(10);
    // x.insert(2);
    // x.insert(6);
    // x.insert(1);
    // for (auto i : x) {
    //   cout << i << "\n";
    // }
    vector<int> y = {1,2,3,4,5,6};
    sort(y.begin(), y.end(), [](int x, int y) {return y > x;});
    for (auto i : y) {
      cout << i << "\n";
    }
    // auto b = x.begin();
    // auto e = x.end();
    // if (b > e) {
    //   cout << "hello\n";
    // };
  }
}
