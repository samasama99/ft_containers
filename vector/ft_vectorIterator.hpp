#pragma once
#include "../helper.hpp"

namespace ft {
template <typename T> class vectorIterator {
  T *p;

public:
  typedef typename ft::iterator_traits<T *>::difference_type difference_type;
  typedef typename ft::iterator_traits<T *>::value_type value_type;
  typedef typename ft::iterator_traits<T *>::pointer pointer;
  typedef typename ft::iterator_traits<T *>::reference reference;
  typedef
      typename ft::iterator_traits<T *>::iterator_category iterator_category;

  explicit vectorIterator() : p(NULL){};
  explicit vectorIterator(T *t) : p(t){};
  template <class iterator> vectorIterator(const iterator &src) : p(&*src){};
  ~vectorIterator(){};
  template <class iterator> iterator &operator=(const iterator &src) {
    if (this == &src)
      return *this;
    p = src.p;
    return *this;
  };

  bool operator==(const vectorIterator &src) const { return src.p == p; };
  bool operator!=(const vectorIterator &src) const { return !(src.p == p); };

  reference operator*() { return *p; };
  const reference operator*() const { return *p; };
  reference operator->() { return *p; };
  const reference operator->() const { return *p; };

  vectorIterator operator++(int) {
    vectorIterator tmp(*this);
    ++p;
    return tmp;
  }; // post
  vectorIterator &operator++() {
    ++p;
    return *this;
  }; // pre
  vectorIterator operator--(int) {
    vectorIterator tmp(*this);
    --p;
    return tmp;
  };
  vectorIterator &operator--() {
    --p;
    return *this;
  };

  vectorIterator operator-(const difference_type v) const {
    return vectorIterator(p - v);
  };
  vectorIterator operator+(const difference_type v) const {
    return vectorIterator(p + v);
  };

  bool operator==(const pointer ptr) const { return p == ptr; };
  bool operator<(const vectorIterator &t) const { return p < t.p; };
  bool operator>(const vectorIterator &t) const { return p > t.p; };
  bool operator<=(const vectorIterator &t) const { return p <= t.p; };
  bool operator>=(const vectorIterator &t) const { return p >= t.p; };
  void operator+=(const difference_type v) { p += v; };
  void operator-=(const difference_type v) { p -= v; };

  reference operator[](const difference_type i) { return *(p + i); }
  const reference operator[](const difference_type i) const { return *(p + i); }
};
} // namespace ft
