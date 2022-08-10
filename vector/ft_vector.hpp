#pragma once
#include "../helper.hpp"
#include <iostream>

namespace ft {

// template <class Type, class Allocator = std::allocator<Type> > class vector {
//   // Type definitions ::
//   typedef Allocator allocator_type;
//   typedef std::size_t size_type;
//   typedef Type value_type;
//   typedef typename allocator_type::reference reference;
//   typedef typename allocator_type::const_reference const_reference;

//   // Error handling ::
//   static_assert((std::is_same<value_type, typename
//   allocator_type::value_type>::value),
//                   "Incompatible type between the allocator and the class
//                   type");

//   // Constructors ::
//   explicit vector(const allocator_type &alloc = allocator_type()); // default
//   explicit vector(size_type n, const value_type &val = value_type(),
//                   const allocator_type &alloc = allocator_type()); // fill
//                   constructor
//   // Todo range constructor
//   // template <class InputIterator>
//   //        vector (InputIterator first, InputIterator last,
//   //                const allocator_type& alloc = allocator_type());
//   // Todo range constructor
//   vector(const vector &x); // copy constructor
//   // Destructor ::
//   ~vector();

//   // Operators overloading ::
//   vector& operator= (const vector& x);
//   reference operator[] (size_type n);
//   const_reference operator[] (size_type n) const;

//   // Other Methods ::
//     // Capacity:
//     size_type size() const;
//     size_type max_size() const;
//     void resize (size_type n, value_type val = value_type());
//     size_type capacity() const;
//     bool empty() const;
//     void reserve (size_type n);
//     // Element access:
//      reference at (size_type n);
//     const_reference at (size_type n) const;
//     reference front();
//     const_reference front() const;
//     reference back();
//     const_reference back() const;
//    //  Modifiers ::
//     template <class InputIterator>
//     void assign (InputIterator first, InputIterator last);
//     void assign (size_type n, const value_type& val);
//     void push_back (const value_type& val);
//     void pop_back();
//     void swap (vector& x);
//     void clear();
//     template <class... Args>
//     void emplace_back (Args&&... args);
//   // to do
//     // iterator insert (iterator position, const value_type& val);
//     // void insert (iterator position, size_type n, const value_type& val);
//     // template <class InputIterator>
//     // void insert (iterator position, InputIterator first, InputIterator
//     last);
//     // iterator erase (iterator position);
//     // iterator erase (iterator first, iterator last);
//     // template <class... Args>
//     // iterator emplace (const_iterator position, Args&&... args);
//   // to do

//     // Allocator
//     allocator_type get_allocator() const;

//   // Attributes ::
//   private:
//     value_type *_array;
//     size_type _size;
//     size_type _capacity;
//     allocator_type _alloc;
// };
// } // namespace ft

template <class Type, class Allocator = std::allocator<Type> > class vector {
  // Type definitions ::
  typedef Allocator allocator_type;
  typedef std::size_t size_type;
  typedef Type value_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;

  // Error handling ::
  static_assert(
      std::is_same<value_type, typename allocator_type::value_type>::value,
      "Incompatible type between the allocator and the class type");

public:
  // Constructors ::
  explicit vector(const allocator_type &alloc = allocator_type())
      : _size(0), _capacity(0), _alloc(allocator_type()) {
#ifdef DEBUG
    std::cerr << "def const of vector with size " << _size << " and capacity "
              << _capacity << '\n';
#endif
    _array = NULL;
  }

  explicit vector(size_type n, const value_type &val = value_type(),
                  const allocator_type &alloc = allocator_type())
      : _size(n), _capacity(n), _alloc(allocator_type()) {
#ifdef DEBUG
    std::cerr << "const(n) of vector with size " << _size << " and capacity "
              << _capacity << '\n';
#endif
    try {
      _array = _alloc.allocate(n * sizeof(value_type));
    } catch (std::length_error &e) {
      throw std::length_error("vector");
    }
    for (std::size_t i = 0; i < _capacity; i++) {
      _array[i] = val;
    }
  };

  // Todo range constructor
  // template <class InputIterator>
  //        vector (InputIterator first, InputIterator last,
  //                const allocator_type& alloc = allocator_type());
  // Todo range constructor
  vector(const vector &x); // copy constructor
  // Destructor ::
  ~vector() {
#ifdef DEBUG
    std::cerr << "des of vector with size " << _size << " and capacity "
              << _capacity << '\n';
#endif
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
    _array = _alloc.allocate(sizeof(value_type) * x._capacity);
    memcpy(_array, x._array, sizeof(value_type) * x._capacity);
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
  void resize(size_type n, value_type val = value_type()){

      // #ifdef DEBUG
      //     std::cerr << "resize method with size " << _size << " and value "
      //               << val << '\n';
      // #endif
      //     try {
      //       _array = _alloc.allocate(n * sizeof(value_type));
      //     } catch (std::length_error &e) {
      //       throw std::length_error("vector");
      //     }
      //     for (std::size_t i = 0; i < _capacity; i++) {
      //       _array[i] = val;
      //     }
  };
  size_type capacity() const { return _capacity; };
  bool empty() const { return _size == 0; };
  void reserve(size_type n) {
    if (n < _capacity)
      return;
    value_type *tmp = _alloc.allocate(sizeof(value_type) * n);
    memset(tmp, 0, sizeof(value_type) * n);
    memcpy(tmp, _array, _capacity);
    _alloc.deallocate(_array, _capacity);
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
  // template <class InputIterator>
  // void assign(InputIterator first, InputIterator last);
  void assign(size_type n, const value_type &val);
  void push_back(const value_type &val) {
    if (_size == _capacity) {
      if (_capacity == 0)
        _capacity = 1;
      else
        _capacity *= 2;
      value_type *tmp = _alloc.allocate(sizeof(value_type) * _capacity);
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
  void pop_back();
  void swap(vector &x);
  void clear();
  // to do
  // iterator insert (iterator position, const value_type& val);
  // void insert (iterator position, size_type n, const value_type& val);
  // template <class InputIterator>
  // void insert (iterator position, InputIterator first, InputIterator last);
  // iterator erase (iterator position);
  // iterator erase (iterator first, iterator last);
  // template <class... Args>
  // iterator emplace (const_iterator position, Args&&... args);
  // to do

  // Allocator
  allocator_type get_allocator() const;

  // Attributes ::
private:
  value_type *_array;
  size_type _size;
  size_type _capacity;
  allocator_type _alloc;
};
} // namespace ft
