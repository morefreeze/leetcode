#ifndef MINIMUM_WINDOW_SUBSTRING_H

#define MINIMUM_WINDOW_SUBSTRING_H

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
        string minWindow(string s, string t) {
            int n(SZ(s));
            int m(SZ(t));
            if (n < m) return "";
            map<char, int> mt;
            map<char, int> ms;
            REP (i, SZ(t)) {
                mt[t[i]]++;
            }
            PII ansp;
            ansp.first = ansp.second = 0;
            int i(0);
            int j(0);
            int cnt(0);
            for (j = 0;j < n; ++j) {
                char c(s[j]);
                map<char,int>::iterator tit(mt.find(c));
                if (tit != mt.end()) {
                    ms[c]++;
                    if (ms[c] <= tit->second) ++cnt;
                }
                // try to move i
                while (cnt == m) {
                    if ((ansp.first == 0 && ansp.second == 0) || j-i < ansp.second-ansp.first) {
                        ansp.first = i;
                        ansp.second = j+1;
                    }
                    char dc(s[i]);
                    map<char,int>::iterator sit(ms.find(dc));
                    if (sit != ms.end()) {
                        sit->second--;
                        if (sit->second < mt[dc]) cnt--;
                    }
                    i++;
                }
            }
            return s.substr(ansp.first, ansp.second-ansp.first);
        }
};

#endif /* end of include guard: MINIMUM_WINDOW_SUBSTRING_H */
