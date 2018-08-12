//
// Created by praveen balure on 09/08/18.
//

#include <iostream>
#include <cmath>
#include "avl_tree.h"
#include "../tree.h"

unsigned int max(unsigned int a, unsigned int b){
    return (a > b? a : b);
}
unsigned int get_height(avl_struct * node){
    if(nullptr == node)
        return 0;
    return node->height;
}

unsigned int get_height_diff(avl_struct* node){
    return std::fabs(get_height(node->left)  - get_height(node->right));
}
avl_struct* avl_tree::create_node(int data) {
    auto * node = new avl_struct();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

int8_t avl_tree::insert(int32_t data) {
    root = avl_insert(root,data);
    return 1;
}

avl_struct * avl_tree::avl_insert(avl_struct *node, int data) {
    if (nullptr == node) {
        node = create_node(data);
        return node;
    }
    if(data > node->data)
        node->right =  avl_insert(node->right,data);
    else if(data < node->data)
        node->left = avl_insert(node->left,data);
    else
        std::cout << "Node is  already present in tree" << std::endl;

    //this will work because our tree is balanced from start and there will be
    //only difference of 1 before any insertion and we are updating of height
    // of child node before updating height of parent node.
    node->height = max(node->left->height, node->right->height) + 1;

    /*
     * check if that node inbalance
     */
    if(1 < get_height(node)){
        /*
         * Now check if data inserted is less then right
         */
    }
}
