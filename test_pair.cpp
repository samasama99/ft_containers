/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pair.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <orahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:59:42 by orahmoun          #+#    #+#             */
/*   Updated: 2022/08/16 12:59:43 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "pair/ft_pair.hpp"

int main() {
    { ft::pair<int, int> p; }
    { ft::pair<int, double> p; }
    {
        ft::pair<std::string, std::vector<int> > p;
        std::cout << "pair() default constructor :: pass\n";
    }
    {
        ft::pair<int, int> p(10, 20);
        assert(p.first == 10);
        assert(p.second == 20);
    }
    {
        ft::pair<int, double> p(10, 1.2);
        assert(p.first == 10);
        assert(p.second == 1.2);
    }
    {
        std::vector<int> x;
        x.push_back(1);
        x.push_back(2);
        x.push_back(3);
        x.push_back(4);
        ft::pair<std::string, std::vector<int> > p("test", x);
        assert(p.first == "test");
        assert(p.second[0] == 1);
        assert(p.second[1] == 2);
        assert(p.second[2] == 3);
        assert(p.second[3] == 4);
        std::cout << "pair(F, S) constructor :: pass\n";
    }
    {
        std::vector<int> x;
        x.push_back(1);
        x.push_back(2);
        x.push_back(3);
        x.push_back(4);
        ft::pair<std::string, std::vector<int> > p("test", x);
        ft::pair<std::string, std::vector<int> > p2(p);
        assert(p2.first == "test");
        assert(p2.second[0] == 1);
        assert(p2.second[1] == 2);
        assert(p2.second[2] == 3);
        assert(p2.second[3] == 4);
        std::cout << "pair(&pair) copy constructor :: pass\n";
        ft::pair<std::string, std::vector<int> > p3;
        p3 = p2;
        assert(p3.first == "test");
        assert(p3.second[0] == 1);
        assert(p3.second[1] == 2);
        assert(p3.second[2] == 3);
        assert(p3.second[3] == 4);
        std::cout << "pair = overloading :: pass\n";
        assert(p == p2 && p == p3);
        assert(!(p != p2) && !(p != p3));
        assert(!(p != p2) && !(p != p3));
        p3.first = "a";
        assert(p > p3);
        std::cout << "pair relational operators :: pass\n";
    }
    {
        ft::pair<int, int> x(10, 20);
        ft::pair<double, std::string> y(1.1, "test");
        ft::pair<ft::pair<int, int>, ft::pair<double, std::string> > xy(x, y);
        ft::pair<ft::pair<int, int>, ft::pair<double, std::string> > xy2 =
            ft::make_pair(x, y);
        assert(xy.first.first == xy2.first.first);
        assert(xy.first.second == xy2.first.second);
        assert(xy.second.first == xy2.second.first);
        assert(xy.second.second == xy2.second.second);
        std::cout << "make pair :: pass\n";
    }
}
