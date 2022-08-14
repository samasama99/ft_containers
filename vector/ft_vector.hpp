#pragma once
#include "../helper.hpp"
#include "ft_vectorIterator.hpp"

namespace ft {
template <class Type, class Allocator = std::allocator<Type> > class vector {
public:
  // Type definitions ::
  typedef Allocator allocator_type;
  typedef std::size_t size_type;
  typedef Type value_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;

  typedef ft::vectorIterator<Type> iterator;
  typedef ft::vectorIterator<const Type> const_iterator;

  // Error handling ::
  static_assert(
      (std::is_same<value_type, typename allocator_type::value_type>::value),
      "Incompatible type between the allocator and the class type");

  // Constructors ::
  explicit vector(const allocator_type &alloc = allocator_type())
      : _size(0), _capacity(0), _alloc(allocator_type()) {
    _array = NULL;
  }

  explicit vector(size_type n, const value_type &val = value_type(),
                  const allocator_type &alloc = allocator_type())
      : _size(n), _capacity(n), _alloc(allocator_type()) {
    try {
      _array = _alloc.allocate(n);
    } catch (std::length_error &e) {
      throw std::length_error("vector");
    }
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
  vector(const vector &x); // copy constructor
  // Destructor ::
  ~vector() {
    if (_array == NULL)
      return;
    for (int i = 0; i < _size; ++i)
      _alloc.destroy(_array + i);
    _alloc.deallocate(_array, _capacity);
  };

  // Operators overloading ::
  vector &operator=(const vector &x) {
    if (&x == this)
      return *this;
    if (_array != NULL) {
      for (int i = 0; i < _size; ++i)
        _alloc.destroy(_array + i);
      _alloc.deallocate(_array, _capacity);
      _array = NULL;
    }
    _array = _alloc.allocate(x._capacity);
    memcpy(_array, x._array, x._capacity);
    _capacity = x._capacity;
    _size = x._size;
    _alloc = x._alloc;
    return *this;
  };
  reference operator[](size_type n) { return _array[n]; };

  const_reference operator[](size_type n) const { return _array[n]; };

  // Other Methods ::
  // Capacity:
  size_type size() const { return _size; };
  size_type max_size() const { return _alloc.max_size(); };
  void resize(size_type n, value_type val = value_type()) {
    if (n < _size) {
      for (int i = n; i < _size; ++i) {
        _alloc.destroy(_array + i);
        _size--;
      }
    } else if (n > _capacity) {
      value_type *tmp = _alloc.allocate(n);
      if (_array != NULL) {
        memcpy(tmp, _array, sizeof(value_type) * _size);
        for (int i = _size; i < n; ++i) {
          tmp[i] = val;
          _size++;
        }
      }
      _alloc.deallocate(_array, _capacity);
      _array = tmp;
      _capacity = _size = n;
    } else if (n > _size) {
      for (int i = _size; i < n; ++i) {
        _array[i] = val;
        _size++;
      }
    }
  };
  size_type capacity() const { return _capacity; };
  bool empty() const { return _size == 0; };
  void reserve(size_type n) {
    if (n < _capacity)
      return;
    value_type *tmp = _alloc.allocate(n);
    if (_array != NULL) {
      memset(tmp, 0, sizeof(value_type) * n);
      memcpy(tmp, _array, sizeof(value_type) * _size);
      _alloc.deallocate(_array, _capacity);
    }
    _array = tmp;
    _capacity = n;
  };
  // Element access:
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
  //  Modifiers ::
  template <class InputIterator>
  void assign(
      typename ft::enable_if<InputIterator,
                             std::is_class<InputIterator>::value>::type first,
      InputIterator last) {
    size_type index = 0;
    size_type len = 0;
    for (InputIterator iter = first; iter != last; ++iter) {
      ++len;
    }
    if (len < _capacity) {
      for (InputIterator iter = first; iter != last; ++iter) {
        while (index < _size)
          _alloc.destroy(_array + index);
        _array[index] = *iter;
        ++index;
      }
      if (index >= _size)
        _size = len;
    } else {
      for (size_type i = 0; i < _size; i++)
        _alloc.destroy(_array + i);
      _alloc.deallocate(_array, _capacity);
      _array = _alloc.allocate(len);
      index = 0;
      for (InputIterator iter = first; iter != last; ++iter) {
        _array[index] = *iter;
        ++index;
      }
      _capacity = _size = len;
    }
  };
  void assign(size_type n, const value_type &val) {
    if (_capacity >= n) {
      for (int i = 0; i < n; ++i) {
        _alloc.destroy(&_array[i]);
        _array[i] = val;
      }
      _size = n;
    } else {
      if (_array != NULL) {
        for (int i = 0; i < _size; ++i) {
          _alloc.destroy(&_array[i]);
        }
        _alloc.deallocate(_array, _capacity);
      }
      _array = _alloc.allocate(n);
      for (int i = 0; i < n; ++i) {
        _array[i] = val;
      }
      _capacity = _size = n;
    }
  };
  void push_back(const value_type &val) {
    if (_size == _capacity) {
      if (_capacity == 0)
        _capacity = 1;
      else
        _capacity *= 2;
      value_type *tmp = _alloc.allocate(_capacity);
      if (_array != NULL) {
        memcpy(tmp, _array, sizeof(value_type) * _capacity);
        for (int i = 0; i < _size; ++i)
          _alloc.destroy(_array + i);
        _alloc.deallocate(_array, _capacity);
        _array = NULL;
      }
      _array = tmp;
    }
    _array[_size] = val;
    ++_size;
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
      _alloc.destroy(&_array[_size - 1]);
      --_size;
    }
  };
  iterator insert(iterator position, const value_type &val) {
    if (position == NULL && _array == NULL) {
      push_back(val);
      return begin();
    }
    size_type index = 0;
    for (iterator iter = begin(); iter != position; ++iter) {
      ++index;
    }
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
  // todo
  iterator erase(iterator position) {
    size_type index = position.base() - begin().base();
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
  // todo

  // Allocator
  allocator_type get_allocator() const { return _alloc; };

  // iterator
  iterator begin() { return iterator(_array); };
  const_iterator begin() const { return iterator(_array); };
  iterator end() { return iterator(_array + _size); };
  const_iterator end() const { return iterator(_array + _size); };
  // Attributes ::
private:
  value_type *_array;
  size_type _size;
  size_type _capacity;
  allocator_type _alloc;
};
} // namespace ft
