#pragma once
#include "../iterators_traits.hpp"

namespace ft {
template <typename T>
class mapIterator {
   protected:
    T* p;
    T* prev;

   public:
    typedef typename ft::iterator_traits<T*>::difference_type difference_type;
    typedef typename ft::iterator_traits<T*>::value_type value_type;
    typedef typename ft::iterator_traits<T*>::pointer pointer;
    typedef typename ft::iterator_traits<T*>::reference reference;
    typedef
        typename ft::iterator_traits<T*>::iterator_category iterator_category;

    typedef typename value_type::value_type value_pair;

    explicit mapIterator(const long t) { (void)t; };

    explicit mapIterator() : p(NULL), prev(NULL){};

    explicit mapIterator(T* t) : p(t), prev(NULL){};

    template <class iter>
    mapIterator(const iter& src) : p(src.base()), prev(NULL){};

    ~mapIterator(){};

    // template <class iterator>
    mapIterator& operator=(const mapIterator& src) {
        if (this == &src)
            return *this;
        p = src.p;
        prev = src.prev;
        return *this;
    };

    pointer base() { return p; };

    const pointer base() const { return p; };

    bool operator==(const mapIterator& src) const { return src.base() == p; };

    bool operator!=(const mapIterator& src) const {
        return !(src.base() == p);
    };

    value_pair& operator*() { return p->data; };

    const value_pair& operator*() const { return p->data; };

    value_pair* operator->() { return &p->data; };

    const value_pair* operator->() const { return &p->data; };

    // mapIterator operator++(int) {
    //     mapIterator tmp(*this);
    //     ++p;
    //     return tmp;
    // };  // post

    mapIterator& operator++() {
        T* tmp = p;
        p = value_type::Next(p, prev);
        prev = tmp;
        return *this;
    };  // pre

    // mapIterator operator--(int) {
    //     mapIterator tmp(*this);
    //     --p;
    //     return tmp;
    // };

    // mapIterator& operator--() {
    //     --p;
    //     return *this;
    // };

    // mapIterator operator-(const difference_type v) const {
    //     return mapIterator(p - v);
    // };

    // mapIterator operator+(const difference_type v) const {
    //     return mapIterator(p + v);
    // };

    // bool operator==(const pointer ptr) const { return p == ptr; };

    // bool operator!=(const pointer ptr) const { return p != ptr; };

    // bool operator<(const mapIterator& t) const { return p < t.p; };

    // bool operator>(const mapIterator& t) const { return p > t.p; };

    // bool operator<=(const mapIterator& t) const { return p <= t.p; };

    // bool operator>=(const mapIterator& t) const { return p >= t.p; };

    // void operator+=(const difference_type v) { p += v; };

    // void operator-=(const difference_type v) { p -= v; };

    // reference operator[](const difference_type i) { return *(p + i); }

    // const reference operator[](const difference_type i) const {
    //     return *(p + i);
    // }
};

};  // namespace ft
