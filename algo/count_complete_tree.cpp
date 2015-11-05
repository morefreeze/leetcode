#ifndef COUNT_COMPLETE_TREE_H

#define COUNT_COMPLETE_TREE_H

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
        bool trvelTree(TreeNode *root, int mask) {
            deque<int> q;
            while (mask > 1) {
                q.push_front(mask%2);
                mask >>= 1;
            }
            while (!q.empty() && root) {
                if (q.front() == 0) {
                    root = root->left;
                }
                else {
                    root = root->right;
                }
                q.pop_front();
            }
            return q.empty() && root;
        }
        // O(h^2), still TLE, why?
        int binarySearch(TreeNode* root) {
            if (NULL == root) return 0;
            TreeNode *most_left(root);
            int low(1);
            while (most_left->left) {
                low <<= 1;
                most_left = most_left->left;
            }

            TreeNode *most_right(root);
            int upp(1);
            while (most_right->right) {
                upp = upp * 2 + 1;
                most_right = most_right->right;
            }

            // leaves node are all same height
            if (low < upp) return upp;

            // otherwise, must upp+1 == low
            upp = upp * 2 + 1;
            int mid;
            do {
                mid = (low + upp + 1) / 2;
                if (trvelTree(root, mid)) {
                    low = mid;
                }
                else {
                    upp = mid - 1;
                }
            }while (low < upp);
            mid = (low+upp + 1) / 2;
            return mid;
        }
        int height(TreeNode *root) {
            return root == NULL ? -1 : 1+height(root->left);
        }
        int countNodes(TreeNode *root) {
            int h = height(root);
            return h < 0 ? 0 :
                height(root->right) == h-1 ? (1<<h) + countNodes(root->right)
                    : (1<<(h-1)) + countNodes(root->left);
        }
};

#endif /* end of include guard: COUNT_COMPLETE_TREE_H */
