#include <map>
#include "map/avl.hpp"

// insert return pair<iterator, bool>
// find
// false if the key already exists doest change the value in that case
// the iterator have a & to a node
// find return an iterator constructed with the node if found and end() if not
// AVL insert should return pair<node, bool>

int main() {
    AVL<int> x;
    x.insert(10);
    assert(x.find(10) != NULL);
    assert(x.find(20) == NULL);
    x.insert(20);
    x.insert(30);
    x.insert(40);
    x.insert(50);
    x.insert(60);
    std::pair<AVL<int>::node, bool> m = x.insert(70);
    assert(m.first == x.find(70));
    assert(m.second == true);
    m = x.insert(70);
    assert(m.first == x.find(70));
    assert(m.second == false);
    assert(x.find(20) != NULL);
    assert(x.find(30) != NULL);
    assert(x.find(40) != NULL);
    assert(x.find(50) != NULL);
    assert(x.find(60) != NULL);
    assert(x.find(70) != NULL);
    assert(x._root->left->data == 20);
    assert(x._root->right->data == 60);
    {
        std::map<int, int> t;
        assert(t.size() == 0);
        assert(t.find(0) == t.end());
        std::pair<std::map<int, int>::iterator, bool> i2 =
            t.insert(std::make_pair(1, 0));
        assert(i2.first == t.find(1));
        t[1];
        assert(t[1] == 0);
        std::pair<std::map<int, int>::iterator, bool> i =
            t.insert(std::make_pair(1, 1));
        assert(i.first == t.find(1));
        assert(i.second == false);
        assert(i2.second == true);
        assert(t.at(1) == 0);
        t[1] = 2;
        assert(t.at(1) == 2);
        t[2] = 3;
        t[3] = 4;
        t[4] = 5;
        t[5] = 6;
        std::map<int, int>::iterator iter = t.begin();
        assert(iter->first == 1);
        ++iter;
        assert(iter->first == 2);
        ++iter;
        assert(iter->first == 3);
        ++iter;
        assert(iter->first == 4);
        ++iter;
        assert(iter->first == 5);
        ++iter;
        assert(iter == t.end());
        t.insert(t.end(), std::make_pair(0, 0));
        iter = t.begin();
        assert(iter->first == 0);
        t.insert(t.end(), std::make_pair(0, 0));
        iter = t.begin();
        assert(iter->first == 0);
        t.erase(t.begin());
        iter = t.begin();
        assert(iter->first == 1);
        t.insert(t.end(), std::make_pair(0, 0));
        iter = t.begin();
        assert(iter->first == 0);
    }
    {
        // map iter have a reference to the pair instead of the node ??
        std::map<int, char> c;
        std::map<int, char>::iterator it = c.find(2);
        assert(it == c.end());
        c[2] = 'x';
        it = c.find(2);
        assert(it->first == 2);
        assert(it->second == 'x');
    }
    std::cout << "end" << std::endl;
}
