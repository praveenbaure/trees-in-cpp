//
// Created by praveen balure on 31/07/18.
//

/*
 * This file contains all the structure in the project
 */

#ifndef PRAC_CODE_RESOURCE_STR_H
#define PRAC_CODE_RESOURCE_STR_H

struct bst_struct {
    int data;
    bst_struct * left;
    bst_struct * right;
};

struct avl_struct{
    int data;
    avl_struct * left;
    avl_struct * right;
    unsigned int height;
};
#endif //PRAC_CODE_RESOURCE_STR_H
