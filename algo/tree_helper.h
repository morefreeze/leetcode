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
};

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

const int NULL_NODE = 0x80000000;
TreeNode* vector2Tree(vector<int> a);
void mid_order(TreeNode *root);
void pre_order(TreeNode *root);
void printTree(TreeNode *root);

TreeLinkNode* vector2TreeLink(const vector<int>& v);
void printTreeLink(TreeLinkNode *root);
vector< vector<int> > dumpTreeLink(TreeLinkNode *root);
vector< vector<int> > makeTreeLinkAns(const vector<int>& v);

#endif /* end of include guard: TREE_HELPER_H */
