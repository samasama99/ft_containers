#include <includes.hpp>
#include "ft_setIterator.hpp"
#include "red_black_tree.hpp"

namespace ft {
template <class Key,
          class Compare = std::less<Key>,
          class Allocator = std::allocator<Key> >

class set {
   public:
    // types:
    typedef Key key_type;
    typedef key_type value_type;
    typedef Compare key_compare;
    typedef key_compare value_compare;
    typedef Allocator allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::size_type size_type;
    typedef typename allocator_type::difference_type difference_type;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;

    // typedef implementation - defined iterator;
    // typedef implementation - defined const_iterator;
    // typedef std::reverse_iterator<iterator> reverse_iterator;
    // typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    typedef ft::setIterator<tree_node<value_type> > iterator;
    typedef const ft::setIterator<tree_node<value_type> > const_iterator;

    typedef ft::reverseSetIterator<tree_node<value_type>, iterator>
        reverse_iterator;
    typedef const ft::reverseSetIterator<tree_node<value_type>, iterator>
        const_reverse_iterator;

    // construct/copy/destroy:
    set();
    explicit set(const value_compare& comp);
    set(const value_compare& comp, const allocator_type& a);
    template <class InputIterator>
    set(InputIterator first,
        InputIterator last,
        const value_compare& comp = value_compare());
    template <class InputIterator>
    set(InputIterator first,
        InputIterator last,
        const value_compare& comp,
        const allocator_type& a);
    set(const set& s);
    explicit set(const allocator_type& a);
    set(const set& s, const allocator_type& a);
    template <class InputIterator>
    set(InputIterator first, InputIterator last, const allocator_type& a)
        : set(first, last, Compare(), a) {}  // C++14
    ~set();

    set& operator=(const set& s);

    // iterators:
    // iterator begin();
    // const_iterator begin() const;
    // iterator end();
    // const_iterator end() const;

    // reverse_iterator rbegin();
    // const_reverse_iterator rbegin() const;
    // reverse_iterator rend();
    // const_reverse_iterator rend() const;

    // capacity:
    bool empty() const;
    size_type size() const;
    size_type max_size() const;

    // modifiers:
    pair<iterator, bool> insert(const value_type& v);
    iterator insert(const_iterator position, const value_type& v);
    template <class InputIterator>
    void insert(InputIterator first, InputIterator last);

    iterator erase(const_iterator position);
    size_type erase(const key_type& k);
    iterator erase(const_iterator first, const_iterator last);
    void clear();

    void swap(set& s);

    // observers:
    allocator_type get_allocator() const;
    key_compare key_comp() const;
    value_compare value_comp() const;

    // set operations:
    iterator find(const key_type& k);
    const_iterator find(const key_type& k) const;
    template <typename K>
    iterator find(const K& x);
    template <typename K>

    size_type count(const key_type& k) const;
    iterator lower_bound(const key_type& k);
    const_iterator lower_bound(const key_type& k) const;

    iterator upper_bound(const key_type& k);
    const_iterator upper_bound(const key_type& k) const;
    pair<iterator, iterator> equal_range(const key_type& k);
    pair<const_iterator, const_iterator> equal_range(const key_type& k) const;
};

template <class Key, class Compare, class Allocator>
bool operator==(const set<Key, Compare, Allocator>& x,
                const set<Key, Compare, Allocator>& y);

template <class Key, class Compare, class Allocator>
bool operator<(const set<Key, Compare, Allocator>& x,
               const set<Key, Compare, Allocator>& y);

template <class Key, class Compare, class Allocator>
bool operator!=(const set<Key, Compare, Allocator>& x,
                const set<Key, Compare, Allocator>& y);

template <class Key, class Compare, class Allocator>
bool operator>(const set<Key, Compare, Allocator>& x,
               const set<Key, Compare, Allocator>& y);

template <class Key, class Compare, class Allocator>
bool operator>=(const set<Key, Compare, Allocator>& x,
                const set<Key, Compare, Allocator>& y);

template <class Key, class Compare, class Allocator>
bool operator<=(const set<Key, Compare, Allocator>& x,
                const set<Key, Compare, Allocator>& y);

}  // namespace ft
