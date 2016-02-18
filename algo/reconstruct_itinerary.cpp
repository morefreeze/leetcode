#ifndef RECONSTRUCT_ITINERARY_H

#define RECONSTRUCT_ITINERARY_H

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
        vector<string> findItinerary(vector<pair<string, string> > a) {
            // airport
            VS ap;
            // d[airport] = lexical_index
            map<string, int> d;
            REP (i, SZ(a)) {
                if (!EXIST(d, a[i].first)) ap.PB(a[i].first);
                d[a[i].first] = -1;
                if (!EXIST(d, a[i].second)) ap.PB(a[i].second);
                d[a[i].second] = -1;
            }
            int n(SZ(d));
            SORT(ap);
            REP (i, SZ(ap)) {
                d[ ap[i] ] = i;
            }
            VVI b(n);
            REP (i, SZ(a)) {
                int from = d[ a[i].first ];
                int to = d[ a[i].second ];
                b[from].PB(to);
            }
            REP (i, n) {
                SORT(b[i]);
            }
            VI path;
            map<PII, int> vi;
            REP (i, SZ(a)) vi[MP(d[a[i].first], d[a[i].second])]++;
            dfs(d["JFK"], b, vi, SZ(a), path);
            VS ans;
            REP (i, SZ(path))
                ans.PB(ap[ path[i] ]);
            return ans;
        }

        bool dfs(int last, VVI &b, map<PII, int> &vi, int cnt, VI &path) {
            path.PB(last);
            if (cnt == 0) {
                return true;
            }
            REP (i, SZ(b[last])) {
                int to = b[last][i];
                PII ft = MP(last, to);
                if (vi[ft] == 0) continue;
                vi[ft]--;
                if (dfs(to, b, vi, cnt-1, path)) return true;
                vi[ft]++;
            }
            path.pop_back();
            return false;
        }
};

#endif /* end of include guard: RECONSTRUCT_ITINERARY_H */
