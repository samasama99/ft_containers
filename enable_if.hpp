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
template <typename T, bool>
struct enable_if {
    typedef void type;
};

template <typename T>
struct enable_if<T, true> {
    typedef T type;
};
}  // namespace ft
