#include <iterator>
#include "../includes.hpp"
#include "../iterators_traits.hpp"
#include "avl.hpp"
#include "ft_mapIterator.hpp"

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
    typedef ft::mapIterator<const avlNode<value_type> > const_iterator;

    typedef std::size_t size_type;
    struct value_compare : std::binary_function<value_type, value_type, bool> {
        const key_compare c;
        value_compare(const key_compare& k) : c(k) {}
        bool operator()(const value_type& v1, const value_type& v2) const {
            return c(v1.first, v2.first);
        }
    };
    typedef AVL<value_type, value_compare> tree_type;

   public:
    // constructors:
    explicit map(const key_compare& comp = key_compare(),
                 const allocator_type& alloc = allocator_type())
        : _alloc(alloc),
          _tree(
              value_compare(comp),
              typename allocator_type::template rebind<avlNode<T> >::other()){};

    // template <class InputIterator>
    // map(InputIterator first,
    //     InputIterator last,
    //     const key_compare& comp = key_compare(),
    //     const allocator_type& alloc = allocator_type()){};

    // map(const map& x){};
    // destructor:
    ~map(){};
    // operator=
    map& operator=(const map& x);
    // capacity:
    bool empty() const { return _tree.size() == 0; };

    size_type size() const { return _tree.size(); };

    // size_type max_size() const;

    mapped_type& operator[](const key_type& k) {
        return _tree.insert(ft::make_pair(k, mapped_type())).first->data.second;
    };

    pair<iterator, bool> insert(const value_type& val) {
        pair<avlNode<value_type>*, bool> tmp = _tree.insert(val);
        return ft::make_pair(iterator(tmp.first), tmp.second);
    };
    // iterator insert(iterator position, const value_type &val);
    // template <class InputIterator>
    // void insert(InputIterator first, InputIterator last);
    // void erase(iterator position);
    // size_type erase(const key_type &k);
    // void erase(iterator first, iterator last);
    void swap(map& x) { swap(*this, x); };
    // TODO AVL clear
    void clear() { _tree.clear(); };
    key_compare key_comp() const { return key_compare(); };
    // value_compare value_comp() const;

    iterator find(const key_type& k) {
        avlNode<value_type>* n = _tree.find(value_type(k, mapped_type()));
        if (n == NULL)
            return end();
        return iterator(n);
    };

    const_iterator find(const key_type& k) const { return find(k); };

    size_type count(const key_type& k) const {
        return (_tree.find(make_pair(k, mapped_type())) != NULL) ? 1 : 0;
    };
    // iterator lower_bound(const key_type &k);
    // const_iterator lower_bound(const key_type &k) const;
    // iterator upper_bound(const key_type &k);
    // const_iterator upper_bound(const key_type &k) const;
    // pair<const_iterator, const_iterator> equal_range(const key_type &k)
    // const; pair<iterator, iterator> equal_range(const key_type &k);
    //////////// does map return alloc inside of tree or the original alloc ??
    allocator_type get_allocator() const { return Alloc(); };
    iterator begin() { return iterator(_tree.theLeftest()); }
    iterator end() {
        return iterator(new avlNode<value_type>(_tree.theLeftest()));
    }

    void print() { _tree.print(); }

   private:
    Alloc _alloc;
    tree_type _tree;
};
template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const ft::pair<K, V>& f) {
    os << f.first;
    return os;
}
}  // namespace ft

#include <map>

int main() {
    ft::map<int, int> m;
    m[5] = 5;
    m[3] = 3;
    m[4] = 4;
    m[1] = 1;
    m[2] = 2;
    m[6] = 6;
    m.print();
    ft::map<int, int>::iterator x = m.begin();
    while (x != m.end())
        ++x;
    // m.empty();
    // m.get_allocator();
    // m.key_comp();
    // m.size();
    // m.count(1);
}
