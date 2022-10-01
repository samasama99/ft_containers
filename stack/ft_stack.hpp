/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <orahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:59:10 by orahmoun          #+#    #+#             */
/*   Updated: 2022/08/16 12:59:11 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.hpp"
#include "../vector/ft_vector.hpp"

namespace ft {
template <class T, class Container = ft::vector<T> >
class stack {
   public:
    typedef T value_type;
    typedef Container container_type;
    typedef std::size_t size_type;

    static_assert(
        (ft::is_same<value_type, typename Container::value_type>::value),
        "Incompatible type between the container and the class type");

   public:
    explicit stack(const container_type& c = container_type()) : c(c){};
    bool empty() const { return c.empty(); };
    size_type size() const { return c.size(); };
    value_type& top() { return c.back(); };
    const value_type& top() const { return c.back(); };
    void push(const value_type& val) { c.push_back(val); };
    void pop() { c.pop_back(); };

   protected:
    container_type c;
};
}  // namespace ft
