/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <orahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:41:59 by orahmoun          #+#    #+#             */
/*   Updated: 2022/08/15 10:42:37 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../enable_if.hpp"
#include "../equal.hpp"
#include "../includes.hpp"
#include "../lexicographical_compare.hpp"
#include "../is_same.hpp"
#include "ft_vectorIterator.hpp"

namespace ft {
template <class Type, class Allocator = std::allocator<Type> > class vector {
public:
  // TYPE DEFINITIONS
  typedef Allocator allocator_type;
  typedef std::size_t size_type;
  typedef Type value_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;

  typedef ft::vectorIterator<Type> iterator;
  typedef ft::reverseVectorIterator<Type, iterator> reverse_iterator;
  typedef ft::vectorIterator<const Type> const_iterator;
  typedef ft::reverseVectorIterator<const Type, iterator>
      const_reverse_iterator;

  // ERROR HANDLING
  static_assert(
      (ft::is_same<value_type, typename allocator_type::value_type>::value),
      "Incompatible type between the allocator and the class type");

private:
  value_type *allocate(size_type n) {
    try {
      return _alloc.allocate(n);
    } catch (std::length_error &e) {
      throw std::length_error("vector");
    } catch (std::exception &e) {
      throw e;
    }
  }

public:
  // CONSTRUCTORS
  explicit vector(const allocator_type &alloc = allocator_type())
      : _size(0), _capacity(0), _array(NULL), _alloc(allocator_type()) {}

  explicit vector(size_type n, const value_type &val = value_type(),
                  const allocator_type &alloc = allocator_type())
      : _size(n), _capacity(n), _alloc(allocator_type()) {
    _array = allocate(n);
    for (size_type i = 0; i < n; ++i) {
      _array[i] = val;
    }
  };

  template <class InputIterator>
  vector(typename ft::enable_if<
             InputIterator, std::is_class<InputIterator>::value>::type first,
         InputIterator last, const allocator_type &alloc = allocator_type())
      : _array(NULL), _capacity(0), _size(0) {
    for (InputIterator iter = first; iter != last; ++iter) {
      push_back(*iter);
    }
  };

  vector(const vector &src)
      : _size(src.size()), _capacity(src.capacity()),
        _alloc(src.get_allocator()) {
    *this = src;
  };

  // DESTRUCTOR
  ~vector() {
    if (_array == NULL)
      return;
    clear();
    _alloc.deallocate(_array, _capacity);
  };

  // Operators overloading ::
  vector &operator=(const vector &x) {
    if (&x == this)
      return *this;
    assign(x.begin(), x.end());
    _alloc = x._alloc;
    return *this;
  };

  reference operator[](size_type n) { return _array[n]; };

  const_reference operator[](size_type n) const { return _array[n]; };

  // OTHER METHODS
  // Capacity:
  size_type size() const { return _size; };

  size_type max_size() const {
    if (std::is_same<value_type, char>::value)
      return _alloc.max_size() / 2;
    return _alloc.max_size();
  };

  void resize(size_type n, value_type val = value_type()) {
    if (n < _size) {
      for (int i = n; i < _size; ++i) {
        _alloc.destroy(_array + i);
        _size--;
      }
    } else if (n > _capacity) {
      reserve(n);
    }
    for (int i = _size; i < n; ++i) {
      _array[i] = val;
      _size++;
    }
  };

  size_type capacity() const { return _capacity; };

  bool empty() const { return _size == 0; };

  void reserve(size_type n) {
    if (n < _capacity)
      return;
    value_type *tmp = allocate(n);
    if (_array != NULL) {
      memset(tmp, 0, sizeof(value_type) * n);
      memcpy(tmp, _array, sizeof(value_type) * _size);
      _alloc.deallocate(_array, _capacity);
    }
    _array = tmp;
    _capacity = n;
  };

  // Element access
  reference at(size_type n) {
    if (n >= _size)
      throw std::out_of_range("vector");
    return _array[n];
  };

  const_reference at(size_type n) const {
    if (n >= _size)
      throw std::out_of_range("vector");
    return _array[n];
  };

  reference front() { return _array[0]; };

  const_reference front() const { return _array[0]; };

  reference back() { return _array[_size - 1]; };

  const_reference back() const { return _array[_size - 1]; };

  //  Modifiers
  template <class InputIterator>
  void assign(
      typename ft::enable_if<InputIterator,
                             std::is_class<InputIterator>::value>::type first,
      InputIterator last) {
    clear();
    insert(begin(), first, last);
  };

  void assign(size_type n, const value_type &val) {
    clear();
    resize(n, val);
  };

  void push_back(const value_type &val) {
    if (_size == _capacity)
      reserve(_capacity == 0 ? 1 : _capacity * 2);
    _array[_size++] = val;
  };

  void pop_back() {
    --_size;
    if (_array == NULL)
      return;
    _alloc.destroy(&_array[_size - 1]);
  };

  void swap(vector &x) {
    std::swap(x._array, _array);
    std::swap(x._size, _size);
    std::swap(x._capacity, _capacity);
    std::swap(x._alloc, _alloc);
  };

  void clear() {
    while (_size) {
      _alloc.destroy(_array + _size - 1);
      --_size;
    }
  };

  iterator insert(iterator position, const value_type &val) {
    if (position == NULL && _array == NULL) {
      push_back(val);
      return begin();
    }
    size_type index = position.base() - _array;
    if (_size == _capacity)
      reserve(_capacity + 1);
    for (size_type i = size() - 1; i != (index - 1); --i) {
      _array[i + 1] = _array[i];
    }
    _array[index] = val;
    ++_size;
    return position - 1;
  };

  void insert(iterator position, size_type n, const value_type &val) {
    if (_array == NULL && position == NULL) {
      push_back(val);
      --n;
      position = end();
    }
    size_type len = position.base() - _array;
    for (size_type i = 0; i < n; ++i) {
      iterator v = begin() + len;
      insert(v, val);
    }
  };

  template <class InputIterator>
  void insert(
      iterator position,
      typename ft::enable_if<InputIterator,
                             std::is_class<InputIterator>::value>::type first,
      InputIterator last) {
    if (_array == NULL && position == NULL) {
      push_back(*first);
      ++first;
      position = end();
    }
    size_type len = position.base() - _array;
    while (last != first) {
      iterator v = begin() + len;
      insert(v, *first);
      ++first;
      ++len;
    }
  }

  iterator erase(iterator position) {
    size_type index = position.base() - _array;
    _alloc.destroy(_array + index);
    for (size_type i = index; i < _size - 1; ++i) {
      _array[i] = _array[i + 1];
    }
    --_size;
    return position;
  };

  iterator erase(iterator first, iterator last) {
    while (first != last) {
      erase(first);
      --last;
    }
    return first;
  };

  // Allocator
  allocator_type get_allocator() const { return _alloc; };

  // iterator
  iterator begin() { return iterator(_array); };
  const_iterator begin() const { return iterator(_array); };
  iterator end() { return iterator(_array + _size); };
  const_iterator end() const { return iterator(_array + _size); };
  reverse_iterator rbegin() { return reverse_iterator(_array + _size); };
  reverse_iterator rend() { return reverse_iterator(_array); };
  // Attributes
private:
  value_type *_array;
  size_type _size;
  size_type _capacity;
  allocator_type _alloc;
};

template <class T, class Alloc>
bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
  if (lhs.size() != rhs.size())
    return false;
  return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
};

template <class T, class Alloc>
bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
  return !(lhs == rhs);
};

template <class T, class Alloc>
bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
  return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                     rhs.end());
};

template <class T, class Alloc>
bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
  return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                     rhs.end()) ||
         ft::equal(lhs.begin(), lhs.end(), rhs.begin());
};

template <class T, class Alloc>
bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
  return !ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                     rhs.end());
};

template <class T, class Alloc>
bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
  return !ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                     rhs.end()) ||
         ft::equal(lhs.begin(), lhs.end(), rhs.begin());
};
} // namespace ft
