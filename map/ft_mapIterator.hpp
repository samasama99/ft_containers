#pragma once
#include "../iterators_traits.hpp"

namespace ft {
template <typename T>
class mapIterator {
   public:
    typedef typename ft::iterator_traits<T*>::difference_type difference_type;
    typedef typename ft::iterator_traits<T*>::value_type value_type;
    typedef typename ft::iterator_traits<T*>::pointer pointer;
    typedef typename ft::iterator_traits<T*>::reference reference;
    typedef
        typename ft::iterator_traits<T*>::iterator_category iterator_category;

    typedef typename value_type::value_type value_pair;

   protected:
    T* p;

    explicit mapIterator(const long t) { (void)t; };

   public:
    pointer base() { return p; };

    explicit mapIterator() : p(NULL){};

    explicit mapIterator(T* t) : p(t){};

    template <class iter>
    mapIterator(const iter& src) : p(src.base()){};

    ~mapIterator(){};

    // template <class iterator>
    mapIterator& operator=(const mapIterator& src) {
        if (this == &src)
            return *this;
        p = src.p;
        return *this;
    };

    const pointer base() const { return p; };

    bool operator==(const mapIterator& src) const { return src.base() == p; };

    bool operator!=(const mapIterator& src) const {
        return !(src.base() == p);
    };

    value_pair& operator*() { return p->data; };

    const value_pair& operator*() const { return p->data; };

    value_pair* operator->() { return &p->data; };

    const value_pair* operator->() const { return &p->data; };

    mapIterator operator++(int) {
        mapIterator tmp(*this);
        ++(*this);
        return tmp;
    };  // post

    mapIterator& operator++() {
        p = value_type::Next(p);
        return *this;
    };  // pre

    mapIterator operator--(int) {
        mapIterator tmp(*this);
        --(*this);
        return tmp;
    };  // post

    mapIterator& operator--() {
        p = value_type::Previous(p);
        return *this;
    };  // pre

    bool operator==(const pointer ptr) const { return p == ptr; };

    bool operator!=(const pointer ptr) const { return p != ptr; };
};

// template <typename T, class iter>
// class reverseMapIterator {
//    private:
//     iter base_iter;
//     reverseMapIterator(const long t) : iter(t){};

//    public:
//     typedef typename iter::difference_type difference_type;
//     typedef typename iter::value_type value_type;
//     typedef typename iter::pointer pointer;
//     typedef typename iter::reference reference;
//     typedef typename iter::iterator_category iterator_category;

//    public:
//     explicit reverseMapIterator() : base_iter(){};

//     explicit reverseMapIterator(T* t) : base_iter(t){};

//     template <class iterator>
//     reverseMapIterator(const iterator& src) : base_iter(src){};

//     ~reverseMapIterator(){};
//     template <class iterator>
//     iterator& operator=(const iterator& src) {
//         if (this == &src)
//             return *this;
//         base_iter = src;
//         return *this;
//     };

//     iter base() { return base_iter; };

//     const iter base() const { return base_iter; };

//     bool operator==(const reverseMapIterator& src) const {
//         return base_iter == src.base();
//     };

//     bool operator!=(const reverseMapIterator& src) const {
//         return !(base_iter == src.base());
//     };

//     reference operator*() { return *(base_iter - 1); };

//     const reference operator*() const { return *(base_iter - 1); };

//     reference operator->() { return *(base_iter - 1); };

//     const reference operator->() const { return *(base_iter - 1); };

//     reverseMapIterator operator++(int) { return base_iter--; };  // post

//     reverseMapIterator& operator++() {
//         --base_iter;
//         return *this;
//     };  // pre

//     reverseMapIterator operator--(int) { return base_iter++; };

//     reverseMapIterator& operator--() {
//         ++base_iter;
//         return *this;
//     };
// };
};  // namespace ft
