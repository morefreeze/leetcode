#ifndef DECODE_WAYS_H

#define DECODE_WAYS_H

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
        int numDecodings(string s) {
            const int MAXN = 100;
            int n(SZ(s));
            if (n == 0) return 0;
            int f[n+1][3];
            CLR(f);
            REP (i, n) {
                if (s[i] != '0') {
                    f[i][1] = 1;
                }
            }
            REP (i, n-1) {
                f[i][2] = f[i][1] * f[i+1][1];
                if (s[i] == '1' || (s[i] == '2' && '0' <= s[i+1] && s[i+1] <= '6')) {
                    f[i][2] += 1;
                }
            }
            FOR (j, 3, n+1) {
                REP (i, n-j+1) {
                    if (s[i] == '0') continue;
                    f[i][j%3] = f[i+1][(j+2)%3];
                    if (s[i] == '1' || (s[i] == '2' && '0' <= s[i+1] && s[i+1] <= '6')) {
                        f[i][j%3] += f[i+2][(j+1)%3];
                    }
                }
            }
            return f[0][n%3];
        }
};

#endif /* end of include guard: DECODE_WAYS_H */
