#ifndef N_QUEEN2_H

#define N_QUEEN2_H

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
    private:
        vector< vector<string> > ans;
        int N;
        int mask;
        vector <string> cur_ans;
    public:
        void dfs(int step, int lm, int mm, int rm){
            // lm(left mask) means the grids current row that can place queen
            // if queens attack left-bottom
            // mm(middle mask) means the grids if queens attack vertical
            // rm(right mask) is opposite against lm
            if (step == N){
                ans.PB(cur_ans);
                return ;
            }
            int cur_mask(lm & mm & rm);
            while (cur_mask){
                // 10010b & (10010b-1) == 10000b   -- next_mask
                // 10010b - 10000b = 10b   -- cur_q (pick the last 1)
                int next_mask(cur_mask & (cur_mask-1));
                int cur_q(cur_mask - next_mask);
                string cur_row(N, '.');
                REP (i, N){
                    if (cur_q & (1<<i)){
                        cur_row[i] = 'Q';
                        break;
                    }
                }
                cur_ans.PB(cur_row);
                // e.g.: cur_q == 001000b, lm = 110010b, the next lm will like this:
                //     110111 (~cur_q)
                // AND 110010
                //     110010
                // then all move left
                // 100101 last bit always is 1
                dfs(step+1, (((lm & ~cur_q)<<1) & mask) | 1, mm & ~cur_q, ((rm|(1<<N)) & ~cur_q)>>1);
                cur_ans.pop_back();
                cur_mask = next_mask;
            }
        }
        int totalNQueens(int n) {
            ans.clear();
            N = n;
            mask = (1<<n) - 1;
            dfs(0, mask, mask, mask);
            return SZ(ans);
        }
};

#endif /* end of include guard: N_QUEEN2_H */
