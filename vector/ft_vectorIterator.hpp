#pragma once
#include "../helper.hpp"

namespace ft {

template <typename T> class vectorIterator {
  T *p;

public:
  typedef typename ft::iterator_traits<
      ft::Iter<std::random_access_iterator_tag, T> >::difference_type
      difference_type;
  typedef typename ft::iterator_traits<
      ft::Iter<std::random_access_iterator_tag, T> >::value_type value_type;
  typedef typename ft::iterator_traits<
      ft::Iter<std::random_access_iterator_tag, T> >::pointer pointer;
  typedef typename ft::iterator_traits<
      ft::Iter<std::random_access_iterator_tag, T> >::reference reference;
  typedef typename ft::iterator_traits<
      ft::Iter<std::random_access_iterator_tag, T> >::iterator_category
      iterator_category;

  explicit vectorIterator() : p(NULL){};
  explicit vectorIterator(T *t) : p(t){};
  vectorIterator(const vectorIterator &src) { *this = src; };
  ~vectorIterator(){};
  vectorIterator &operator=(const vectorIterator &src) {
    if (this == &src)
      return *this;
    p = src.p;
    return *this;
  };
  // T *base() {return p;};

  bool operator==(const vectorIterator &src) const { return src.p == p; };
  bool operator!=(const vectorIterator &src) const { return !(src.p == p); };

  reference operator*() { return *p; };
  const reference operator*() const { return *p; };
  reference operator->() { return *p; };
  const reference operator->() const { return *p; };

  vectorIterator operator++(int) {
    vectorIterator<int> tmp(*this);
    ++p;
    return tmp;
  }; // post
  vectorIterator &operator++() {
    ++p;
    return *this;
  }; // pre
  const vectorIterator &operator++() const {
    ++p;
    return *this;
  }; // pre
  //
  vectorIterator operator--(int) {
    vectorIterator<int> tmp(*this);
    --p;
    return tmp;
  };
  vectorIterator &operator--() {
    --p;
    return *this;
  };
  const vectorIterator &operator--() const {
    --p;
    return *this;
  };

  vectorIterator operator-(difference_type v) { return vectorIterator(p - v); };
  vectorIterator operator+(difference_type v) { return vectorIterator(p + v); };

  bool operator==(pointer ptr) { return p == ptr;};
  bool operator<(const vectorIterator &t) { return p < t.p;};
  bool operator>(const vectorIterator &t) { return p > t.p;};
  bool operator<=(const vectorIterator &t) { return p <= t.p;};
  bool operator>=(const vectorIterator &t) { return p >= t.p;};
  bool operator+=(difference_type v) { p += v;};
  bool operator-=(difference_type v) { p -= v;};

  reference operator[](difference_type i) {
    return *(p + i);
  }
};
} // namespace ft
