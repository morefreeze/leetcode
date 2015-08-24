#ifndef LCA_BT_H

#define LCA_BT_H

#include "tree_helper.h"
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
		map<TreeNode*, int> d;
		bool dfs(TreeNode* root, TreeNode* p){
			if (!root) return false;
			if (root == p){
				d[p] = 1;
				return true;
			}
			if (dfs(root->left, p) || dfs(root->right, p)){
				d[root] = 1;
				return true;
			}
			return false;
		}
		vector<TreeNode*> v;
		bool dfsCheck(TreeNode* root, TreeNode* q){
			if (!root) return false;
			if (root == q){
				v.PB(root);
				return true;
			}
			if (dfsCheck(root->left, q) || dfsCheck(root->right, q)){
				v.PB(root);
				return true;
			}
			return false;
		}
                TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			dfs(root, p);
			dfsCheck(root, q);
			for (vector<TreeNode*>::iterator iter = v.begin();iter != v.end();++iter){
				if (d.find(*iter) != d.end()) return *iter;
			}
			return NULL;
                }
};

#endif /* end of include guard: LCA_BT_H */
