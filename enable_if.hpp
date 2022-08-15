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
// enable_if
template <typename T, bool> class enable_if {};

template <typename T> class enable_if<T, true> {
public:
  typedef T type;
};
} // namespace ft
