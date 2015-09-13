#ifndef FRACTION_RECURRING_DECIMAL_H

#define FRACTION_RECURRING_DECIMAL_H

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

const int MAX_INT = 0x7fffffff;
class Solution {
    public:
        // return a*k/b, and remainder
        int product(int a, int b, int k, int *remainder){
            *remainder = 0;
            if (k == 0 || b == 0) return 0;
            // not overflow, so do the math directly
            if (a <= MAX_INT / k){
                *remainder = a*k % b;
                return a*k / b;
            }
            int ans(0);
            *remainder = -b;
            // try ans one by one prevent from overflow
            int i(0);
            while (i < k){
                // make more faster to reach k
                int diff(min(k-i, abs(b/a)+(b%a>0)));
                *remainder += diff * a;
                if (*remainder >= 0){
                    *remainder -= b;
                    ++ans;
                }
                i += diff;
            }
            // make sure remainder positive
            if (*remainder < 0){
                *remainder += b;
            }
            return ans;
        }
        string fractionToDecimal(int a, int b) {
            string ans;
            if (b == 0) return ans;
            if ((a<0 && b>0) || (a>0 && b<0)) ans += '-';
            a = abs(a);
            b = abs(b);
            if (a / b < 0){
                ans += toString(a / b).substr(1);
            }
            else{
                ans += toString(a / b);
            }
            // dig store all possible remainder position to find cycle section
            map<int, int> dig;
            string decimal;
            a %= b;
            if (a < 0) a = -a;
            int cnt(0);
            if (a % b){
                ans += '.';
                while (a % b){
                    dig[a] = cnt++;
                    int remainder;
                    int quo(product(a, b, 10, &remainder));
                    decimal += toString(quo);
                    a = remainder;
                    // find the cycle section
                    if (EXIST(dig, remainder)){
                        int idx(dig[remainder]);
                        decimal = decimal.substr(0, idx) + '(' + decimal.substr(idx) + ')';
                        break;
                    }
                }
                ans += decimal;
            }
            return ans;
        }
};

#endif /* end of include guard: FRACTION_RECURRING_DECIMAL_H */
