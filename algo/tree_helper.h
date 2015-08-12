#ifndef TREE_HELPER_H

#define TREE_HELPER_H
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(){}
};

const int NULL_NODE = 0x80000000;
TreeNode* vector2Tree(vector<int> a);
void mid_order(TreeNode *root);
void pre_order(TreeNode *root);
void printTree(TreeNode *root);

#endif /* end of include guard: TREE_HELPER_H */
