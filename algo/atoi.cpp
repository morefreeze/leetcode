#ifndef ATOI_H

#define ATOI_H

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
#include <climits>

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
        int gt(string lhs, string rhs){
            if (SZ(lhs) != SZ(rhs))
                return SZ(lhs) > SZ(rhs);
            return lhs > rhs;
        }
        int myAtoi(string str) {
            int i(0);
            while(i < SZ(str) && str[i] == ' '){
                ++i;
            }
            cout << "i " << i << endl;
            int sign(1);
            if (i < SZ(str) && (str[i] == '-' || str[i] == '+')){
                if (str[i] == '-')
                    sign *= -1;
                ++i;
            }
            int ans(0);
            string s;
            for(;i < SZ(str) && '0' <= str[i] && str[i] <= '9';++i){
                s += str[i];
                cout << s << endl;
                // overflow
                if (sign == 1 && gt(s, "2147483647")){
                    return INT_MAX;
                }
                if (sign == -1 && gt(s, "2147483648")){
                    return INT_MIN;
                }
                ans = ans * 10 + (str[i]-'0');
            }
            // don't care -2147483648
            return ans*sign;
        }
};

#endif /* end of include guard: ATOI_H */
