#ifndef REMOVE_PARENTHESES_H

#define REMOVE_PARENTHESES_H

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
        vector<string> removeInvalidParentheses(string s) {
            VS ans;
            char par[] = {'(', ')'};
            dfs(s, 0, 0, par, ans);
            return ans;
        }
        void dfs(string s, int last_i, int last_j, char par[], VS &ans) {
            int st = 0;
            FOR (i, last_i, SZ(s)) {
                if (s[i] == par[0]) ++st;
                if (s[i] == par[1]) --st;
                if (st < 0) {
                    FOR (j, last_j, i+1) {
                        if (s[j] == par[1] && (j == last_j || s[j-1] != par[1])) {
                            dfs(s.substr(0, j) + s.substr(j+1), i, j, par, ans);
                        }
                    }
                    return ;
                }
            }
            // all ans will be add in reversed mode
            // 1. order string will reverse but parentheses must be matched;
            // 2. reversed string will be calcuted.
            reverse(ALL(s));
            if (par[0] == '(') {
                char r_par[] = {')', '('};
                dfs(s, 0, 0, r_par, ans);
            }
            else {
                ans.PB(s);
            }
        }
};

#endif /* end of include guard: REMOVE_PARENTHESES_H */
