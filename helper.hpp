#pragma once

/////// INCLUDES ///////////
#include <cstring>
#include <exception>
#include <iostream>
#include <memory>
#include <string.h>
#include <type_traits>

namespace ft {

template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T *, class Reference = T &>
class Iter {
public:
  typedef T value_type;
  typedef Distance difference_type;
  typedef Pointer pointer;
  typedef Reference reference;
  typedef Category iterator_category;
};

template <class Iter> struct iterator_traits {
  typedef typename Iter::difference_type difference_type;
  typedef typename Iter::value_type value_type;
  typedef typename Iter::pointer pointer;
  typedef typename Iter::reference reference;
  typedef typename Iter::iterator_category iterator_category;
};

template <class T> class iterator_traits<T *> {
  typedef ptrdiff_t difference_type;
  typedef T value_type;
  typedef T *pointer;
  typedef T &reference;
  typedef std::random_access_iterator_tag iterator_category;
};
// enable_if
template <typename T, bool> class enable_if {};

template <typename T> class enable_if<T, true> {
public:
  typedef T type;
};
} // namespace ft
