//
// Created by praveen balure on 09/08/18.
//

#ifndef TREE_AVL_TREE_H
#define TREE_AVL_TREE_H

#include "../tree.h"
#include "../resource_str.h"

class avl_tree  : public tree {
    avl_struct *create_node(int data);
    avl_struct * root;
public:
    void delete_t() override;
    bool find(int32_t data) override;
    int8_t insert(int32_t data) override;
    void in_order_traverse() override;
    void pre_order_traversal() override;
    void delete_n(int32_t data) override ;
    void bfs_traversal() override;

private:
    avl_struct * avl_insert(avl_struct *node, int data);
    avl_struct * find(avl_struct *node, int32_t data);
    avl_struct * right_rotation(avl_struct*);
    avl_struct * left_rotation(avl_struct *);
    void avl_preorder(avl_struct *);
    void avl_inorder(avl_struct *);
    avl_struct * avl_delete(avl_struct * node, int data);

};
#endif //TREE_AVL_TREE_H
