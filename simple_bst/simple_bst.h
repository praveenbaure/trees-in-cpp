//
// Created by praveen balure on 31/07/18.
//

#ifndef PRAC_CODE_SIMPLE_BINARY_TREE_H
#define PRAC_CODE_SIMPLE_BINARY_TREE_H


#include "../resource_str.h"
#include "../tree.h"

class simple_bst : public tree{
    bst_struct * root;
    bst_struct * create_node(int val);

public:
    simple_bst() : root(nullptr) {}
    virtual ~simple_bst();

public:
    void delete_t() override;
    bool find(int32_t data) override;
    int8_t insert(int32_t data) override;
    void in_order_traverse() override;
    void delete_n(int32_t data) override ;
    void bfs_traversal() override;
    void pre_order_traversal() override;
//    uint8_t post_order_traverse();
//    uint8_t per_order_traverse();

private:
    int8_t bst_insert(bst_struct * &,  int32_t val);
    bst_struct* bst_find(bst_struct* ,int32_t  val);
    void bst_delete(bst_struct *node);
    void bst_inorder(bst_struct *node);
    void bst_preorder(bst_struct *node);
    bst_struct * bst_find_parent(bst_struct *node, int32_t val);
    void swap_bst(bst_struct *node, bst_struct *parent_node);

};


#endif //PRAC_CODE_SIMPLE_BINARY_TREE_H
