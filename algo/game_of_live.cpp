#ifndef GAME_OF_LIVE_H

#define GAME_OF_LIVE_H

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
        void gameOfLife(VVI& b) {
            int dx[] = {-1,-1,-1,0,0,1,1,1};
            int dy[] = {-1,0,1,-1,1,-1,0,1};
            int n(SZ(b));
            if (n == 0) return ;
            int m(SZ(b[0]));
            REP (i, n) {
                REP (j, m) {
                    int cnt(0);
                    REP (k, 8) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        cnt += (0 <= x && x < n && 0 <= y && y < m && (b[x][y] & 1) == 1);
                    }
                    //cout << i << " " << j << " " << b[i][j] << " " << cnt << endl;
                    if ((b[i][j] == 1 && 2 <= cnt && cnt <= 3)
                            || (b[i][j] == 0 && cnt == 3)) {
                        b[i][j] |= 2;
                    }
                    //debug(b[i][j]);
                }
            }
            REP (i, n)
                REP (j, m)
                    b[i][j] >>= 1;
        }
};

#endif /* end of include guard: GAME_OF_LIVE_H */
