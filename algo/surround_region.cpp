#ifndef SURROUND_REGION_H

#define SURROUND_REGION_H

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
        void solve(vector<vector<char> >& b) {
            const int dx[] = {-1, 0, 0, 1};
            const int dy[] = {0, -1, 1, 0};
            int n(SZ(b));
            if (n == 0) return ;
            int m(SZ(b[0]));
            deque<PII> Q;
            bool vi[n][m];
            CLR(vi);
            REP (i, n){
                REP(j, m){
                    if (i != 0 && i != n-1 && j != 0 && j != m-1) continue;
                    if (b[i][j] != 'O' || vi[i][j]) continue;
                    vi[i][j] = 1;
                    Q.PB(MP(i,j));
                    bool surr(false);
                    while (!Q.empty()){
                        PII cur(Q.front());
                        Q.pop_front();
                        REP (k, sizeof(dx)/sizeof(int)){
                            PII t(MP(cur.first+dx[k], cur.second+dy[k]));
                            if (0 <= t.first && t.first < n
                                    && 0 <= t.second && t.second < m
                                    && !vi[t.first][t.second]
                                    && b[t.first][t.second] == 'O'){
                                Q.PB(t);
                                vi[t.first][t.second] = 1;
                            }
                        }
                    }
                }
            }
            REP (i, n){
                REP (j, m){
                    if (!vi[i][j])
                        b[i][j] = 'X';
                }
            }
        }
};

#endif /* end of include guard: SURROUND_REGION_H */
