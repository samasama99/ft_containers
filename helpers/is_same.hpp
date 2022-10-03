/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <orahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:59:26 by orahmoun          #+#    #+#             */
/*   Updated: 2022/08/16 12:59:28 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <typeinfo>

namespace ft {
template <typename T, typename U>
struct is_same {
    static const bool value = false;
};
template <typename T>
struct is_same<T, T> {
    static const bool value = true;
};
}  // namespace ft
