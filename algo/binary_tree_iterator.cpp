#ifndef BINARY_TREE_ITERATOR_H

#define BINARY_TREE_ITERATOR_H

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

struct IterNode{
    TreeNode* nd;
    // 0 for left, 1 for this, 2 for right, 3 for popup
    int idx;
    IterNode(TreeNode *nd, int idx):nd(nd), idx(idx){}
};
class BSTIterator {
    private:
        stack<IterNode> his;
    public:
        int calc_idx(TreeNode *root, int ori_idx = 0){
            if (root == NULL) return -1;
            if (ori_idx == 0){
                if (root->left != NULL){
                    return 0;
                }
                else return 1;
            }
            else if (ori_idx == 1){
                return 1;
            }
            else if (ori_idx == 2){
                if (root->right != NULL){
                    return 2;
                }
            }
            return 3;
        }
        BSTIterator(TreeNode *root = NULL) {
            if (root == NULL) return ;
            his.push(IterNode(root, 0));
        }

        /** @return whether we have a next smallest number */
        bool hasNext() {
            while (!his.empty()){
                IterNode &t = his.top();
                int idx = calc_idx(t.nd, t.idx);
                t.idx = idx;
                //cout << idx << " " << t.nd->val << endl;
                if (idx == 0){
                    his.push(IterNode(t.nd->left, calc_idx(t.nd->left)));
                }
                else if (idx == 1){
                    return true;
                }
                else if (idx == 2){
                    his.push(IterNode(t.nd->right, calc_idx(t.nd->right)));
                }
                else if (idx == 3){
                    his.pop();
                    if (his.empty()) return false;
                    IterNode &tmp = his.top();
                    tmp.idx++;
                }
            }
            return !(his.empty());
        }

        /** @return the next smallest number */
        int next() {
            if (his.empty()) return -1;
            IterNode &t = his.top();
            t.idx++;
            return t.nd->val;
        }
};


#endif /* end of include guard: BINARY_TREE_ITERATOR_H */
