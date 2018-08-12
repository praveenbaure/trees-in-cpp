#include <cstdio>
#include <iostream>
#include "./simple_bst/simple_bst.h"

int main()
{
    simple_bst bt;

    bt.insert(6);
    bt.insert(2);
    bt.insert(11);
    bt.insert(1);
    bt.insert(5);
    bt.insert(4);
    bt.insert(7);
    bt.insert(3);
    bt.insert(10);
    bt.insert(8);
    bt.insert(9);

    bt.bfs_traversal();
    std::cout << "\n";
    bt.in_order_traverse();
    std::cout << "\n";
    bt.delete_n(1);
    bt.bfs_traversal();
    std::cout << "\n";
    bt.in_order_traverse();

    return 0;
} // The bst_struct is destroyed here