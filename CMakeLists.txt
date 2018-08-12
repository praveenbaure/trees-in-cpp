cmake_minimum_required(VERSION 3.10)
project(tree)

set(CMAKE_CXX_STANDARD 17)
set(AVL_TREE
        avl_tree/avl_tree.cpp avl_tree/avl_tree.h)
set(INCLUDE_FILES
        ${PROJECT_SOURCE_DIR}/tree.h
        ${PROJECT_SOURCE_DIR}/resource_str.h
)
set(SIMPLE_BST
        ${PROJECT_SOURCE_DIR}/simple_bst/simple_bst.cpp
        ${PROJECT_SOURCE_DIR}/simple_bst/simple_bst.h
        )
add_library(avl_tree SHARED ${AVL_TREE} ${INCLUDE_FILES} avl_tree/avl_tree.cpp avl_tree/avl_tree.h)
add_library(binary_tree SHARED ${SIMPLE_BST} ${INCLUDE_FILES})
add_executable(tree main.cpp ${INCLUDE_FILES})
target_link_libraries(tree binary_tree)

