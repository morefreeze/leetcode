#include "tree_helper.h"

TreeNode* vector2Tree(vector<int> a){
    TreeNode *root(NULL);
    int n(a.size());
    if (n == 0) return root;
    vector<TreeNode*> tree(n);
    for (int i = 0;i < n;++i){
        if (a[i] == NULL_NODE) continue;
        if (i == 0){
            tree[0] = new TreeNode(a[i]);
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

// convert vector<int> to tree by leetcode style
// vector don't need complete binary tree
TreeNode* vector2TreeLT(vector<int> a) {
    int n(a.size());
    vector<TreeNode*> tree;
    for (int i = 0;i < n;++i) {
        if (a[i] == NULL_NODE) continue;
        tree.push_back(new TreeNode(a[i]));
    }
    if (tree.size() == 0) return NULL;
    int fa(0);
    int ch(1);
    int i(1);
    while (i < n) {
        if (a[i] != NULL_NODE) {
            tree[fa]->left = tree[ch];
            ++ch;
        }
        ++i;
        if (i >= n) {
            break;
        }
        if (a[i] != NULL_NODE) {
            tree[fa]->right = tree[ch];
            ++ch;
        }
        ++i;
        ++fa;
    }
    return tree[0];
}

int midOrder(TreeNode *root){
    if (root == NULL) return NULL_NODE;
    midOrder(root->left);
    cout << root->val << " ";
    midOrder(root->right);
    return root->val;
}
int preOrder(TreeNode *root){
    if (root == NULL) return NULL_NODE;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
    return root->val;
}
int postOrder(TreeNode *root){
    if (root == NULL) return NULL_NODE;
    preOrder(root->left);
    preOrder(root->right);
    cout << root->val << " ";
    return root->val;
}
void printTree(TreeNode *root){
    preOrder(root);
    cout << endl;
    midOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
}
bool checkBST(TreeNode *root) {
    if (root == NULL) return true;
    if (root->left != NULL && !(root->left->val < root->val)) return false;
    if (root->right != NULL && !(root->right->val > root->val)) return false;
    return checkBST(root->left) && checkBST(root->right);
}

TreeLinkNode* vector2TreeLink(const vector<int>& v){
    TreeLinkNode *root(NULL);
    int n(v.size());
    if (n == 0) return root;
    vector<TreeLinkNode*> tree(n);
    for (int i = 0;i < n;++i){
        if (v[i] == NULL_NODE) continue;
        if (i == 0){
            root = new TreeLinkNode(v[i]);
            tree[0] = root;
        }
        root = tree[i];
        if (i * 2 + 1 < n && v[i*2+1] != NULL_NODE){
            root->left = new TreeLinkNode(v[i*2+1]);
            tree[i*2+1] = root->left;
        }
        if (i * 2 + 2 < n && v[i*2+2] != NULL_NODE){
            root->right = new TreeLinkNode(v[i*2+2]);
            tree[i*2+2] = root->right;
        }
    }
    return tree[0];
}

void printTreeLink(TreeLinkNode *root){
    if (root == NULL){
        cout << "(empty tree)" << endl;
        return;
    }
    int depth(0);
    while (root){
        cout << "depth " << depth << endl;
        TreeLinkNode *cur(root);
        while (cur){
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
        root = root->left;
        ++depth;
    }
}

vector< vector<int> > dumpTreeLink(TreeLinkNode *root){
    vector< vector<int> > ans;
    while (root){
        vector<int> tmp;
        TreeLinkNode *cur(root);
        while (cur){
            tmp.push_back(cur->val);
            cur = cur->next;
        }
        root = root->left;
        ans.push_back(tmp);
    }
    return ans;
}

vector< vector<int> > makeTreeLinkAns(const vector<int>& v){
    vector< vector<int> > ans;
    int pow(1);
    for (int i = 0;i < int(v.size());++i){
        if (i == pow-1){
            vector<int> tmp;
            ans.push_back(tmp);
            pow <<= 1;
        }
        ans[int(ans.size())-1].push_back(v[i]);
    }
    return ans;
}

