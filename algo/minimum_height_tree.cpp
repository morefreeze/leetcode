#ifndef MINIMUM_HEIGHT_TREE_H

#define MINIMUM_HEIGHT_TREE_H

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

// d0 cur node longest path
// d1 cur node second longest path without longest path
// ret[cur] = max(d0[cur], go up through father longest path)
class Solution {
    public:
        vector<int> findMinHeightTrees(int n, vector<PII>& edges) {
            VVI a(n);
            REP (i, SZ(edges)) {
                a[edges[i].first].PB(edges[i].second);
                a[edges[i].second].PB(edges[i].first);
            }
            VI d0(n), d1(n);
            calc_d(-1, 0, d0, d1, a);
            VI ret(n);
            dfs(-1, 0, 0, d0, d1, a, ret);
            int min_len(n);
            REP (i, n) {
                min_len = min(min_len, ret[i]);
            }
            VI ans;
            REP (i, n) {
                if (min_len == ret[i]) ans.PB(i);
            }
            return ans;
        }
        void dfs(int fa, int cur, int fa_up_path, const VI &d0, const VI &d1, const VVI &a, VI &ret) {
            // go up through father node which longest path
            int up_path;
            if (fa == -1) up_path = 0;
            else if (d0[cur]+1 == d0[fa]) {
                up_path = max(fa_up_path, d1[fa]) + 1;
            }
            // <=
            else {
                up_path = max(fa_up_path, d0[fa]) + 1;
            }
            ret[cur] = max(d0[cur], up_path);
            REP (i, SZ(a[cur])) {
                if (a[cur][i] == fa) continue;
                dfs(cur, a[cur][i], up_path, d0, d1, a, ret);
            }
        }
        int calc_d(int fa, int cur, VI &d0, VI &d1, const VVI &a) {
            int l0(0), l1(0);
            REP (i, SZ(a[cur])) {
                if (a[cur][i] == fa) continue;
                int l(calc_d(cur, a[cur][i], d0, d1, a) + 1);
                if (l > l0) {
                    l1 = l0;
                    l0 = l;
                }
                else if (l > l1) {
                    l1 = l;
                }
            }
            d0[cur] = l0;
            d1[cur] = l1;
            return l0;
        }
};

// find diameter, then find center
// slower than Solution
class Solution2 {
    public:
        vector<int> findMinHeightTrees(int n, vector<PII>& edges) {
            VVI a(n);
            REP (i, SZ(edges)) {
                a[edges[i].first].PB(edges[i].second);
                a[edges[i].second].PB(edges[i].first);
            }
            VI ret(n);
            VI fa(n);
            VI p;
            int diameter(find_diameter(a, ret, fa, p));
            VI ans;
            int cur(p[1]);
            REP (i, diameter/2) {
                cur = fa[cur];
            }
            ans.PB(cur);
            if (diameter%2 == 1) {
                ans.PB(fa[cur]);
            }
            return ans;
        }
        // find diameter
        // ret length from one point
        // fa father of path
        // p contain two endpoint
        // return diameter length
        int find_diameter(const VVI &a, VI &ret, VI &fa, VI &p) {
            int diameter;
            // pick random point to start, so we pick 0, use random can't speed up
            int point(find_longest(0, a, ret, fa, diameter));
            int point2(find_longest(point, a, ret, fa, diameter));
            p.PB(point);
            p.PB(point2);
            return diameter;
        }
        // bfs find longest point
        int find_longest(int start, const VVI &a, VI &ret, VI &fa, int &diameter) {
            deque<int> q;
            q.PB(start);
            unordered_set<int> v;
            v.insert(start);
            ret[start] = 0;
            while (!q.empty()) {
                int cur(q.front());
                REP (i, SZ(a[cur])) {
                    if (!EXIST(v, a[cur][i])) {
                        v.insert(a[cur][i]);
                        q.PB(a[cur][i]);
                        ret[a[cur][i]] = ret[cur] + 1;
                        fa[a[cur][i]] = cur;
                    }
                }
                // the last one of queue
                if (SZ(q) == 1) {
                    diameter = ret[q.front()];
                    return q.front();
                }
                q.pop_front();
            }
            return start;
        }
};

// cut every leaf, again and again, until left one or two node
class CutSolution {
    public:
        vector<int> findMinHeightTrees(int n, vector<PII>& edges) {
            if (n == 1) {
                VI ans;
                ans.PB(0);
                return ans;
            }
            vector<unordered_set<int> > a(n);
            REP (i, SZ(edges)) {
                a[edges[i].first].insert(edges[i].second);
                a[edges[i].second].insert(edges[i].first);
            }
            VI ans1, ans2;
            VI *p1(&ans1), *p2(&ans2);
            REP (i, SZ(a)) {
                if (SZ(a[i]) == 1) p1->PB(i);
            }
            while (1) {
                for (auto i: *p1) {
                    for (auto cur : a[i]) {
                        a[ cur ].erase(i);
                        if (SZ(a[ cur ]) == 1) p2->PB(cur);
                    }
                }
                if (p2->empty()) return *p1;
                p1->clear();
                swap(p1, p2);
            }
        }
};

// TLE
class BruteForceSolution {
    public:
        vector<int> findMinHeightTrees(int n, vector<PII>& edges) {
            VI ans;
            int min_len(n);
            if (n <= 0) return ans;
            if (n == 2) {
                ans.PB(0);
                ans.PB(1);
                return ans;
            }
            VI cnt(n);
            VVI a(n);
            REP (i, SZ(edges)) {
                cnt[edges[i].first]++;
                cnt[edges[i].second]++;
                a[edges[i].first].PB(edges[i].second);
                a[edges[i].second].PB(edges[i].first);
            }
            REP (i, n) {
                if (cnt[i] == 0) return ans;
                if (cnt[i] == 1) continue;
                map<int,bool> vi;
                vi[i] = true;
                int len(0);
                dfs(i, 0, vi, a, len);
                if (len <= min_len) {
                    if (len < min_len) ans.clear();
                    min_len = len;
                    ans.PB(i);
                }
            }
            return ans;
        }
        void dfs(int cur, int depth, map<int,bool> &vi, VVI &a, int &len) {
            len = max(len, depth);
            REP (i, SZ(a[cur])) {
                if (!EXIST(vi, a[cur][i])) {
                    vi[ a[cur][i] ] = true;
                    dfs(a[cur][i], depth+1, vi, a, len);
                    vi[ a[cur][i] ] = false;
                }
            }
        }
};

#endif /* end of include guard: MINIMUM_HEIGHT_TREE_H */
