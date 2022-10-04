#pragma once
#include <avl.hpp>
#include <ft_mapIterator.hpp>
#include <ft_vector.hpp>
#include <includes.hpp>
#include <iterator>

namespace ft {
template <class Key,
          class T,
          class Compare = std::less<Key>,
          class Alloc = std::allocator<ft::pair<const Key, T> > >
class map {
   public:
    typedef Key key_type;
    typedef T mapped_type;
    typedef pair<const Key, mapped_type> value_type;
    typedef Compare key_compare;
    typedef Alloc allocator_type;
    typedef typename Alloc::reference reference;
    typedef typename Alloc::const_reference const_reference;
    typedef typename Alloc::pointer pointer;
    typedef typename Alloc::const_pointer const_pointer;

    typedef ft::mapIterator<avlNode<value_type> > iterator;
    typedef const ft::mapIterator<avlNode<value_type> > const_iterator;

    typedef ft::reverseMapIterator<avlNode<value_type>, iterator>
        reverse_iterator;
    typedef const ft::reverseMapIterator<avlNode<value_type>, iterator>
        const_reverse_iterator;

    typedef size_t size_type;
    struct value_compare : std::binary_function<value_type, value_type, bool> {
        typedef bool result_type;
        typedef value_type first_argument_type;
        typedef value_type second_argument_type;
        key_compare c;
        value_compare() : c() {}
        value_compare(key_compare k) : c(k) {}
        bool operator()(const value_type& v1, const value_type& v2) const {
            return c(v1.first, v2.first);
        }
    };
    typedef AVL<value_type, value_compare> tree_type;

   public:
    explicit map(const key_compare& comp = key_compare(),
                 const allocator_type& alloc = allocator_type())
        : _alloc(alloc),
          _tree(
              value_compare(comp),
              typename allocator_type::template rebind<avlNode<T> >::other()){};

    template <class InputIterator>
    map(InputIterator first,
        InputIterator last,
        const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type())
        : _alloc(alloc),
          _comp(comp),
          _tree(
              value_compare(comp),
              typename allocator_type::template rebind<avlNode<T> >::other()) {
        insert(first, last);
    };

    map(const map& x)
        : _alloc(x._alloc),
          _comp(x._comp),
          _tree(x._tree._comp, x._tree._alloc) {
        insert(x.begin(), x.end());
    };

    ~map() { _tree.clear(); };

    map& operator=(const map& x) {
        if (&x == this)
            return *this;
        _comp = x._comp;
        _alloc = x._alloc;
        _tree.clear();
        insert(x.begin(), x.end());
        return *this;
    };

    bool empty() const { return _tree.size() == 0; };

    size_type size() const { return _tree.size(); };

    size_type max_size() const { return _alloc.max_size(); };

    mapped_type& operator[](const key_type& k) {
        return _tree.insert(ft::make_pair(k, mapped_type())).first->data.second;
    };

    pair<iterator, bool> insert(const value_type& val) {
        pair<avlNode<value_type>*, bool> tmp = _tree.insert(val);
        return ft::make_pair(iterator(tmp.first), tmp.second);
    };

    iterator insert(iterator position, const value_type& val) {
        if (!position.base()->left || !position.base()->right)
            return insert(val).first;
        typename tree_type::node p = _tree.inOrderPredecessor(position.base());
        typename tree_type::node s = _tree.inOrderSuccessor(position.base());
        if (p && s) {
            if (_vcomp(s->data, p->data) && _vcomp(p->data, s->data)) {
                typename tree_type::node b = position.base();
                return iterator(_tree.insert(b, val).first);
            }
        }
        return insert(val).first;
    };

    template <class InputIterator>
    void insert(InputIterator first, InputIterator last) {
        for (InputIterator i = first; i != last; ++i) {
            insert(ft::make_pair(i->first, i->second));
        }
    };

    void erase(iterator position) { _tree.remove(*position); };

    size_type erase(const key_type& k) {
        _tree.remove(ft::make_pair(k, T()));
        return 1;
    };

    void erase(iterator first, iterator last) {
        ft::vector<ft::pair<Key, T> > t;
        for (iterator i = first; i != last; ++i) {
            t.push_back(ft::make_pair(i->first, i->second));
        }
        for (size_t i = 0; i < t.size(); ++i) {
            _tree.remove(t[i]);
        }
    };

    void swap(map& x) {
        map tmp = x;
        x = *this;
        *this = tmp;
    };

    void clear() { _tree.clear(); };

    key_compare key_comp() const { return _comp; };

    value_compare value_comp() const { return _vcomp; };

    iterator find(const key_type& k) {
        avlNode<value_type>* n = _tree.find(value_type(k, mapped_type()));
        if (n == NULL)
            return end();
        return iterator(n);
    };

    const_iterator find(const key_type& k) const { return find(k); };

    size_type count(const key_type& k) const {
        return ((_tree.find(ft::make_pair(k, mapped_type()))) ? 1 : 0);
    };

    iterator lower_bound(const key_type& k) { return find(k); };

    const_iterator lower_bound(const key_type& k) const { return find(k); };

    iterator upper_bound(const key_type& k) {
        typename tree_type::node i =
            _tree.find(ft::make_pair(k, mapped_type()));
        if (i == NULL)
            return end();
        if (i->right)
            return iterator(i->right);
        return end();
    };

    const_iterator upper_bound(const key_type& k) const {
        typename tree_type::node i =
            _tree.find(ft::make_pair(k, mapped_type()));
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

    allocator_type get_allocator() const { return Alloc(); };

    iterator begin() { return iterator(_tree.theLeftest()); }

    iterator end() { return iterator(_tree._end); }

    const_iterator begin() const { return const_iterator(_tree.theLeftest()); }

    const_iterator end() const { return const_iterator(_tree._end); }

    reverse_iterator rbegin() { return reverse_iterator(_tree._end); }

    reverse_iterator rend() { return reverse_iterator(begin()); }

    const_iterator rbegin() const { return const_iterator(_tree.theLeftest()); }

    const_iterator rend() const { return const_iterator(_tree._end); }

    void print() { _tree.print(); }

   private:
    allocator_type _alloc;
    key_compare _comp;
    value_compare _vcomp;
    tree_type _tree;
};
template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const ft::pair<K, V>& f) {
    os << f.first;
    return os;
}
}  // namespace ft
