#ifndef SCRAMBLE_STRING_H

#define SCRAMBLE_STRING_H

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
        int f[50][50][50];
        string sl, sr;
        bool isScramble(string s1, string s2) {
            CLR(f);
            sl = s1;
            sr = s2;
            return d(0, SZ(sl), 0, SZ(sr));
        }
        bool d(int l1, int len1, int l2, int len2) {
            //debug(l1); debug(len1); debug(l2); debug(len2);
            if (len1 != len2 || len1 <= 0) return false;
            int &ans = f[l1][len1][l2];
            if (ans) return ans == 1;
            if (sl.substr(l1, len1) == sr.substr(l2, len2))
                return ans = 1;
            FOR (i, 1, len1) {
                if (d(l1, i, l2, i) && d(l1+i, len1-i, l2+i, len2-i))
                    return ans = 1;
                if (d(l1, i, l2+len2-i, i) && d(l1+i, len1-i, l2, len2-i))
                    return ans = 1;
            }
            ans = 2;
            return false;
        }
};

#endif /* end of include guard: SCRAMBLE_STRING_H */
