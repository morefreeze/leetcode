#ifndef BINARY_TREE_ZIGZAG_H

#define BINARY_TREE_ZIGZAG_H

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

struct node {
    TreeNode *t;
    int depth;
    node(TreeNode *v, int d): t(v), depth(d) {}
};
class Solution {
    public:
        VVI zigzagLevelOrder(TreeNode* root) {
            VVI ans;
            if (NULL == root) return ans;
            deque<node*> q;
            q.PB(new node(root, 0));
            int last_depth(-1);
            while (!q.empty()) {
                node *cur(q.front());
                q.pop_front();
                if (cur->depth != last_depth) {
                    VI tmp;
                    ans.PB(tmp);
                    last_depth = cur->depth;
                }
                ans[last_depth].PB(cur->t->val);
                if (cur->t->left) q.PB(new node(cur->t->left, cur->depth+1));
                if (cur->t->right) q.PB(new node(cur->t->right, cur->depth+1));
            }
            for (int i = 1;i < SZ(ans);i += 2) {
                reverse(ALL(ans[i]));
            }
            return ans;
        }
};

#endif /* end of include guard: BINARY_TREE_ZIGZAG_H */
