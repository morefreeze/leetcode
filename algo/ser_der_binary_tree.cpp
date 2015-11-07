#ifndef SER_DER_BINARY_TREE_H

#define SER_DER_BINARY_TREE_H

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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (NULL == root) return "( null )";
        return "( " + serialize(root->left) + " " + toString(root->val) + " " + serialize(root->right) + " )";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root(NULL);
        //if (data[0] != '(') {
            //if (data == "null") return NULL;
            //root = new TreeNode(toInt(data));
            //return root;
        //}
        // find left tree
        int left_dep(0);
        int i;
        int n(SZ(data));
        for (i = 0; i < n; ++i) {
            if (data[i] == '(') {
                ++left_dep;
            }
            else if (data[i] == ')') {
                --left_dep;
                if (left_dep == 1) {
                    root = new TreeNode(0);
                    root->left = deserialize(data.substr(2, i));
                    break;
                }
            }
        }
        // only one element, must NULL?
        if (i == n) return NULL;
        // jump space
        i += 2;
        root->val = toInt(data.substr(i));
        // jump another space
        for (; i < n && data[i] != ' '; ++i) ;
        i += 1;
        root->right = deserialize(data.substr(i, n-i-2));
        return root;
    }
};

#endif /* end of include guard: SER_DER_BINARY_TREE_H */
