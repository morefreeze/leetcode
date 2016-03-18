#ifndef LONGEST_INCREASING_PATH_H

#define LONGEST_INCREASING_PATH_H

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
    int x,y, num;
    node(int x, int y, int num): x(x), y(y), num(num) {}
    bool operator<(const node& rhs) const {
        if (num != rhs.num) return num < rhs.num;
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
};
class Solution {
    public:
        int longestIncreasingPath(VVI& matrix) {
            int n(SZ(matrix));
            if (n == 0) return 0;
            int m(SZ(matrix[0]));
            vector<node> st;
            REP (i, n) {
                REP (j, m) {
                    st.PB(node(i,j, matrix[i][j]));
                }
            }
            SORT(st);
            vector< vector<bool> > vi(n);
            vector< vector<int> > f(n);
            REP (i, n) {
                vi[i] = vector<bool>(m, false);
                f[i] = vector<int>(m, 0);
            }
            int ans(1);
            const int dx[4] = {-1, 0, 0, 1};
            const int dy[4] = {0, -1, 1, 0};
            REP (i, SZ(st)) {
                int &cur = f[st[i].x][st[i].y];
                cur = 1;
                REP (k, 4) {
                    int x = st[i].x + dx[k];
                    int y = st[i].y + dy[k];
                    if (!(0 <= x && x < n && 0 <= y && y < m)) continue;
                    if (matrix[x][y] < st[i].num && f[x][y] >= cur) {
                        cur = f[x][y] + 1;
                        ans = max(ans, cur);
                    }
                }
            }
            return ans;
        }
};

#endif /* end of include guard: LONGEST_INCREASING_PATH_H */
