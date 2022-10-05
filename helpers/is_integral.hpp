/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <orahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:59:22 by orahmoun          #+#    #+#             */
/*   Updated: 2022/08/16 12:59:23 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <includes.hpp>

namespace ft {
template <typename T>
struct is_integral {
    typedef T value_type;
    static const bool value = std::numeric_limits<T>::is_integer;
};
};  // namespace ft
