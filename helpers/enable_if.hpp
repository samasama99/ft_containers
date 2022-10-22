/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <orahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:42:02 by orahmoun          #+#    #+#             */
/*   Updated: 2022/08/15 10:42:03 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft {
template <bool, typename T>
struct enable_if {
    typedef void type;
};

template <typename T>
struct enable_if<true, T> {
    typedef T type;
};
}  // namespace ft

// enable_if<is_same<char, T>, T>

// enable_if<is_same<char, char>, char>
// enable_if<true, char>::type == char

// enable_if<is_same<char, int>, int>
// enable_if<true, char>::type == void

// template <typename T>
// int fn(enable_if<is_same<char, T>, T>::type x) {
//     return x;
// }
