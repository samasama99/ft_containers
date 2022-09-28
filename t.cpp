/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <orahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:59:37 by orahmoun          #+#    #+#             */
/*   Updated: 2022/08/16 12:59:38 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector/ft_vector.hpp"

typedef struct p {
   public:
    int a;
    int b;
    p(int a, int b) : a(a), b(b){};
} p;

class X {
    p test;

   public:
    X(int x) : test(x, x){};
    void t() { std::cout << "test\n"; }
    X& operator*() { return *this; };
    X* operator->() { return this; };
};

int main() {
    X x(10);
    x.t();
    (*x).t();
    x->t();
}
