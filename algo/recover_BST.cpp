#ifndef RECOVER_BST_H

#define RECOVER_BST_H

#include "tree_helper.h"
#include <unordered_set>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define ASZ(a) (a),(a)+int(sizeof(a)/sizeof(a[0]))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

class Solution {
    public:
        int last;
        TreeNode *lastNode;
        TreeNode *first;
        TreeNode *second;
        void recoverTree(TreeNode* root) {
            lastNode = first = second = NULL;
            inorder(root);
            if (first && second) {
                int tmp = first->val;
                first->val = second->val;
                second->val = tmp;
            }
            else {
                cerr << "not found" << endl;
            }
        }
        void inorder(TreeNode *root) {
            if (root == NULL) return ;
            inorder(root->left);
            if (lastNode) {
                // find first reverse order
                if (first == NULL && root->val < lastNode->val) {
                    first = lastNode;
                }
                // meanwhile, root is second when first > root, but there may be more
                // take the last
                if (first && root->val < lastNode->val) {
                    second = root;
                }
            }
            lastNode = root;
            inorder(root->right);
        }
};

#endif /* end of include guard: RECOVER_BST_H */
