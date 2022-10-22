#include "set/red_black_tree.hpp"
// start : for checker
#include <algorithm>
#include <random>
#include <set>
// end
int func() {
    return 1;
}
int main() {
    red_black_tree<int> x;
    // generating random numbers also {made by: jalalium}
    std::set<int> st;
    std::set<int> sit;
    srand(time(0));
    while (st.size() < 500)
        st.insert(rand() % 2147483647);
    std::vector<int> v(st.begin(), st.end());
    random_shuffle(v.begin(), v.end());
    //   std::cout << " numbers to insert : \n";
    // for (int z : v)
    //  	std::cout << z << " " ;
    // std::cout << std::endl;
    // int i = 0;
    for (int z : v) {
        x.add(z);
    }
    // std::vector<int> ss =
    // {77,76,43,27,8,85,55,63,18,91,57,90,34,25,50,12,88,35,60,84};
    // std::vector<int> rr =
    // {25,60,88,57,77,76,35,12,85,91,63,55,27,84,43,8,18,34,50,90}; for (int s
    // : ss) x.insert(s);
    // x.printing();
    // for (int c : rr)
    // x.remove(c);
    // x.insert(5);
    // x.insert(20);
    // x.insert(15);
    // x.insert(16);
    // x.insert(12);
    // x.insert(11);
    // x.insert(19);
    // x.insert(18);
    // x.insert(17);
    // x.insert(50);
    // x.insert(32);
    // x.insert(64);
    // x.insert(8);
    // x.insert(51);
    // x.insert(52);
    // x.insert(40);
    // x.insert(45);
    // x.insert(0);
    // x.insert(21);
    // x.insert(13);
    // x.insert(37);
    // x.printing();
    // i = 0;
    // for (int z : v)
    // {
    //   // if (i == 2)
    //   //   break;
    //   x.remove(z);
    //   // if (std::find(v.begin(), v.end(), z) != v.end())
    //   //   v.erase(std::find(v.begin(), v.end(), z));
    //   // i++;
    // }
    // i = 0;
    // for (int z : v)
    // {
    //   if (i == 1)
    //     break;
    //   x.insert(z);
    //   i++;
    // }
    // x.printing();
}
