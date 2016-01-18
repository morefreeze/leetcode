#ifndef COUNT_RANGE_SUM_H

#define COUNT_RANGE_SUM_H

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
        int mergeSort(vector<LL> &sum, int left, int right, int lower, int upper) {
            if (left > right) return 0;
            if (left == right) return int(lower <= sum[left] && sum[left] <= upper);
            int mid = (left+right) / 2, i,j,k;
            int res = mergeSort(sum, left, mid, lower, upper) + mergeSort(sum, mid+1, right, lower, upper);
            for (i=left, j=k=mid+1;i <= mid;++i) {
                while (j <= right && sum[j] - sum[i] < lower) ++j;
                while (k <= right && sum[k] - sum[i] <= upper) ++k;
                res += k - j;
            }
            vector<LL> tmp(right-left+1, 0);
            for (i=k=left, j=mid+1;k <= right;++k) {
                tmp[k-left] = ((i <= mid) && (j > right || sum[i] < sum[j])) ? sum[i++] : sum[j++];
            }
            for (k = left; k <= right;++k) {
                sum[k] = tmp[k-left];
            }
            return res;
        }
        // You can implement this with binary tree
        int countRangeSum(vector<int>& nums, int lower, int upper) {
            int n(SZ(nums));
            vector<LL> sum(n+1, 0);
            REP (i, n) sum[i+1] = sum[i] + nums[i];
            return mergeSort(sum, 1, n, lower, upper);
        }
};

class BSTSolution {
    struct BSTNode {
        LL val;
        BSTNode *left, *right;
        int cnt;
        int lCnt;
        BSTNode(LL x): val(x), left(NULL), right(NULL), cnt(1), lCnt(0) {}
    };
    public:
        void insert(BSTNode *&root, LL x) {
            if (NULL == root) root = new BSTNode(x);
            else if (root->val == x) {
                ++root->cnt;
            }
            else if (root->val < x) {
                insert(root->right, x);
            }
            // if (root->val > x)
            else {
                insert(root->left, x);
                ++root->lCnt;
            }
        }
        int getBound(BSTNode *root, LL x, bool includeSelf) {
            if (NULL == root) return 0;
            if (root->val == x) {
                return root->lCnt + (includeSelf ? root->cnt : 0);
            }
            else if (root->val < x) {
                return root->lCnt + root->cnt + getBound(root->right, x, includeSelf);
            }
            // if (root->val > x)
            else {
                return getBound(root->left, x, includeSelf);
            }
        }
        int countRangeSum(vector<int>& nums, int lower, int upper) {
            BSTNode *root = new BSTNode(0);
            LL sum(0);
            int ans(0);
            REP (i, SZ(nums)) {
                sum += nums[i];
                int left = getBound(root, sum-lower, true);
                int right = getBound(root, sum-upper, false);
                ans += left - right;
                insert(root, sum);
            }
            return ans;
        }
};

class MSSolution {
    public:
        // You can implement this with binary tree
        int countRangeSum(vector<int>& nums, int lower, int upper) {
            multiset<LL> pSum;
            LL sum(0);
            pSum.insert(sum);
            int ans(0);
            REP (i, SZ(nums)) {
                sum += nums[i];
                ans += distance(pSum.lower_bound(sum-upper), pSum.upper_bound(sum-lower));
                pSum.insert(sum);
            }
            return ans;
        }
};

#endif /* end of include guard: COUNT_RANGE_SUM_H */
