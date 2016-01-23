#ifndef POPULATING_NEXT_RIGHT_POINTER2_H

#define POPULATING_NEXT_RIGHT_POINTER2_H

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
        TreeLinkNode *findLeft(TreeLinkNode *root, int depth) {
            if (root == NULL) return NULL;
            if (depth == 0) {
                if (root->left) return root->left;
                return root->right;
            }
            TreeLinkNode *ans(NULL);
            if (root->left) {
                ans = findLeft(root->left, depth-1);
                if (ans) return ans;
            }
            if (ans == NULL) {
                ans = findLeft(root->right, depth-1);
            }
            return ans;
        }
        TreeLinkNode *findRight(TreeLinkNode *root, int depth) {
            if (root == NULL) return NULL;
            if (depth == 0) {
                if (root->right) return root->right;
                return root->left;
            }
            TreeLinkNode *ans(NULL);
            if (root->right) {
                ans = findRight(root->right, depth-1);
                if (ans) return ans;
            }
            if (ans == NULL) {
                ans = findRight(root->left, depth-1);
            }
            return ans;
        }
        void link(TreeLinkNode *root) {
            if (root == NULL) return ;
            if (root->left != NULL) {
                root->left->next = root->right;
                link(root->left);
            }
            link(root->right);
            for (int depth = 0;;++depth) {
                TreeLinkNode *next_left(findRight(root->left, depth));
                if (next_left == NULL) return ;
                TreeLinkNode *next_right(findLeft(root->right, depth));
                if (next_right == NULL) return ;
                next_left->next = next_right;
            }
        }
        void connect(TreeLinkNode *root) {
            link(root);
        }
};

#endif /* end of include guard: POPULATING_NEXT_RIGHT_POINTER2_H */
