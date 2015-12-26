#ifndef CANDY_H

#define CANDY_H

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
        int candy(vector<int>& r) {
            int n(SZ(r));
            int ans(n);
            int lastHigh(1);
            int highLen(1);
            int lowLen(0);
            FOR (i, 1, n) {
                if (i == n-1 || r[i] > r[i-1]) {
                    if (r[i] < r[i-1]) lowLen++;
                    if (lowLen > 0) {
                        ans += (lowLen-1) * lowLen / 2;
                        if (highLen <= lowLen) ans += lowLen - highLen + 1;
                        highLen = 1;
                        lowLen = 0;
                    }
                    if (r[i] > r[i-1]) {
                        lastHigh = r[i];
                        ans += highLen;
                        highLen++;
                    }
                }
                else if (r[i] < r[i-1]){
                    lowLen++;
                }
                // r[i] == r[i-1]
                else {
                    if (lowLen > 0) {
                        ans += (lowLen-1) * lowLen / 2;
                        if (highLen <= lowLen) ans += lowLen - highLen + 1;
                        highLen = 1;
                        lowLen = 0;
                    }
                    highLen = 1;
                    lowLen = 0;
                }
                //cout << i << " " << r[i] << " " << highLen << " " << lowLen << endl;
                //debug(ans);
            }
            return ans;
        }
};

#endif /* end of include guard: CANDY_H */
