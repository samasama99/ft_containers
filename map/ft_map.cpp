#include "../includes.hpp"
#include "../iterators_traits.hpp"
#include "../pair/ft_pair.hpp"
#include <iterator>

namespace ft {
template <class Key, class T, class Compare = std::less<Key>,
          class Alloc = std::allocator<ft::pair<const Key, T> > >
class map {
public:
  typedef Key key_type;
  typedef T mapped_type;
  typedef pair<const Key, T> value_type;
  typedef Compare key_compare;
  typedef Alloc allocator_type;
  typedef typename Alloc::reference reference;
  typedef typename Alloc::const_reference const_reference;
  typedef typename Alloc::pointer pointer;
  typedef typename Alloc::const_pointer const_pointer;
  typedef std::size_t size_type;

public:
  // constructors:
  explicit map(const key_compare &comp = key_compare(),
               const allocator_type &alloc = allocator_type()){};

  template <class InputIterator>
  map(InputIterator first, InputIterator last,
      const key_compare &comp = key_compare(),
      const allocator_type &alloc = allocator_type()){};

  map(const map &x){};
  // destructor:
  ~map();
  // operator=
  map &operator=(const map &x);
  // capacity:
  bool empty() const;
  size_type size() const;
  size_type max_size() const;
  mapped_type &operator[](const key_type &k);
  // pair<iterator, bool> insert(const value_type &val);
  // iterator insert(iterator position, const value_type &val);
  // template <class InputIterator>
  // void insert(InputIterator first, InputIterator last);
  // void erase(iterator position);
  // size_type erase(const key_type &k);
  // void erase(iterator first, iterator last);
  void swap(map &x);
  void clear();
  key_compare key_comp() const;
  // value_compare value_comp() const;
  // iterator find(const key_type &k);
  // const_iterator find(const key_type &k) const;
  // size_type count(const key_type &k) const;
  // iterator lower_bound(const key_type &k);
  // const_iterator lower_bound(const key_type &k) const;
  // iterator upper_bound(const key_type &k);
  // const_iterator upper_bound(const key_type &k) const;
  // pair<const_iterator, const_iterator> equal_range(const key_type &k) const;
  // pair<iterator, iterator> equal_range(const key_type &k);
  allocator_type get_allocator() const;

private:
};
} // namespace ft
