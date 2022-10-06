#pragma once
#include <iterators_traits.hpp>

namespace ft {
template <typename T>
class setIterator {
   public:
    typedef typename ft::iterator_traits<T*>::difference_type difference_type;
    typedef typename ft::iterator_traits<T*>::value_type value_type;
    typedef typename ft::iterator_traits<T*>::pointer pointer;
    typedef typename ft::iterator_traits<T*>::reference reference;
    typedef
        typename ft::iterator_traits<T*>::iterator_category iterator_category;

    typedef typename value_type::value_type value_return;

   protected:
    T* p;

    explicit setIterator(const long t) { (void)t; };

   public:
    pointer base() { return p; };

    explicit setIterator() : p(NULL){};

    explicit setIterator(T* t) : p(t){};

    // template <class iter>
    // setIterator(const iter& src) : p(src.base()){};

    ~setIterator(){};

    // template <class iterator>
    setIterator& operator=(const setIterator& src) {
        if (this == &src)
            return *this;
        p = src.p;
        return *this;
    };

    const pointer base() const { return p; };

    bool operator==(const setIterator& src) const { return src.base() == p; };

    bool operator!=(const setIterator& src) const {
        return !(src.base() == p);
    };

    value_return& operator*() { return p->data; };

    const value_return& operator*() const { return p->data; };

    value_return* operator->() { return &p->data; };

    const value_return* operator->() const { return &p->data; };

    setIterator operator++(int) {
        setIterator tmp(*this);
        ++(*this);
        return tmp;
    };  // post

    setIterator& operator++() {
        p = value_type::Next(p);
        return *this;
    };  // pre

    setIterator operator--(int) {
        setIterator tmp(*this);
        --(*this);
        return tmp;
    };  // post

    setIterator& operator--() {
        p = value_type::Previous(p);
        return *this;
    };  // pre

    bool operator==(const pointer ptr) const { return p == ptr; };

    bool operator!=(const pointer ptr) const { return p != ptr; };
};

template <typename T, class iter>
class reverseSetIterator {
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

    explicit reverseSetIterator(const long t) { (void)t; };

   public:
    pointer base() { return p; };

    explicit reverseSetIterator() : p(NULL){};

    explicit reverseSetIterator(T* t) : p(t){};

    reverseSetIterator(const iter& src) : p(src.base()){};

    ~reverseSetIterator(){};

    // template <class iterator>
    reverseSetIterator& operator=(const reverseSetIterator& src) {
        if (this == &src)
            return *this;
        p = src.p;
        return *this;
    };

    const pointer base() const { return p; };

    bool operator==(const reverseSetIterator& src) const {
        return src.base() == p;
    };

    bool operator!=(const reverseSetIterator& src) const {
        return !(src.base() == p);
    };

    value_pair& operator*() { return value_type::Previous(p)->data; };

    const value_pair& operator*() const {
        return value_type::Previous(p)->data;
    };

    value_pair* operator->() { return &value_type::Previous(p)->data; };

    const value_pair* operator->() const {
        return &value_type::Previous(p)->data;
    };

    reverseSetIterator operator++(int) {
        reverseSetIterator tmp(*this);
        --(*this);
        return tmp;
    };  // post

    reverseSetIterator& operator++() {
        p = value_type::Previous(p);
        return *this;
    };  // pre

    reverseSetIterator operator--(int) {
        reverseSetIterator tmp(*this);
        ++(*this);
        return tmp;
    };  // post

    reverseSetIterator& operator--() {
        p = value_type::Next(p);
        return *this;
    };  // pre

    bool operator==(const pointer ptr) const { return p == ptr; };

    bool operator!=(const pointer ptr) const { return p != ptr; };
};
};  // namespace ft
