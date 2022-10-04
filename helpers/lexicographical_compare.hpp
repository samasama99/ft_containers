/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <orahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:59:31 by orahmoun          #+#    #+#             */
/*   Updated: 2022/08/16 12:59:32 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes.hpp>

namespace ft {
template <class InputIterator1, class InputIterator2>
// [1,2,3] < [1,2,4] ==> true || "aaba" < "aabb" ==> true
bool lexicographical_compare(InputIterator1 first1,
                             InputIterator1 last1,
                             InputIterator2 first2,
                             InputIterator2 last2) {
    while (first1 != last1) {
        if (first2 == last2 || *first1 > *first2)
            return false;
        else if (*first1 < *first2)
            return true;
        ++first1;
        ++first2;
    }
    return (first2 != last2);
};

template <class InputIterator1, class InputIterator2, class Compare>
bool lexicographical_compare(InputIterator1 first1,
                             InputIterator1 last1,
                             InputIterator2 first2,
                             InputIterator2 last2,
                             Compare comp) {
    while (first1 != last1) {
        if (first2 == last2 || comp(*first2, *first1))
            return false;
        else if (comp(*first1, *first2))
            return true;
        ++first1;
        ++first2;
    }
    return (first2 != last2);
};
}  // namespace ft
