#ifndef REVERSE_WORD_STRING_H

#define REVERSE_WORD_STRING_H

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
        void trim(string &s){
            for (int i = SZ(s)-1; i > 0; --i) {
                if (s[i] == s[i-1] && s[i] == ' ') s.erase(i, 1);
            }
            while (SZ(s) > 0 && s[SZ(s)-1] == ' ') {
                s.erase(SZ(s)-1, 1);
            }
            while (SZ(s) > 0 && s[0] == ' ') {
                s.erase(0, 1);
            }
        }
        void swapChar(string &s, int st, int en) {
            --en;
            while (st < en){
                char tmp(s[st]);
                s[st] = s[en];
                s[en] = tmp;
                ++st;
                --en;
            }
        }
        void reverseWords(string &s) {
            trim(s);
            int n(SZ(s));
            swapChar(s, 0, n);
            int st(0);
            int en(0);
            for (; en < n;++en) {
                if (s[en] == ' ') {
                    swapChar(s, st, en);
                    st = en + 1;
                }
            }
            swapChar(s, st, en);
        }
};

#endif /* end of include guard: REVERSE_WORD_STRING_H */
