/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <orahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:42:06 by orahmoun          #+#    #+#             */
/*   Updated: 2022/08/15 10:42:07 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "includes.hpp"


namespace ft {
template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T *, class Reference = T &>
struct Iter {
  typedef T value_type;
  typedef Distance difference_type;
  typedef Pointer pointer;
  typedef Reference reference;
  typedef Category iterator_category;
};

template <class Iter> struct iterator_traits {
  typedef typename Iter::difference_type difference_type;
  typedef typename Iter::value_type value_type;
  typedef typename Iter::pointer pointer;
  typedef typename Iter::reference reference;
  typedef typename Iter::iterator_category iterator_category;
};

template <class T> struct iterator_traits<T *> {
  typedef ptrdiff_t difference_type;
  typedef T value_type;
  typedef T *pointer;
  typedef T &reference;
  typedef std::random_access_iterator_tag iterator_category;
};

template <class T> struct iterator_traits<const T *> {
  typedef ptrdiff_t difference_type;
  typedef T value_type;
  typedef const T *pointer;
  typedef const T &reference;
  typedef std::random_access_iterator_tag iterator_category;
};
} // namespace ft
