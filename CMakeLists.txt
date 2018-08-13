cmake_minimum_required(VERSION 3.1)
project(tree)

set(CMAKE_CXX_STANDARD 14)
set(AVL_TREE
        ${PROJECT_SOURCE_DIR}/avl_tree/avl_tree.cpp
        ${PROJECT_SOURCE_DIR}/avl_tree/avl_tree.h
        )
set(INCLUDE_FILES
        ${PROJECT_SOURCE_DIR}/tree.h
        ${PROJECT_SOURCE_DIR}/resource_str.h
)
set(SIMPLE_BST
        ${PROJECT_SOURCE_DIR}/simple_bst/simple_bst.cpp
        ${PROJECT_SOURCE_DIR}/simple_bst/simple_bst.h
        )
add_library(avl_tree SHARED ${AVL_TREE} ${INCLUDE_FILES})
add_library(binary_tree SHARED ${SIMPLE_BST} ${INCLUDE_FILES})
add_executable(tree main.cpp ${INCLUDE_FILES})
target_link_libraries(tree binary_tree avl_tree)

