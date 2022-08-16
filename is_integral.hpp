#include "includes.hpp"

namespace ft {
template <typename T> struct is_integral {
  typedef T value_type;
  static const bool value = std::numeric_limits<T>::is_integer;
};
}; // namespace ft
