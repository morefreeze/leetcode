#ifndef EXPRESSION_ADD_OPERATORS_H

#define EXPRESSION_ADD_OPERATORS_H

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
        int target;
        int slen;
        string s;
        vector<string> addOperators(string oriNum, int t) {
            target = t;
            s = oriNum;
            slen = SZ(s);
            VS ans;
            if (slen == 0) return ans;
            int lmax = (s[0] == '0' ? 1 : slen);
            long long cur(0);
            string buf(2*slen+1, '0');
            REP (i, lmax) {
                cur = cur * 10 + s[i] - '0';
                buf[i] = s[i];
                dfs(0, cur, i+1, buf, i+1, ans);
            }
            return ans;
        }
        void dfs(long long sum, long long prev, int pos, string &buf, int bufpos, VS &ans) {
            int lmax = (s[pos] == '0' ? pos+1 : slen);
            if (pos == slen) {
                if (sum + prev == target) {
                    ans.PB(buf.substr(0, bufpos));
                }
                return ;
            }
            long long cur(0);
            REP (i, lmax-pos) {
                cur = cur * 10 + s[i+pos] - '0';
                buf[bufpos+i+1] = s[i+pos];

                buf[bufpos] = '+';
                dfs(sum+prev, cur, pos+i+1, buf, bufpos+i+2, ans);

                buf[bufpos] = '-';
                dfs(sum+prev, -cur, pos+i+1, buf, bufpos+i+2, ans);

                buf[bufpos] = '*';
                dfs(sum, cur*prev, pos+i+1, buf, bufpos+i+2, ans);
            }
        }
};

#endif /* end of include guard: EXPRESSION_ADD_OPERATORS_H */
