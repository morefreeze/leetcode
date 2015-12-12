#ifndef SKYLINE_H

#define SKYLINE_H

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

#define left(x) (((x)<<1)+1)
#define right(x) (((x)<<1)+2)
#define middle(l,r) (((l)+(r))/2)
#define father(x) (((x)-1)/2)
struct Node {
    //[l, r)
    int l,r,h;
};
class Solution {
    public:
        vector<Node> tree;
        void build_tree(int n) {
            tree = vector<Node>(n*4);
            init(0, n, 0);
        }
        void init(int l, int r, int idx) {
            if (l == r) return ;
            tree[idx].l = l;
            tree[idx].r = r;
            tree[idx].h = -1;
            if (l == r-1) {
                tree[idx].h = 0;
                return ;
            }
            int mid(middle(l, r));
            init(l, mid, left(idx));
            init(mid, r, right(idx));
        }
        void set(int l, int r, int idx, int h, int old_h) {
            if (idx < 0 || idx >= SZ(tree)) {
                return ;
            }
            if (l <= tree[idx].l && tree[idx].r <= r) {
                tree[idx].h = max(tree[idx].h, h);
                return ;
            }
            // out of range
            if (l >= tree[idx].r || r <= tree[idx].l) {
                tree[idx].h = max(tree[idx].h, old_h);
                return ;
            }
            int mid(middle(l, r));
            set(l, r, left(idx), h, max(tree[idx].h, old_h));
            set(l, r, right(idx), h, max(tree[idx].h, old_h));
            if (tree[idx].l == tree[idx].r-1) tree[idx].h = 0;
            else tree[idx].h = -1;
        }
        void find_ans(int idx, const VI &nums, vector<PII> &ans) {
            if (idx < 0 || idx >= SZ(tree)) {
                return ;
            }
            if (tree[idx].l == tree[idx].r) return ;
            if (tree[idx].h >= 0) {
                if (SZ(ans) == 0 || ans.rbegin()->second != tree[idx].h)
                    ans.PB(MP(nums[tree[idx].l], tree[idx].h));
                return ;
            }
            // is leaf
            if (tree[idx].l == tree[idx].r) return ;
            find_ans(left(idx), nums, ans);
            find_ans(right(idx), nums, ans);
        }
        vector<PII> getSkyline(VVI& buildings) {
            tree.clear();
            // discrete: convert x-axis to 0..n
            VI nums;
            map<int,int> m;
            REP (i, SZ(buildings)) {
                int l(buildings[i][0]);
                if (!EXIST(m, l)) {
                    m[l] = -2;
                    nums.PB(l);
                }
                int r(buildings[i][1]);
                if (!EXIST(m, r)) {
                    m[r] = -2;
                    nums.PB(r);
                }
            }
            SORT(nums);
            REP (i, SZ(nums)) {
                m[nums[i]] = i;
            }
            int n(SZ(m));
            debug(n);
            build_tree(n);
            sort(ALL(buildings), cmp);

            REP (i, SZ(buildings)) {
                int l(m[buildings[i][0]]);
                int r(m[buildings[i][1]]);
                int h(buildings[i][2]);
                set(l, r, 0, h, -1);
            }
            vector<PII> ans;
            find_ans(0, nums, ans);
            return ans;
        }
        // sort by h inc, l inc, r desc
        static bool cmp(const VI& lhs, const VI& rhs) {
            if (lhs[2] != rhs[2]) return lhs[2] < rhs[2];
            if (lhs[0] != rhs[0]) return lhs[0] < rhs[0];
            if (lhs[1] != rhs[1]) return lhs[1] > rhs[1];
            return false;
        }
};

#endif /* end of include guard: SKYLINE_H */
