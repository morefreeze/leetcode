#ifndef DUNGEON_GAME_H

#define DUNGEON_GAME_H

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
#define ASZ(a) int(sizeof(a)/sizeof(a[0]))
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
    private:
        int n, m;
    public:
        bool check(const VVI& map, int goal){
            int r[n+1][m+1];
            CLR(r);
            REP (i, n+1) r[i][0] = -1;
            REP (j, m+1) r[0][j] = -1;
            r[0][1] = r[1][0] = goal;
            FOR (i, 1, n+1){
                FOR (j, 1, m+1){
                    r[i][j] = max(r[i-1][j], r[i][j-1]) + map[i-1][j-1];
                    if (r[i-1][j] < 0 && r[i][j-1] < 0) r[i][j] = -1;
                }
            }
            return r[n][m] >= 0;
        }
        int calculateMinimumHP(VVI& map) {
            srand(time(0));
            n = SZ(map);
            m = SZ(map[0]);
            int x(0), y(0);
            int upp(0), remain(map[0][0]);
            if (remain < 0){
                upp = -remain;
                remain = 0;
            }
            while (1){
                if (x == n-1 && y == m-1) break;
                //if (rand() % 2){
                if (1){
                    if (x + 1 >= n){
                        ++y;
                    }
                    else{
                        ++x;
                    }
                }
                else{
                    if (y + 1 >= m){
                        ++x;
                    }
                    else{
                        ++y;
                    }
                }
                remain += map[x][y];
                if (remain < 0){
                    upp -= remain;
                    remain = 0;
                }
            }
            int low(0);
            int mid;
            while (low < upp){
                mid = (low + upp) / 2;
                if (check(map, mid)){
                    upp = mid;
                }
                else{
                    low = mid + 1;
                }
            }
            mid = (low + upp) / 2;
            return 1 + mid;
        }
};

#endif /* end of include guard: DUNGEON_GAME_H */
