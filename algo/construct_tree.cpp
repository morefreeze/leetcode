#ifndef CONSTRUCT_TREE_H

#define CONSTRUCT_TREE_H

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
        // ps: pre start
        // pe: pre end
        // is: inorder start
        // ie: inorder end
        TreeNode* buildTreeInplace(vector<int>& preorder, int ps, int pe,
                vector<int>& inorder, int is, int ie) {
            if (pe - ps != ie - is) return NULL;
            if (pe - ps <= 0) return NULL;
            int root(preorder[ps]);
            TreeNode *node = new TreeNode(root);
            int left;
            for (left = 0;is+left < ie && inorder[is+left] != root; ++left);
            node->left = buildTreeInplace(preorder, ps+1, ps+left+1,
                    inorder, is, is+left);
            node->right = buildTreeInplace(preorder, ps+left+1, pe,
                    inorder, is+left+1, ie);
            return node;
        }

        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            return buildTreeInplace(preorder, 0, SZ(preorder), inorder, 0, SZ(inorder));
        }
};

#endif /* end of include guard: CONSTRUCT_TREE_H */
