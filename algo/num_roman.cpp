#ifndef NUM_ROMAN_H

#define NUM_ROMAN_H

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
        int romanToInt(string s) {
            map<char, int> d;
            d['I'] = 1;
            d['V'] = 5;
            d['X'] = 10;
            d['L'] = 50;
            d['C'] = 100;
            d['D'] = 500;
            d['M'] = 1000;
            // 1 to 9
            int ans(0);
            int i(0);
            int cur(0);
            while(i < SZ(s)){
                cur += d[s[i]];
                if (i+1 < SZ(s) && d[s[i+1]] > d[s[i]]){
                    ans += d[s[i+1]] - cur;
                    ++i;
                    cur = 0;
                }
                else if(i+1 < SZ(s) && d[s[i+1]] != d[s[i]]){
                    ans += cur;
                    cur = 0;
                }
                else{
                }
                ++i;
            }
            ans += cur;
            return ans;
        }
};

#endif /* end of include guard: NUM_ROMAN_H */
