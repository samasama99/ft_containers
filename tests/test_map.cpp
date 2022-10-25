/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <orahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:43:51 by orahmoun          #+#    #+#             */
/*   Updated: 2022/10/03 18:43:52 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <ft_map.hpp>
#include <iostream>
#include <map>

using namespace std;

void add_self(ft::pair<const int, int>& x) {
    x.second += x.second;
}

bool valid_iter(std::bidirectional_iterator_tag x) {
    (void)x;
    cout << "valid\n";
    return true;
}

int main() {
    {
        ft::map<int, int> t;
        ft::map<int, std::string> t2;
        cout << "default constructor :: pass\n";
    }
    {
        ft::map<int, int> t;
        ft::map<int, int>::iterator b = t.begin();
        ft::map<int, int>::iterator e = t.end();
        assert(b == e);
        cout << "testing begin and end iterator :: pass\n";
    }
    {
        ft::map<int, int> t;

        ft::pair<ft::map<int, int>::iterator, bool> i1 =
            t.insert(ft::make_pair(1, 10));
        ft::pair<ft::map<int, int>::iterator, bool> i2 =
            t.insert(ft::make_pair(2, 20));

        assert(i1.first->first == 1 && i1.second == true);
        assert(i2.first->first == 2 && i2.second == true);

        ft::pair<ft::map<int, int>::iterator, bool> ii1 =
            t.insert(ft::make_pair(1, 15));
        ft::pair<ft::map<int, int>::iterator, bool> ii2 =
            t.insert(ft::make_pair(2, 25));

        assert(ii1.first->first == 1 && ii1.second == false &&
               (i1.first == ii1.first));
        assert(ii2.first->first == 2 && ii2.second == false &&
               (i2.first == ii2.first));

        assert(t.find(1)->first == 1);
        assert(t.find(2)->first == 2);

        cout << "find and insert :: pass\n";
    }
    {
        ft::vector<ft::pair<int, int> > x;
        for (int i = 0; i < 30; ++i)
            x.push_back(ft::make_pair(i, i % 2));
        ft::map<int, int> m(x.begin(), x.end());
        for (int i = 0; i < 30; ++i) {
            ft::map<int, int>::iterator it = m.find(i);
            assert(it->second == i % 2);
            assert(it != m.end());
        }
        cout << "map range constructor :: pass\n";
    }
    {
        ft::map<int, int> t1;
        t1[0] = 65413;
        t1[2] = 232;
        t1[10] = 64654;
        t1[5] = 54684;
        t1[99] = 99842;
        assert(t1[0] == 65413);
        assert(t1[2] == 232);
        assert(t1[10] == 64654);
        assert(t1[5] == 54684);
        assert(t1[99] == 99842);
        ft::map<int, int> t2(t1);
        ft::map<int, int>::iterator i2 = t2.begin();
        for (ft::map<int, int>::iterator i = t1.begin(); i != t1.end(); ++i) {
            assert(*i == *i2);
            i2++;
        }
        t1.clear();
        assert(t2[0] == 65413);
        assert(t2[2] == 232);
        assert(t2[10] == 64654);
        assert(t2[5] == 54684);
        assert(t2[99] == 99842);
        cout << "copy constructor and [] overloading :: pass\n";
    }
    {
        ft::map<int, int> t1;
        t1[0] = 65413;
        t1[2] = 232;
        t1[10] = 64654;
        t1[5] = 54684;
        t1[99] = 99842;

        assert(t1[99] == 99842);
        ft::map<int, int> t2;
        t2 = t1;
        assert(t2[0] == 65413);
        assert(t2[2] == 232);
        assert(t2[10] == 64654);
        assert(t2[5] == 54684);
        assert(t2[99] == 99842);
        cout << "= overloading and [] overloading :: pass\n";
    }
    {
        ft::map<int, int> x;
        assert(x.size() == 0);

        x.insert(ft::make_pair(1, 1));
        assert(x.size() == 1);
        x.insert(ft::make_pair(2, 1));
        assert(x.size() == 2);
        x.insert(ft::make_pair(3, 1));
        assert(x.size() == 3);

        // erase somthing doesnt exists
        x.erase(x.find(10));

        x.erase(x.find(1));
        assert(x.size() == 2);
        x.erase(x.find(2));
        assert(x.size() == 1);
        x.erase(x.find(3));
        assert(x.size() == 0);
        assert(x.empty());
        assert(x.find(1) == x.end());
        assert(x.find(2) == x.end());
        assert(x.find(3) == x.end());
        cout << "testing erase and empty\n";
    }
    {
        ft::map<int, std::string> x;
        x[10] = "test1";
        x[20] = "test2";
        x[30] = x[10] + x[20];
        assert(x[10] == "test1");
        assert(x[20] == "test2");
        assert(x[30] == "test1test2");
        x[10] = x[10] + "test3";
        x[20] = x[20] + "test4";
        x[30] = x[10] + x[20];
        assert(x[10] == "test1test3");
        assert(x[20] == "test2test4");
        assert(x[30] == "test1test3test2test4");
        cout << "valid constructing of a class inside of map\n";
    }
    {
        ft::map<char, int> mymap;
        ft::map<char, int>::iterator itlow, itup;

        mymap['a'] = 20;
        mymap['b'] = 40;
        mymap['c'] = 60;
        mymap['d'] = 80;
        mymap['e'] = 100;

        itlow = mymap.lower_bound('b');  // itlow points to b
        itup = mymap.upper_bound('d');
        assert(itlow->first == 'b');
        assert(itup->first == 'e');
        itlow = mymap.lower_bound('x');  // itlow points to b
        itup = mymap.upper_bound('r');
        assert(itlow == mymap.end());
        assert(itup == mymap.end());
        itup = mymap.upper_bound('x');
        assert(itup == mymap.end());
        cout << "testing lower_bound and upper_bound\n";
    }
    {
        ft::map<char, int> mymap;
        ft::map<char, int>::iterator itlow, itup;

        mymap['a'] = 20;
        mymap['b'] = 40;
        mymap['c'] = 60;
        mymap['d'] = 80;
        mymap['e'] = 100;
        assert(mymap['a'] == 20);
        assert(mymap['b'] == 40);
        assert(mymap['c'] == 60);
        assert(mymap['d'] == 80);
        assert(mymap['e'] == 100);

        assert(mymap.count('a') == 1);
        assert(mymap.count('b') == 1);
        assert(mymap.count('c') == 1);
        assert(mymap.count('d') == 1);
        assert(mymap.count('e') == 1);

        itlow = mymap.lower_bound('b');  // itlow points to b
        itup = mymap.upper_bound('d');
        mymap.erase(itlow, itup);

        assert(mymap.count('a') == 1);
        assert(mymap.count('b') == 0);
        assert(mymap.count('c') == 0);
        assert(mymap.count('d') == 0);
        assert(mymap.count('e') == 1);

        assert(mymap['a'] == 20);
        assert(mymap['b'] == 0);
        assert(mymap['c'] == 0);
        assert(mymap['d'] == 0);
        assert(mymap['e'] == 100);
        cout << "testing range erase and count\n";
    }
    {
        ft::map<char, int> mymap;

        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;

        ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator>
            ret;
        ret = mymap.equal_range('b');
        assert(ret.first->second == 20);
        assert(ret.second->second == 30);
        cout << "testing equal range\n";
    }
    {
        map<std::string, std::string> s;
        s["test"] = "hello";
        s["test2"] = ",";
        s["test3"] = "world";
        s["test4"] = "!";
        map<std::string, std::string>::reverse_iterator ri = s.rbegin();
        assert(ri->first == "test4" && ri->second == "!");
        ++ri;
        assert(ri->first == "test3" && ri->second == "world");
        ++ri;
        assert(ri->first == "test2" && ri->second == ",");
        ++ri;
        assert(ri->first == "test" && ri->second == "hello");

        --ri;
        assert(ri->first == "test2" && ri->second == ",");
        --ri;
        assert(ri->first == "test3" && ri->second == "world");
        --ri;
        assert(ri->first == "test4" && ri->second == "!");
        cout << "testing reverse_iterator\n";
    }
    {
        ft::map<int, int, greater<int> > m;
        m[1];
        m[2];
        m[3];
        ft::map<int, int, greater<int> >::iterator i = m.begin();
        assert(i->first == 3);
        i++;
        assert(i->first == 2);
        ++i;
        assert(i->first == 1);
        cout << "changing the comp object\n";
    }
    {
        ft::map<int, int> t1;
        t1[0] = 65413;
        t1[2] = 232;
        t1[10] = 64654;
        t1[5] = 54684;
        t1[99] = 99842;
        std::for_each(t1.begin(), t1.end(), add_self);
        assert(t1[0] == (2 * 65413));
        assert(t1[2] == (232 * 2));
        assert(t1[10] == (64654 * 2));
        assert(t1[5] == (54684 * 2));
        assert(t1[99] == (99842 * 2));
    }
    {
        ft::map<int, int> t1;
        assert(valid_iter(t1.begin()));
    }
    system("leaks test_map");
    std::cout << "all pass" << std::endl;
}
