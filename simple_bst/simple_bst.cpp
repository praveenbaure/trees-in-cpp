//
// Created by praveen balure on 31/07/18.
//

#include <cstdio>
#include <queue>
#include "simple_bst.h"


simple_bst::~simple_bst() {
    if(nullptr != root)
        delete root;
}

bst_struct* simple_bst::create_node(int val) {
    auto * res = new bst_struct();
    res->data = val;
    res->left = nullptr;
    res->right = nullptr;
    return res;
}

/*
 * find
 */
bool simple_bst::find(int32_t data) {
    return bst_find(root, data) != nullptr;
}

bst_struct* simple_bst::bst_find(bst_struct *node, int32_t val) {
    if(nullptr == node)
        return nullptr;
    if(val == node->data)
        return node;
    if(val < node->data)
        return bst_find(node->left,val);
    if(val > node->data)
        return bst_find(node->right,val);
    return nullptr;
}

bst_struct * simple_bst::bst_find_parent(bst_struct *node,
                                         int32_t val) {
    if(nullptr == node)
        return nullptr;
    if(nullptr != node->right && val == node->right->data){
        return node;
    }
    if(nullptr != node->left && val == node->left->data){
        return node;
    }
    if(val < node->data)
        return bst_find_parent(node->left,val);
    else if(val > node->data)
        return bst_find_parent(node->right,val);
    return nullptr;
}

/*
 * Insert
 */
int8_t simple_bst::insert(int32_t data) {
    //start traversing the  tree
    if(nullptr == root)
        root = create_node(data);
    if(nullptr == root)
        return -1;
    return bst_insert(root,data);
}
int8_t simple_bst::bst_insert(bst_struct *  &  cur , int32_t val) {
    int8_t ret;
    if(nullptr == cur)
        cur = create_node(val);
    if(nullptr == cur)
        return -1;
    if(val < cur->data)
        ret = bst_insert(cur->left,val);
    else if (val > cur->data)
        ret = bst_insert(cur->right, val);
    else
        return 0; //No action performed
    return ret;
}

/*
 * delete tree
 */
void simple_bst::delete_t() {
    bst_delete(root);
}

void simple_bst::bst_delete(bst_struct *node) {
    if(nullptr == node)
        return;
    bst_delete(node->left);
    bst_delete(node->right);
    delete node;
}

void simple_bst::delete_n(int32_t data) {
    bst_struct * node ;
    // root need to be deleted in case root is the node
    node = bst_find_parent(root, data);
    if(data == root->data)
        swap_bst(root, nullptr);
    else if((nullptr != node->left) && (data == node->left->data))
        swap_bst(node->left, node);
    else
        swap_bst(node->right,node);
}

void simple_bst::swap_bst(bst_struct *node, bst_struct *parent_node) {
    bst_struct* temp , *  temp_parent;
    if(nullptr == node->left && nullptr == node->right) {
        if(node == parent_node->left)
            parent_node->left = nullptr;
        else
            parent_node->right = nullptr;
        delete node;
        return;
    }
    temp_parent =  node;
    if(nullptr != node->left) {
        //find largest left  node if there is any left sub tree
        temp = node->left;
        while(nullptr != temp->right){
            temp_parent = temp;
            temp = temp->right;
        }
        node->data = temp->data;
    }else{
        //find smallest right node
        temp = node->right;
        while(nullptr != temp->left){
            temp_parent = temp;
            temp = temp->left;
        }
        node->data = temp->data;
    }
    swap_bst(temp, temp_parent);
}


/*
 * tree traversal
 */
//inorder traversal

void simple_bst::in_order_traverse() {
    return bst_inorder(root);
}

void simple_bst::bst_inorder(bst_struct *node) {
    if(nullptr == node)
        return;
    bst_inorder(node->left);
    printf("%d\t",node->data);
    bst_inorder(node->right);
}

//breadth first traversal
void simple_bst::bfs_traversal() {
    std::queue<bst_struct * > fifoq;
    bst_struct * node;
    fifoq.push(root);
    while(!fifoq.empty()) {
        node = fifoq.front();
        if (nullptr == node) {
            fifoq.push(nullptr);
            continue;
        }else{
            printf("%d\t",node->data);
        }
        if(node->left)
            fifoq.push(node->left);
        if(node->right)
            fifoq.push(node->right);
        fifoq.pop();
    }
}