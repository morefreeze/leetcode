#ifndef WILDCARD_MATCH_H

#define WILDCARD_MATCH_H

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
        string _s, _p;
        bool dfs(int idx, int pat_idx){
            //cout << idx << " " << pat_idx << endl;
            if (idx == SZ(_s) && pat_idx == SZ(_p)) return true;
            char card(_p[pat_idx]);
            if (card == '?'){
                if (dfs(idx+1, pat_idx+1)){
                    return true;
                }
            }
            else if (card == '*'){
                // optimizate a****b to a*b
                if (pat_idx > 0 && _p[pat_idx-1] == '*'){
                    return (dfs(idx, pat_idx+1));
                }
                FOR (i, idx, SZ(_s)+1){
                    if (dfs(i, pat_idx+1)){
                        return true;
                    }
                }
            }
            // other normal character
            else{
                if (card == _s[idx] && dfs(idx+1, pat_idx+1)){
                    return true;
                }
            }
            return false;
        }
        bool dp(){
            int f[SZ(_s)+10][10];
            memset(f, 0, sizeof(f));
            f[0][0] = 1;
            REP (j, SZ(_p)){
                char card(_p[j]);
                REP (i, SZ(_s)+1){
                    f[i][(j+1)%2] = 0;
                }
                if (card == '*') f[0][(j+1)%2] = f[0][j%2];
                REP (i, SZ(_s)){
                    if (card == '?'){
                        f[i+1][(j+1)%2] = f[i+1][(j+1)%2] || (f[i][j%2]);
                    }
                    else if (card == '*'){
                        REP (k, i+2){
                            f[i+1][(j+1)%2] = f[i+1][(j+1)%2] || f[k][j%2];
                            if (f[i+1][(j+1)%2]) break;
                        }
                    }
                    else{
                        f[i+1][(j+1)%2] = f[i+1][(j+1)%2] || (f[i][j%2] && _s[i] == card);
                    }
                }
            }
            return f[SZ(_s)][SZ(_p)%2];
        }
    public:
        bool isMatch(string s, string p) {
            _s = s;
            _p = p;
            return dp();
            //return dfs(0, 0);
        }
};

#endif /* end of include guard: WILDCARD_MATCH_H */
