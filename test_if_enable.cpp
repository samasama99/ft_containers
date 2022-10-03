/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_if_enable.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <orahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:59:39 by orahmoun          #+#    #+#             */
/*   Updated: 2022/08/16 12:59:40 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "helpers/enable_if.hpp"

class A {};

template <typename T>
typename ft::enable_if<std::is_class<T>::value, T>::type is_even(T i) {
    return i;
}

int main() {
    // should work with class bc enale_if :: value == A
    A x;
    // should not work with int bc enale_if :: value == void
    // int x;
    is_even(x);
}
