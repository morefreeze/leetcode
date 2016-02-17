#ifndef UNIQUE_BINARY_TREE2_H

#define UNIQUE_BINARY_TREE2_H

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
    private:
        vector<TreeNode*> makeTree(VI &arr) {
            vector<TreeNode*> ans;
            int n(SZ(arr));
            if (n == 0) {
                ans.PB(NULL);
                return ans;
            }
            REP (i, n) {
                VI larr = VI(arr.begin(), arr.begin()+i);
                vector<TreeNode*> left = makeTree(larr);
                VI rarr = VI(arr.begin()+i+1, arr.end());
                vector<TreeNode*> right = makeTree(rarr);
                for (auto lit : left) {
                    for (auto rit : right) {
                        TreeNode *root = new TreeNode(arr[i]);
                        root->left = lit;
                        root->right = rit;
                        ans.PB(root);
                    }
                }
            }
            return ans;
        }
    public:
        vector<TreeNode*> generateTrees(int n) {
            vector<TreeNode*> ans;
            if (n == 0) return ans;
            VI arr;
            FOR (i, 1, n+1) arr.PB(i);
            return makeTree(arr);
        }
};

#endif /* end of include guard: UNIQUE_BINARY_TREE2_H */
