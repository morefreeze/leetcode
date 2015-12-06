#ifndef CONSTRUCT_TREE_POSTORDER_H

#define CONSTRUCT_TREE_POSTORDER_H

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
        // is: inorder start
        // ie: inorder end
        // ps: post start
        // pe: post end
        TreeNode* buildTreeInplace(VI &inorder, int is, int ie,
                VI &postorder, int ps, int pe) {
            if (pe - ps != ie - is) return NULL;
            if (pe - ps <= 0) return NULL;
            if (pe - ps == 1 && inorder[is] != postorder[ps]) {
                cerr << "invalid tree" << endl;
                return NULL;
            }
            int root(postorder[pe-1]);
            TreeNode *node = new TreeNode(root);
            int left;
            for (left = 0;is+left < ie && inorder[is+left] != root; ++left);
            node->left = buildTreeInplace(inorder, is, is+left, postorder, ps, ps+left);
            node->right = buildTreeInplace(inorder, is+left+1, ie, postorder, ps+left, pe-1);
            return node;
        }
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            return buildTreeInplace(inorder, 0, SZ(inorder), postorder, 0, SZ(postorder));
        }
};

#endif /* end of include guard: CONSTRUCT_TREE_POSTORDER_H */
