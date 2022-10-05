#include "set/red_black_tree.hpp"

int main() {
    red_black_tree<int> rbt;

    rbt.add(1);
    rbt.add(2);
    rbt.add(3);
    rbt.add(5);
    rbt.add(9);
    rbt.add(5);
    rbt.add(4);
    // rbt.add(7);
    // rbt.add(6);
    // rbt.add(8);
    rbt.print();
}
