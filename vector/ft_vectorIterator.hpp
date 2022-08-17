/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectorIterator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <orahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:41:55 by orahmoun          #+#    #+#             */
/*   Updated: 2022/08/15 10:41:57 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../iterators_traits.hpp"

namespace ft {
template <typename T> class vectorIterator {
protected:
  T *p;
  vectorIterator(const long t) { (void)t; };

public:
  typedef typename ft::iterator_traits<T *>::difference_type difference_type;
  typedef typename ft::iterator_traits<T *>::value_type value_type;
  typedef typename ft::iterator_traits<T *>::pointer pointer;
  typedef typename ft::iterator_traits<T *>::reference reference;
  typedef
      typename ft::iterator_traits<T *>::iterator_category iterator_category;

  explicit vectorIterator() : p(nullptr){};

  explicit vectorIterator(T *t) : p(t){};

  template <class iterator>
  vectorIterator(const iterator &src) : p(src.base()){};

  ~vectorIterator(){};
  template <class iterator> iterator &operator=(const iterator &src) {
    if (this == &src)
      return *this;
    p = src.p;
    return *this;
  };

  pointer base() { return p; };

  const pointer base() const { return p; };

  bool operator==(const vectorIterator &src) const { return src.base() == p; };

  bool operator!=(const vectorIterator &src) const {
    return !(src.base() == p);
  };

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

  bool operator!=(const pointer ptr) const { return p != ptr; };

  bool operator<(const vectorIterator &t) const { return p < t.p; };

  bool operator>(const vectorIterator &t) const { return p > t.p; };

  bool operator<=(const vectorIterator &t) const { return p <= t.p; };

  bool operator>=(const vectorIterator &t) const { return p >= t.p; };

  void operator+=(const difference_type v) { p += v; };

  void operator-=(const difference_type v) { p -= v; };

  reference operator[](const difference_type i) { return *(p + i); }

  const reference operator[](const difference_type i) const { return *(p + i); }
};

template <typename T, class iter> class reverseVectorIterator {
private:
  iter base_iter;
  reverseVectorIterator(const long t) : iter(t){};

public:
  typedef typename iter::difference_type difference_type;
  typedef typename iter::value_type value_type;
  typedef typename iter::pointer pointer;
  typedef typename iter::reference reference;
  typedef typename iter::iterator_category iterator_category;

public:
  explicit reverseVectorIterator() : base_iter(){};

  explicit reverseVectorIterator(T *t) : base_iter(t){};

  template <class iterator>
  reverseVectorIterator(const iterator &src) : base_iter(src){};

  ~reverseVectorIterator(){};
  template <class iterator> iterator &operator=(const iterator &src) {
    if (this == &src)
      return *this;
    base_iter = src;
    return *this;
  };

  iter base() { return base_iter; };

  const iter base() const { return base_iter; };

  bool operator==(const reverseVectorIterator &src) const {
    return base_iter == src.base();
  };

  bool operator!=(const reverseVectorIterator &src) const {
    return !(base_iter == src.base());
  };

  reference operator*() { return *(base_iter - 1); };

  const reference operator*() const { return *(base_iter - 1); };

  reference operator->() { return *(base_iter - 1); };

  const reference operator->() const { return *(base_iter - 1); };

  reverseVectorIterator operator++(int) { return base_iter--; }; // post

  reverseVectorIterator &operator++() {
    --base_iter;
    return *this;
  }; // pre

  reverseVectorIterator operator--(int) { return base_iter++; };

  reverseVectorIterator &operator--() {
    ++base_iter;
    return *this;
  };

  reverseVectorIterator operator-(const difference_type v) const {
    return base_iter + v;
  };

  reverseVectorIterator operator+(const difference_type v) const {
    return base_iter - v;
  };

  bool operator<(const reverseVectorIterator &t) const {
    return base_iter > t.base();
  };

  bool operator>(const reverseVectorIterator &t) const {
    return base_iter < t.base();
  };

  bool operator<=(const reverseVectorIterator &t) const {
    return base_iter >= t.base();
  };

  bool operator>=(const reverseVectorIterator &t) const {
    return base_iter <= t.base();
  };

  void operator+=(const difference_type v) { base_iter -= v; };

  void operator-=(const difference_type v) { base_iter += v; };
};
}; // namespace ft
