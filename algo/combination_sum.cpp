#ifndef COMBINATION_SUM_H

#define COMBINATION_SUM_H

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
    vector<VI> ans;
    public:
        void dfs(VI& unq, VI sol, int idx, int target){
            if (target == 0){
                // reverse vector
                REP (i, SZ(sol)/2){
                    swap(sol[i], sol[SZ(sol)-i-1]);
                }
                ans.PB(sol);
                return ;
            }
            if (target < 0){
                return ;
            }
            FOR (i, idx, SZ(unq)){
                sol.PB(unq[i]);
                dfs(unq, sol, i, target-unq[i]);
                sol.pop_back();
            }
        }
        vector<VI> combinationSum(vector<int>& candidates, int target) {
            VI unq;
            sort(ALL(candidates));
            for (int i = SZ(candidates)-1; i>0; --i){
                if (candidates[i] != candidates[i-1]){
                    unq.PB(candidates[i]);
                }
            }
            VI sol;
            unq.PB(candidates[0]);
            dfs(unq, sol, 0, target);
            return ans;
        }
};

#endif /* end of include guard: COMBINATION_SUM_H */
