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

    pointer base() { return p; };
    explicit mapIterator(const long t) { (void)t; };

   public:
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

};  // namespace ft
