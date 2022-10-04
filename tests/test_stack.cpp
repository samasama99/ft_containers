/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <orahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:59:46 by orahmoun          #+#    #+#             */
/*   Updated: 2022/08/16 12:59:47 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stack.hpp>
#include <list>
#include <stack>
#include <vector>

int main() {
    {
        ft::stack<int, ft::vector<int> > s;
        s.push(5);
        assert(s.top() == 5);
        s.push(6);
        assert(s.top() == 6);
        s.pop();
        assert(s.top() == 5);
        std::cout << "testing stack with my vector + top | push | pop\n";
    }
    {
        ft::stack<int> ss;
        assert(ss.empty());
        ss.push(5);
        assert(!ss.empty());
        ss.pop();
        assert(ss.empty());
        std::cout << "testing stack with my vector + empty\n";
    }
    {
        ft::stack<double, std::vector<double> > s;
        s.push(5);
        assert(s.top() == 5);
        s.push(6);
        assert(s.top() == 6);
        s.pop();
        assert(s.top() == 5);
        std::cout << "testing stack with stl vector + top | push | pop\n";
    }
    {
        ft::stack<int, std::vector<int> > ss;
        assert(ss.empty());
        ss.push(5);
        assert(!ss.empty());
        ss.pop();
        assert(ss.empty());
        std::cout << "testing stack with stl vector + empty\n";
    }
    {
        ft::stack<double, std::list<double> > s;
        s.push(5);
        assert(s.top() == 5);
        s.push(6);
        assert(s.top() == 6);
        s.pop();
        assert(s.top() == 5);
        std::cout << "testing stack with stl list + top | push | pop\n";
    }
    {
        ft::stack<int, std::list<int> > ss;
        assert(ss.empty());
        ss.push(5);
        assert(!ss.empty());
        ss.pop();
        assert(ss.empty());
        std::cout << "testing stack with stl list + empty\n";
    }
}
