#ifndef GAS_STATION_H

#define GAS_STATION_H

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
        int calc(const VI& a) {
            int ans(-1);
            VI s;
            int sum(0);
            int n(SZ(a));
            REP (i, n) {
                sum += a[i];
                s.PB(sum);
            }
            if (sum < 0) return -1;
            REP (k, n) {
                if (a[k] >= 0) {
                    if (ans == -1 || s[(k+n-1)%n] < s[(ans+n-1)%n]) {
                        ans = k;
                    }
                }
            }
            if (ans == -1) return -1;
            sum = 0;
            REP (i, n) {
                sum += a[(ans+i)%n];
                if (sum < 0) return -1;
            }
            return ans;
        }
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            // clockwise
            VI a;
            REP (i, SZ(gas)) {
                a.PB(gas[i] - cost[i]);
            }
            int ans;
            ans = calc(a);
            if (ans >= 0) return ans;
            // counterclockwise
            VI b;
            REP (i, SZ(gas)) {
                if (i == 0) b.PB(gas[i] - cost.back());
                else b.PB(gas[i] - cost[i-1]);
            }
            REP (i, SZ(b)) cout << b[i] << " ";
            cout << endl;
            return calc(b);
        }
};

#endif /* end of include guard: GAS_STATION_H */
