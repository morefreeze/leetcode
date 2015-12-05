#ifndef RSQ_MUTABLE_H

#define RSQ_MUTABLE_H

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

class NumArray {
public:
    struct node {
        int st;
        int len;
        int sum;
        node *left, *right;
    };
    node *root;
    void build_tree(node *cur, const VI &nums, int st, int len) {
        cur->st = st;
        cur->len = len;
        if (len <= 1) {
            cur->left = NULL;
            cur->right = NULL;
            if (len == 1) cur->sum = nums[st];
            return ;
        }
        cur->left = new node();
        cur->right = new node();
        build_tree(cur->left, nums, st, len/2);
        build_tree(cur->right, nums, st+len/2, len-len/2);
        cur->sum = cur->left->sum + cur->right->sum;
    }
    NumArray(vector<int> &nums) {
        root = new node();
        build_tree(root, nums, 0, SZ(nums));
    }

    int update_tree(node *cur, int idx, int val) {
        if (cur == NULL || idx < cur->st || idx >= cur->st+cur->len) return 0;
        if (cur->len == 1) {
            int tmp(val - cur->sum);
            cur->sum += val - cur->sum;
            return tmp;
        }
        int delta = update_tree(cur->left, idx, val) + update_tree(cur->right, idx, val);
        cur->sum += delta;
        return delta;
    }
    void update(int i, int val) {
        update_tree(root, i, val);
    }

    int sum_tree(node *cur, int i, int j) {
        if (cur == NULL || cur->st > j || cur->st+cur->len-1 < i) return 0;
        if (i <= cur->st && cur->st+cur->len-1 <= j) return cur->sum;
        return sum_tree(cur->left, i, j) + sum_tree(cur->right, i, j);
    }
    int sumRange(int i, int j) {
        return sum_tree(root, i, j);
    }
};

#endif /* end of include guard: RSQ_MUTABLE_H */
