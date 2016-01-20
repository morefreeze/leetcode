#ifndef DISTINCT_SUBSEQUENCES_H

#define DISTINCT_SUBSEQUENCES_H

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
        int numDistinct(string s, string t) {
            int n(SZ(s));
            int m(SZ(t));
            if (n == 0 || m == 0) return 0;
            int f[n+1][m+1];
            CLR(f);
            REP (i, n+1) f[i][0] = 1;
            REP (j, m) {
                FOR (i, j, n) {
                    f[i+1][j+1] = f[i][j+1] + f[i][j] * (s[i] == t[j]);
                }
            }
            return f[n][m];
        }
};

class Solution2 {
    public:
        int numDistinct(string s, string t) {
            int n(SZ(s));
            int m(SZ(t));
            if (n == 0 || m == 0) return 0;
            VI pos[128];
            for (int i = m-1; i >= 0; --i)
                pos[t[i]].PB(i+1);
            VI match(n+1, 0);
            match[0] = 1;
            REP (i, n) {
                REP (j, SZ(pos[s[i]])) {
                    int u = pos[s[i]][j];
                    match[u] += match[u-1];
                }
            }
            return match[m];
        }
};
#endif /* end of include guard: DISTINCT_SUBSEQUENCES_H */
