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
void postOrder(TreeNode *root){
    if (root == NULL) return;
    preOrder(root->left);
    preOrder(root->right);
    cout << root->val << " ";
}
void printTree(TreeNode *root){
    preOrder(root);
    cout << endl;
    midOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
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

