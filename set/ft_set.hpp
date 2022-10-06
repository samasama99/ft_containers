#include <includes.hpp>
#include "ft_setIterator.hpp"
#include "red_black_tree.hpp"

namespace ft {
template <class Key,
          class Compare = std::less<Key>,
          class Allocator = std::allocator<Key> >

class set {
    typedef red_black_tree<Key, Compare, Allocator> tree_type;

    tree_type _tree;

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

    typedef ft::setIterator<tree_node<value_type> > iterator;
    typedef const ft::setIterator<tree_node<value_type> > const_iterator;

    typedef ft::reverseSetIterator<tree_node<value_type>, iterator>
        reverse_iterator;
    typedef const ft::reverseSetIterator<tree_node<value_type>, iterator>
        const_reverse_iterator;

    // construct/copy/destroy:
    set() : _tree(){};

    explicit set(const value_compare& comp) : _tree(comp){};

    set(const value_compare& comp, const allocator_type& a) : _tree(comp, a){};

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

    ~set(){};

    set& operator=(const set& s);

    // iterators:
    iterator begin() { return iterator(_tree.theLeftest()); };

    const_iterator begin() const { return iterator(_tree.theLeftest()); };

    iterator end() { return iterator(_tree.getEnd()); };

    const_iterator end() const { return iterator(_tree.getEnd()); };

    reverse_iterator rbegin();

    const_reverse_iterator rbegin() const;

    reverse_iterator rend();

    const_reverse_iterator rend() const;

    // capacity:
    bool empty() const { return _tree.size() == 0; };

    size_type size() const { return _tree.size(); };

    size_type max_size() const { return Allocator().size(); };

    // modifiers:
    pair<iterator, bool> insert(const value_type& v) {
        ft::pair<tree_node<value_type>*, bool> p = _tree.add(v);
        return ft::make_pair(iterator(p.first), p.second);
    };

    iterator insert(const_iterator position, const value_type& v) {
        if (!position.base()->left || !position.base()->right)
            return insert(v).first;
        typename tree_type::node p = _tree.inOrderPredecessor(position.base());
        typename tree_type::node s = _tree.inOrderSuccessor(position.base());
        if (p && s) {
            if (_vcomp(s->data, p->data) && _vcomp(p->data, s->data)) {
                typename tree_type::node b = position.base();
                return iterator(_tree.insert(b, v).first);
            }
        }
        return insert(v).first;
    };

    template <class InputIterator>
    void insert(InputIterator first, InputIterator last) {
        for (InputIterator i = first; i != last; ++i) {
            insert(*i);
        }
    };

    iterator erase(const_iterator position);

    size_type erase(const key_type& k);

    iterator erase(const_iterator first, const_iterator last);

    void clear();

    void swap(set& s);

    // observers:
    allocator_type get_allocator() const { return Allocator(); };

    key_compare key_comp() const { return value_compare(); };

    value_compare value_comp() const { return key_comp(); };

    // set operations:
    iterator find(const key_type& k) {
        tree_node<value_type>* p = _tree.find(k);
        if (p == NULL)
            return iterator(_tree.getEnd());
        return iterator(p);
    };

    size_type count(const key_type& k) const {
        return ((_tree.find(k)) ? 1 : 0);
    };

    iterator lower_bound(const key_type& k) { return find(k); };

    const_iterator lower_bound(const key_type& k) const { return find(k); };

    iterator upper_bound(const key_type& k) {
        typename tree_type::node i = _tree.find(k);
        if (i == NULL)
            return end();
        if (i->right)
            return iterator(i->right);
        return end();
    };

    const_iterator upper_bound(const key_type& k) const {
        typename tree_type::node i = _tree.find(k);
        if (i == NULL)
            return end();
        if (i->right)
            return const_iterator(i->right);
        return end();
    };

    pair<const_iterator, const_iterator> equal_range(const key_type& k) const {
        return ft::make_pair(lower_bound(k), upper_bound(k));
    };

    pair<iterator, iterator> equal_range(const key_type& k) {
        return ft::make_pair(lower_bound(k), upper_bound(k));
    };

    void print() { _tree.print(); };
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
