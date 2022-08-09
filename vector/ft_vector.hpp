#pragma once
#include "../helper.hpp"

namespace ft {
template <class Type, class Allocator = std::allocator<Type> > class vector {
  // Type definitions ::
  typedef Allocator allocator_type;
  typedef std::size_t size_type;
  typedef Type value_type;



  // Error handling ::
  static_assert((std::is_same<value_type, typename allocator_type::value_type>::value),
                  "Incompatible type between the allocator and the class type");



  // Constructors ::
  explicit vector(const allocator_type &alloc = allocator_type()); // default
  explicit vector(size_type n, const value_type &val = value_type(),
                  const allocator_type &alloc = allocator_type()); // fill constructor
  // Todo range constructor
  // template <class InputIterator>
  //        vector (InputIterator first, InputIterator last,
  //                const allocator_type& alloc = allocator_type());
  // Todo range constructor
  vector(const vector &x); // copy constructor



  // Destructor ::
  ~vector();



  // Attributes ::
  // private:
  //   size_type _size;
  //   allocator_type _alloc;
};
} // namespace ft

