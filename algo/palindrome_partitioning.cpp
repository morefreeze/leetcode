#ifndef PALINDROME_PARTITIONING_H

#define PALINDROME_PARTITIONING_H

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
        vector<VS> partition(string s) {
            vector<VS> ans;
            VS tmp;
            dfs(s, 0, tmp, ans);
            return ans;
        }
        bool isPalindrome(const string &s) {
            int l(0), r(SZ(s));
            for (;l < r && s[l] == s[r]; ++l, --r);
            return l >= r;
        }
        void dfs(const string &s, int idx, VS &tmp, vector<VS> &ans) {
            if (idx == SZ(s)) {
                ans.PB(tmp);
                return ;
            }
            FOR (i, idx, SZ(s)) {
                int l(idx), r(i);
                for (;l < r && s[l] == s[r]; ++l, --r);
                if (l >= r) {
                    tmp.PB(s.substr(idx, i-idx+1));
                    dfs(s, i+1, tmp, ans);
                    tmp.pop_back();
                }
            }
        }
};

#endif /* end of include guard: PALINDROME_PARTITIONING_H */
