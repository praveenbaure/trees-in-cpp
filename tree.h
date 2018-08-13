//
// Created by praveen balure on 01/08/18.
//

#ifndef PRAC_CODE_TREE_H
#define PRAC_CODE_TREE_H

#include <cstdint>

class tree {
private:
    virtual int8_t insert(int32_t data) = 0;
    virtual bool find(int32_t  data) = 0;
    virtual void in_order_traverse() = 0;
    virtual void pre_order_traversal() = 0;
    virtual void delete_t() = 0;
    virtual void delete_n(int32_t data) = 0;
    virtual void bfs_traversal() = 0;
};
#endif //PRAC_CODE_TREE_H
