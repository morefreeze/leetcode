#ifndef STOCK4_H

#define STOCK4_H

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
        int maxProfit(int k, vector<int>& prices) {
            int n(SZ(prices));
            if (n <= 1 || k <= 0) return 0;
            if (k >= n/2) {
                int ans(0);
                FOR (i, 1, n) {
                    if (prices[i] > prices[i-1]) ans += prices[i] - prices[i-1];
                }
                return ans;
            }
            int f[n][k+1];
            CLR(f);
            // f[i][j] = max(f[i-1][j], prices[i] + f[ii][j-1]-prices[ii]), ii<i
            FOR (j, 1, k+1) {
                int localMax(f[0][j-1] - prices[0]);
                FOR (i, 1, n) {
                    f[i][j] = max(f[i-1][j], prices[i] + localMax);
                    localMax = max(localMax, f[i][j-1] - prices[i]);
                }
            }
            return f[n-1][k];
        }
};

#endif /* end of include guard: STOCK4_H */
