#ifndef COURSE_SCHEDULE2_H

#define COURSE_SCHEDULE2_H

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
        vector<int> findOrder(int n, vector<pair<int, int> >& p) {
            if (n <= 0) return VI();
            VI ans;
            VVI g(n);
            REP (i, SZ(p)) {
                g[p[i].first].PB(p[i].second);
            }
            bool vi[n];
            CLR(vi);
            REP (i, n) {
                bool found(false);
                REP (cur, n) {
                    if (!vi[cur] && SZ(g[cur]) == 0) {
                        REP (j, n) {
                            if (!vi[j] && SZ(g[j]) > 0) {
                                for (int k = SZ(g[j])-1; k >= 0; --k) {
                                    if (g[j][k] == cur) {
                                        g[j].erase(g[j].begin()+k);
                                    }
                                }
                            }
                        }
                        ans.PB(cur);
                        vi[cur] = 1;
                        found = true;
                        break;
                    }
                }
                if (!found) return VI();
            }
            return ans;
        }
};

#endif /* end of include guard: COURSE_SCHEDULE2_H */
