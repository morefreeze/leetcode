#include "tree_helper.h"

TreeNode* vector2Tree(vector<int> a){
    TreeNode *root(NULL);
    int n(a.size());
    if (n == 0) return root;
    vector<TreeNode*> tree(n);
    for (int i = 0;i < n;++i){
        if (a[i] == NULL_NODE) continue;
        if (i == 0){
            root = new TreeNode(a[i]);
            tree[0] = root;
        }
        root = tree[i];
        if (i * 2 + 1 < n && a[i*2+1] != NULL_NODE){
            root->left = new TreeNode(a[i*2+1]);
            tree[i*2+1] = root->left;
        }
        if (i * 2 + 2 < n && a[i*2+2] != NULL_NODE){
            root->right = new TreeNode(a[i*2+2]);
            tree[i*2+2] = root->right;
        }
    }
    return tree[0];
}

void midOrder(TreeNode *root){
    if (root == NULL) return;
    midOrder(root->left);
    cout << root->val << " ";
    midOrder(root->right);
}
void preOrder(TreeNode *root){
    if (root == NULL) return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void printTree(TreeNode *root){
    midOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
}

