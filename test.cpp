#include <includes.hpp>
#include <set>
#include "set/ft_set.hpp"
#include "set/red_black_tree.hpp"
#include "vector/ft_vector.hpp"

int main() {
    {
        ft::set<int> x;
        std::cout << "testing default constructor\n";
    }
    {
        std::less<int> l;
        ft::set<int> x(l);
        std::cout << "testing comp constructor\n";
    }
    {
        std::less<int> l;
        std::allocator<int> a;
        ft::set<int> x(l, a);
        std::cout << "testing comp and allocator constructor\n";
    }
    {
        ft::set<int> x;
        x.insert(10);
        x.insert(20);
        x.insert(30);
        assert(x.find(10) != x.end());
        assert(x.find(20) != x.end());
        assert(x.find(30) != x.end());
        assert(x.find(40) == x.end());
        assert(x.find(50) == x.end());
        assert(x.find(60) == x.end());
        x.insert(40);
        x.insert(50);
        x.insert(60);
        assert(x.find(10) != x.end());
        assert(x.find(20) != x.end());
        assert(x.find(30) != x.end());
        assert(x.find(40) != x.end());
        assert(x.find(50) != x.end());
        assert(x.find(60) != x.end());
        std::cout << "testing insert and find\n";
    }
    {
        ft::set<int> x;
        x.insert(1);
        ft::set<int>::iterator i = x.begin();
        assert(*i == 1);
        ++i;
        assert(i == x.end());
        --i;
        assert(i == x.begin());
        assert(i++ == x.begin());
        assert(i == x.end());
        assert(i-- == x.end());
        assert(i == x.begin());
        std::cout << "testing iterators (begin, end)\n";
    }
    {
        ft::set<int> x;
        x.insert(1);
        x.insert(2);
        x.insert(3);
        x.insert(4);
        x.insert(5);
        x.insert(6);
        x.insert(7);
        x.insert(8);
        x.insert(9);
        x.insert(10);
        ft::set<int>::iterator i = x.begin();
        for (int in = 1; in < 11; ++in) {
            assert(*i == in);
            ++i;
        }
        i = x.end();
        for (int in = 10; in; --in) {
            --i;
            assert(*i == in);
        }
        std::cout << "testing iterators (++, --)\n";
    }
    {
        std::set<int> stl;
        ft::set<int> ft;
        stl.insert(1);
        stl.insert(2);
        stl.insert(3);
        stl.insert(4);
        stl.insert(5);
        stl.insert(6);
        stl.insert(7);
        stl.insert(8);
        stl.insert(9);
        stl.insert(10);
        ft.insert(stl.begin(), stl.end());
        ft::set<int>::iterator i = ft.begin();
        for (std::set<int>::iterator in = stl.begin(); in != stl.end(); ++in) {
            assert(*in == *i);
            ++i;
        }
        std::cout << "testing range insert\n";
    }
    {
        ft::vector<int> stl;
        ft::set<int> ft;
        stl.push_back(1);
        stl.push_back(2);
        stl.push_back(3);
        stl.push_back(4);
        stl.push_back(5);
        stl.push_back(6);
        stl.push_back(7);
        stl.push_back(8);
        stl.push_back(9);
        stl.push_back(10);
        ft.insert(stl.begin(), stl.end());
        ft::set<int>::iterator i = ft.begin();
        for (ft::vector<int>::iterator in = stl.begin(); in != stl.end();
             ++in) {
            assert(*in == *i);
            ++i;
        }
        std::cout << "testing range insert with ft::vector\n";
    }
}
