//
// Created by praveen balure on 09/08/18.
//

#include <iostream>
#include <cmath>
#include <queue>
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

int get_height_diff(avl_struct* node){
    return get_height(node->left)  - get_height(node->right);
}
avl_struct* avl_tree::create_node(int data) {
    auto * node = new avl_struct();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

bool avl_tree::find(int32_t data) {
    return nullptr != find(root, data);
}

avl_struct * avl_tree::find(avl_struct *node, int32_t data) {
    if(nullptr ==  node){
        return nullptr;
    }
    if(data == node->data){
        return node;
    }
    if(data < node->data)
        return find(node->left, data);
    else
        return find(node->right, data);
}
int8_t avl_tree::insert(int32_t data) {
    root = avl_insert(root, data);
    return 1;
}

avl_struct* avl_tree::left_rotation(avl_struct * node) {
    avl_struct * right_node = node->right;
    avl_struct * temp = right_node->left;

    right_node->left = node;
    node->right = temp;
    node->height = max(get_height(node->left), get_height(node->right)) + 1;
    right_node->height = max(get_height(right_node->left), get_height(right_node->right)) + 1;
    return right_node;
}

avl_struct* avl_tree::right_rotation(avl_struct * node) {
    avl_struct * left_node = node->left;
    avl_struct * temp = left_node->right;

    left_node->right = node;
    node->left = temp;
    node->height = max(get_height(node->left), get_height(node->right)) + 1;
    left_node->height =  max(get_height(left_node->left), get_height(left_node->right)) + 1;
    return left_node;
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
         printf("Node is  already present in tree\n");

    //this will work because our tree is balanced from start and there will be
    //only difference of 1 before any insertion and we are updating the height
    // of child node before updating height of parent node.
    node->height = max(get_height(node->left), get_height(node->right)) + 1;
    /*
     * check if that node inbalance
     */
    if(1 < get_height_diff(node)){ //tree is left unbalance
        /*
         * Now check if data inserted is less then right
         * To check if node is leftRight unbalance and if it
         * then left rotate its right child to make tree
         * leftLeft unbalence at node
         */
        if(data > node->left->data){
            node->left = left_rotation(node->left);
        }
        return right_rotation(node);
    } else if(-1 > get_height_diff(node)){ //tree is right unbalance
        /*
         * Now check if data inserted is  greater than left->data
         * To check if node is rightLeft unbalance and if it is
         * Then rotate its left child right and make tree rightRight
         * unbalance at node
         */
        if(data < node->right->data)
            node->right = right_rotation(node->right);
        return left_rotation(node);
    } else
    return node;
}

/*
 * delete node and tree
 */
void avl_tree::delete_n(int32_t data) {
    if(nullptr == root)
        return;
    avl_delete(root, data);
}
avl_struct* avl_tree::avl_delete(avl_struct *node, int data) {
    /*
     * first delete normal delete on bst
     */
    avl_struct * temp = node;
    if(nullptr == node)
        return node;
    if(data < node->data)
        node->left = avl_delete(node->left, data);
    else if(data > node->data)
        node->right = avl_delete(node->right, data);
    else if(data == node->data){
        //both left and right child are null
        if(nullptr == node->right && nullptr == node->left) {
            delete node;
            temp = nullptr;
        }
        //if left of node is null
        else  if(nullptr == node->left){
            temp = node->right;
            delete node;
        }
        //if right is null
        else if(nullptr == node->right){
            temp = node->left;
            delete node;
        } else {
            //left and right are not null
            temp = node->right;
            while (nullptr != temp->left)
                temp = temp->left;
            node->data = temp->data;
            node->right = avl_delete(node->right, temp->data);
            temp = node;
        }
    }
    return temp;
}

void avl_tree::delete_t() {

}

/*
 * Tree traversals
 */
void avl_tree::pre_order_traversal() {
    return avl_preorder(root);
}

void avl_tree::avl_preorder(avl_struct * node) {
    if(!node)
        return;
    printf("%d\t", node->data);
    avl_preorder(node->left);
    avl_preorder(node->right);
}

//in order
void avl_tree::in_order_traverse() {
    avl_inorder(root);
}

void avl_tree::avl_inorder(avl_struct *node) {
    if(!node)
        return;
    avl_inorder(node->left);
    printf("%d\t", node->data);
    avl_inorder(node->right);
}


//bsf traversal
void avl_tree::bfs_traversal() {
    std::queue<avl_struct *> fifo_queue;
    avl_struct *temp;
    fifo_queue.push(root);
    fifo_queue.push(nullptr);
    while(!fifo_queue.empty()){
        temp = fifo_queue.front();
        fifo_queue.pop();
        if(nullptr == temp)
            fifo_queue.push(nullptr);
        else{
            printf("%d\t",temp->data);
            if(nullptr == temp->left)
                fifo_queue.push(temp->left);
            if(nullptr == temp->right)
                fifo_queue.push(temp->right);
        }
    }
}