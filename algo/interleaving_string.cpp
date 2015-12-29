#ifndef INTERLEAVING_STRING_H

#define INTERLEAVING_STRING_H

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
        bool isInterleave(string a, string b, string s) {
            if (SZ(s) != SZ(a) + SZ(b)) return false;
            if (SZ(a) > SZ(b)) {
                swap(a,b);
            }
            bool f[2][SZ(a)+1];
            CLR(f);
            f[0][0] = true;
            FOR (i, 1, SZ(s)+1) {
                // s[i-1]
                FOR (j, 0, min(i,SZ(a))+1) {
                    // a[j-1]
                    // b[i-j]
                    f[i%2][j] = false;
                    if (j > 0) {
                        f[i%2][j] |= f[1-i%2][j-1] && (a[j-1] == s[i-1]);
                    }
                    f[i%2][j] |= f[1-i%2][j] && (b[i-j-1] == s[i-1]);
                }
            }
            return f[SZ(s)%2][SZ(a)];
        }
};

#endif /* end of include guard: INTERLEAVING_STRING_H */
