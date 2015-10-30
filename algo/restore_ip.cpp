#ifndef RESTORE_IP_H

#define RESTORE_IP_H

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
        vector<string> ans;
        string cur;
    public:
        bool check(const string &s) {
            if (SZ(s) > 3 || SZ(s) <= 0) return false;
            if (SZ(s) > 1 && s[0] == '0') return false;
            int x(0);
            REP (i, SZ(s)) {
                if (!('0' <= s[i] && s[i] <= '9')) return false;
                x = x * 10 + s[i] - '0';
            }
            return 0 <= x && x <= 255;
        }
        void dfsIp(const string &s, int idx, int depth) {
            if (depth == 4) {
                if (idx == SZ(s)) {
                    ans.PB(cur.substr(0, SZ(cur)-1));
                }
                return ;
            }
            FOR (i, 1, min(SZ(s)-idx, 3)+1) {
                string item(s.substr(idx, i));
                if (check(item)) {
                    cur += item + ".";
                    dfsIp(s, idx+i, depth+1);
                    cur = cur.substr(0, SZ(cur)-SZ(item)-1);
                }
                else {
                    break;
                }
            }
        }
        vector<string> restoreIpAddresses(string s) {
            ans.clear();
            cur = "";
            dfsIp(s, 0, 0);
            return ans;
        }
};

#endif /* end of include guard: RESTORE_IP_H */
