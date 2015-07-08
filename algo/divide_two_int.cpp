#ifndef DIVIDE_TWO_INT_H

#define DIVIDE_TWO_INT_H

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
        int divide(int a, int b) {
            const int MAX_INT(2147483647);
            const int MIN_INT(-2147483648);
            if (a == 0) return 0;
            if (b == 0) return MAX_INT;
            if (b == MIN_INT){
                if (a == MIN_INT) return 1;
                return 0;
            }
            int pow[100];
            int two[100];
            bool sign(false);
            if ((a < 0 && b > 0)
            || (a > 0 && b < 0)){
                sign = true;
                b = -b;
            }
            // convert a,b to <0 those range is bigger
            if (a > 0){
                a = -a;
                b = -b;
            }
            int ans(0);
            if (a > b) return 0;
            int t(b+b);
            int cnt(0);
            pow[0] = b;
            two[0] = 1;
            // not overflow
            while(t < 0 && t >= a){
                ++cnt;
                pow[cnt] = t;
                two[cnt] = two[cnt-1] + two[cnt-1];
                //cout << t << " " << cnt << endl;
                if (MIN_INT - t > t) break;
                t += t;
            }
            while(a){
                while(cnt >= 0 && a > pow[cnt]) --cnt;
                if (a <= pow[cnt]){
                    a -= pow[cnt];
                    ans += two[cnt];
                }
                else{
                    break;
                }
            }
            if (sign){
                if (ans == MIN_INT){
                    return ans;
                }
                return -ans;
            }
            if (ans == MIN_INT) return MAX_INT;
            return ans;
        }
};

#endif /* end of include guard: DIVIDE_TWO_INT_H */
