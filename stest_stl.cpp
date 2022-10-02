#include <iostream>
#include <map>

bool fncomp(char lhs, char rhs) {
    return lhs < rhs;
}

struct classcomp {
    bool operator()(const char& lhs, const char& rhs) const {
        return lhs < rhs;
    }
};

int main() {
    {
        // constructors test + operator[]
        std::map<char, int> first;
        first['a'] = 10;
        first['a'] = 11;
        first['b'] = 30;
        first['c'] = 50;
        first['d'] = 70;
        std::map<char, int> second(first.begin(), first.end());
        std::map<char, int> third(second);

        std::map<char, int, classcomp> fourth;

        bool (*fn_pt)(char, char) = fncomp;
        std::map<char, int, bool (*)(char, char)> fifth(fn_pt);
        // first.my_tree._printing();
        std::cout << "========================================================="
                     "====\n";
        // second.my_tree._printing();
        std::cout << "========================================================="
                     "====\n";
        // third.my_tree._printing();
        std::cout << "========================================================="
                     "====\n";
        // fifth.my_tree._printing();
        std::cout << "========================================================="
                     "====\n";
    }
    std::cout
        << "=============================================================\n";
    {  // assignement operator
        std::map<char, int> first;
        std::map<char, int> second;

        first['x'] = 8;
        first['y'] = 16;
        first['z'] = 32;
        second['a'] = 32;

        second = first;
        first = std::map<char, int>();

        std::cout << "Size of first: " << first.size() << '\n';
        std::cout << "Size of second: " << second.size() << '\n';
        std::cout << "========================================================="
                     "====\n";
        // first.my_tree._printing();
        std::cout << "========================================================="
                     "====\n";
        // second.my_tree._printing();
    }
    std::cout
        << "=============================================================\n";
    {  // iterators begin and end
        std::map<char, int> mymap;

        mymap['b'] = 100;
        mymap['a'] = 200;
        mymap['c'] = 300;

        for (std::map<char, int>::iterator it = mymap.begin();
             it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    std::cout
        << "=============================================================\n";
    {  // iterators rbegin and rend
        std::map<char, int> mymap;

        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300;

        for (std::map<char, int>::reverse_iterator it = mymap.rbegin();
             it != mymap.rend(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    std::cout
        << "=============================================================\n";
    {  // empty() + size()
        std::map<char, int> mymap;

        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;
        mymap['c'] = 30;

        std::cout << "size before " << mymap.size() << "\n";
        while (!mymap.empty()) {
            std::cout << mymap.begin()->first << " => " << mymap.begin()->second
                      << '\n';
            mymap.erase(mymap.begin());
        }
        std::cout << "size after " << mymap.size() << "\n";
    }
    std::cout
        << "=============================================================\n";
    {  // max_size()
        int i;
        std::map<int, int> mymap;

        if (mymap.max_size() > 1000) {
            for (i = 0; i < 1000; i++)
                mymap[i] = 0;
            std::cout << "The map contains 1000 elements.\n";
        } else
            std::cout << "The map could not hold 1000 elements.\n";
    }
    std::cout
        << "=============================================================\n";
    {  // insert
        std::map<char, int> mymap;
        mymap.insert(std::pair<char, int>('a', 100));
        mymap.insert(std::pair<char, int>('z', 200));

        std::pair<std::map<char, int>::iterator, bool> ret;
        ret = mymap.insert(std::pair<char, int>('z', 500));
        if (ret.second == false) {
            std::cout << "element 'z' already existed\n";
            std::cout << " with a value of " << ret.first->second << '\n';
        }

        std::map<char, int>::iterator it = mymap.begin();
        mymap.insert(it, std::pair<char, int>('b', 300));
        mymap.insert(it, std::pair<char, int>('c', 400));

        std::map<char, int> anothermap;
        anothermap.insert(mymap.begin(), mymap.find('c'));

        std::cout << "mymap contains:\n";
        for (it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::cout << "anothermap contains:\n";
        for (it = anothermap.begin(); it != anothermap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    std::cout
        << "=============================================================\n";
    {
        std::map<char, int> mymap;
        std::map<char, int>::iterator it;
        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;
        mymap['d'] = 40;
        mymap['e'] = 50;
        mymap['f'] = 60;
        it = mymap.find('b');
        mymap.erase(it);

        mymap.erase('c');

        it = mymap.find('e');
        mymap.erase(it, mymap.end());

        for (it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        // mymap.my_tree._printing();
    }
    std::cout
        << "=============================================================\n";
    {  // swap
        std::map<char, int> foo, bar;
        foo['x'] = 100;
        foo['y'] = 200;
        bar['a'] = 11;
        bar['b'] = 22;
        bar['c'] = 33;
        foo.swap(bar);
        std::cout << "foo contains:\n";
        for (std::map<char, int>::iterator it = foo.begin(); it != foo.end();
             ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "bar contains:\n";
        for (std::map<char, int>::iterator it = bar.begin(); it != bar.end();
             ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    std::cout
        << "=============================================================\n";
    {  // clear();
        std::map<char, int> mymap;
        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300;
        std::cout << "mymap contains:\n";
        for (std::map<char, int>::iterator it = mymap.begin();
             it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        mymap.clear();
        mymap['a'] = 1101;
        mymap['b'] = 2202;
        std::cout << "mymap contains:\n";
        for (std::map<char, int>::iterator it = mymap.begin();
             it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        //  mymap.my_tree._printing();
    }
    std::cout
        << "=============================================================\n";
    {  // key_comp
        std::map<char, int> mymap;

        std::map<char, int>::key_compare mycomp = mymap.key_comp();

        mymap['a'] = 100;
        mymap['b'] = 200;
        mymap['c'] = 300;

        std::cout << "mymap contains:\n";

        char highest = mymap.rbegin()->first;
        std::map<char, int>::iterator it = mymap.begin();
        do {
            std::cout << it->first << " => " << it->second << '\n';
        } while (mycomp((*it++).first, highest));
    }
    std::cout
        << "=============================================================\n";
    {  // value_comp
        std::map<char, int> mymap;
        mymap['x'] = 1001;
        mymap['y'] = 2002;
        mymap['z'] = 3003;
        std::cout << "mymap contains:\n";
        std::pair<char, int> highest = *mymap.rbegin();
        std::map<char, int>::iterator it = mymap.begin();
        do {
            std::cout << it->first << " => " << it->second << '\n';
        } while (mymap.value_comp()(*it++, highest));
    }
    std::cout
        << "=============================================================\n";
    {  // find
        std::map<char, int> mymap;
        std::map<char, int>::iterator it;
        mymap['a'] = 50;
        mymap['b'] = 100;
        mymap['c'] = 150;
        mymap['d'] = 200;
        it = mymap.find('b');
        if (it != mymap.end())
            mymap.erase(it);
        std::cout << "elements in mymap:" << '\n';
        std::cout << "a => " << mymap.find('a')->second << '\n';
        std::cout << "c => " << mymap.find('c')->second << '\n';
        std::cout << "d => " << mymap.find('d')->second << '\n';
    }
    {
        std::map<char, int> mymap;
        char c;

        mymap['a'] = 101;
        mymap['c'] = 202;
        mymap['f'] = 303;
        for (c = 'a'; c < 'h'; c++) {
            std::cout << c;
            if (mymap.count(c) > 0)
                std::cout << " is an element of mymap.\n";
            else
                std::cout << " is not an element of mymap.\n";
        }
    }
    std::cout
        << "=============================================================\n";
    {  // lower + upper
        std::map<char, int> mymap;
        std::map<char, int>::iterator itlow, itup;

        mymap['a'] = 20;
        mymap['b'] = 40;
        mymap['c'] = 60;
        mymap['d'] = 80;
        mymap['e'] = 100;

        itlow = mymap.lower_bound('b');
        itup = mymap.upper_bound('d');

        std::cout << itlow->first << "\n";
        std::cout << itup->first << "\n";
        mymap.erase(itlow, itup);
        // mymap.my_tree._printing();
        for (std::map<char, int>::iterator it = mymap.begin();
             it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    std::cout
        << "=============================================================\n";
    {
        std::map<char, int> mymap;

        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;

        std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator>
            ret;
        ret = mymap.equal_range('b');
        std::cout << "lower bound points to: ";
        std::cout << ret.first->first << " => " << ret.first->second << '\n';
        std::cout << "upper bound points to: ";
        std::cout << ret.second->first << " => " << ret.second->second << '\n';
    }
    std::cout
        << "=============================================================\n";
    // system("leaks a.out");
    return 0;
}
