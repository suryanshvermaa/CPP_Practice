#include<iostream>

#ifndef TREENODE_H
#define TREENODE_H

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

#endif